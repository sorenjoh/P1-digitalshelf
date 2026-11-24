#include "user_database.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

static const char usersPath[] = "users.json";
static const char tempPath[] = "users.json.tmp";

static int nextToken(FILE *file){
    int c;
    do {
        c = fgetc(file);
    } while(c == ' ' || c == '\t' || c == '\r' || c == '\n');
    return c;
}

static int readHexCode(FILE *file, unsigned *code){
    *code = 0;
    for(int i = 0; i < 4; i++){
        int c = fgetc(file);
        const char *digits = "0123456789abcdefABCDEF";
        const char *digit = c > 0 ? strchr(digits, c) : NULL;
        if(!digit){
            return 0;
        }
        unsigned n = (unsigned)(digit - digits);
        *code = *code * 16 + (n >= 16 ? n - 6 : n);
    }
    return 1;
}

static size_t encodeUtf8(unsigned code, unsigned char bytes[4]){
    if(code <= 0x7F){
        bytes[0] = (unsigned char)code;
        return 1;
    }
    if(code <= 0x7FF){
        bytes[0] = (unsigned char)(0xC0 | (code >> 6));
        bytes[1] = (unsigned char)(0x80 | (code & 0x3F));
        return 2;
    }
    if(code <= 0xFFFF){
        bytes[0] = (unsigned char)(0xE0 | (code >> 12));
        bytes[1] = (unsigned char)(0x80 | ((code >> 6) & 0x3F));
        bytes[2] = (unsigned char)(0x80 | (code & 0x3F));
        return 3;
    }
    bytes[0] = (unsigned char)(0xF0 | (code >> 18));
    bytes[1] = (unsigned char)(0x80 | ((code >> 12) & 0x3F));
    bytes[2] = (unsigned char)(0x80 | ((code >> 6) & 0x3F));
    bytes[3] = (unsigned char)(0x80 | (code & 0x3F));
    return 4;
}

/* Read a JSON string after its opening quote. */
static int readString(FILE *file, char *value, size_t capacity){
    size_t length = 0;
    int c;
    while((c = fgetc(file)) != '"'){
        if(c < 0x20){
            return 0;
        }

        unsigned char bytes[4] = {(unsigned char)c};
        size_t size = 1;
        if(c == '\\'){
            const char escapes[] = "\"\\/bfnrt";
            const char decoded[] = "\"\\/\b\f\n\r\t";
            c = fgetc(file);
            if(c == 'u'){
                unsigned code;
                if(!readHexCode(file, &code) || code == 0){
                    return 0;
                }
                if(code >= 0xD800 && code <= 0xDBFF){
                    unsigned low;
                    if(fgetc(file) != '\\' || fgetc(file) != 'u' ||
                       !readHexCode(file, &low) || low < 0xDC00 || low > 0xDFFF){
                        return 0;
                    }
                    code = 0x10000 + ((code - 0xD800) << 10) + (low - 0xDC00);
                }else if(code >= 0xDC00 && code <= 0xDFFF){
                    return 0;
                }
                size = encodeUtf8(code, bytes);
            }else{
                const char *escape = c > 0 ? strchr(escapes, c) : NULL;
                if(!escape){
                    return 0;
                }
                bytes[0] = (unsigned char)decoded[escape - escapes];
            }
        }

        if(value){
            if(length + size >= capacity){
                return 0;
            }
            memcpy(value + length, bytes, size);
            length += size;
        }
    }
    if(value){
        value[length] = '\0';
    }
    return 1;
}

static int readUser(FILE *file, char user[7][100]){
    int hasUsername = 0;
    int token = nextToken(file);
    while(token == '"'){
        char key[32];
        if(!readString(file, key, sizeof key) || nextToken(file) != ':'){
            return 0;
        }

        token = nextToken(file);
        if(strcmp(key, "username") == 0){
            if(hasUsername || token != '"' || !readString(file, user[0], sizeof user[0])){
                return 0;
            }
            hasUsername = 1;
        }else{
            int slot = strcmp(key, "genres") == 0 ? 1 : strcmp(key, "actors") == 0 ? 4 : 0;
            if(token != '['){
                return 0;
            }
            token = nextToken(file);
            for(int i = 0; token == '"'; i++){
                if(!readString(file, slot && i < 3 ? user[slot + i] : NULL, sizeof user[0])){
                    return 0;
                }
                token = nextToken(file);
                if(token != ','){
                    break;
                }
                token = nextToken(file);
                if(token != '"'){
                    return 0;
                }
            }
            if(token != ']'){
                return 0;
            }
        }

        token = nextToken(file);
        if(token == '}'){
            return hasUsername;
        }
        if(token != ','){
            return 0;
        }
        token = nextToken(file);
    }
    return 0;
}

/* Return the number of accounts and optionally locate the final array bracket. */
static int readUsers(FILE *file, char users[MAX_USERS][7][100], long *arrayEnd){
    char key[16];
    if(nextToken(file) != '{' || nextToken(file) != '"' ||
       !readString(file, key, sizeof key) || strcmp(key, "users") != 0 ||
       nextToken(file) != ':' || nextToken(file) != '['){
        return -1;
    }

    int count = 0;
    int token = nextToken(file);
    while(token == '{'){
        if(count == MAX_USERS || !readUser(file, users[count])){
            return -1;
        }
        count++;
        token = nextToken(file);
        if(token != ','){
            break;
        }
        token = nextToken(file);
        if(token != '{'){
            return -1;
        }
    }
    if(token != ']'){
        return -1;
    }
    if(arrayEnd){
        *arrayEnd = ftell(file) - 1;
        if(*arrayEnd < 0){
            return -1;
        }
    }
    return nextToken(file) == '}' && nextToken(file) == EOF && !ferror(file) ? count : -1;
}

int LoadUsers(char users[MAX_USERS][7][100]){
    memset(users, 0, MAX_USERS * sizeof users[0]);
    FILE *file = fopen(usersPath, "rb");
    if(!file){
        return errno == ENOENT ? 0 : -1;
    }
    int count = readUsers(file, users, NULL);
    fclose(file);
    return count;
}

static void writeString(FILE *file, const char *value){
    fputc('"', file);
    for(const unsigned char *c = (const unsigned char *)value; *c; c++){
        if(*c == '"' || *c == '\\'){
            fputc('\\', file);
            fputc(*c, file);
        }else if(*c < 0x20){
            fprintf(file, "\\u%04x", (unsigned)*c);
        }else{
            fputc(*c, file);
        }
    }
    fputc('"', file);
}

static void writeList(FILE *file, char values[3][30]){
    fputc('[', file);
    for(int i = 0; i < 3; i++){
        if(i > 0){
            fputs(", ", file);
        }
        writeString(file, values[i]);
    }
    fputc(']', file);
}

static int copyUserPrefix(FILE *source, FILE *target, long arrayEnd){
    /* Trim whitespace before the array bracket so the comma follows the last object. */
    int c;
    do {
        if(arrayEnd <= 0 || fseek(source, --arrayEnd, SEEK_SET) != 0){
            return 0;
        }
        c = fgetc(source);
    } while(c == ' ' || c == '\t' || c == '\r' || c == '\n');

    if((c != '}' && c != '[') || fseek(source, 0, SEEK_SET) != 0){
        return 0;
    }
    for(long i = 0; i <= arrayEnd; i++){
        c = fgetc(source);
        if(c == EOF || fputc(c, target) == EOF){
            return 0;
        }
    }
    return 1;
}

int SaveUser(const char *username, char genres[3][30], char actors[3][30]){
    /* Exclusive creation also prevents two writers from overwriting each other. */
    FILE *target = fopen(tempPath, "wbx");
    if(!target){
        return 0;
    }

    FILE *source = fopen(usersPath, "rb");
    int ok;
    if(source){
        char users[MAX_USERS][7][100] = {0};
        long arrayEnd;
        int count = readUsers(source, users, &arrayEnd);
        ok = count >= 0 && count < MAX_USERS && copyUserPrefix(source, target, arrayEnd);
        if(ok && count > 0){
            fputc(',', target);
        }
        fclose(source);
    }else{
        ok = errno == ENOENT && fputs("{\n  \"users\": [", target) != EOF;
    }

    if(ok){
        fputs("\n    {\n      \"username\": ", target);
        writeString(target, username);
        fputs(",\n      \"genres\": ", target);
        writeList(target, genres);
        fputs(",\n      \"actors\": ", target);
        writeList(target, actors);
        fputs("\n    }\n  ]\n}\n", target);
    }
    int writeFailed = ferror(target);
    int closeFailed = fclose(target);
    if(ok && !writeFailed && closeFailed == 0){
#ifdef _WIN32
        if(MoveFileExA(tempPath, usersPath, MOVEFILE_REPLACE_EXISTING)){
#else
        if(rename(tempPath, usersPath) == 0){
#endif
            return 1;
        }
    }
    remove(tempPath);
    return 0;
}
