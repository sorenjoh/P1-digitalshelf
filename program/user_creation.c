#include "user_creation.h"
#include <stdio.h>
#include <string.h>

 void CreateUser(char Username[50], int users){
    printf("Enter a username:\n");
    scanf("%s", Username);

    int Amount_Genre = 3;
    char Genre[Amount_Genre][30];
    printf("Enter three genres you like, one per line:\n");
    for(int i = 0; i < Amount_Genre; i++){
    scanf(" %29[^\n]", Genre[i]);
    }

    int Amount_Actors = 3;
    char Actors[Amount_Actors][30];
    printf("Enter the names of three different actors you like, one per line:\n");
    for(int i = 0; i < Amount_Actors; i++){
    scanf(" %29[^\n]", Actors[i]);
    }
    Write_user_to_file(Username, Genre, Actors, users);

}


void Write_user_to_file(char Username[50], char (*Genre)[30], char (*Actors)[30], int users){
    FILE *Userfile = fopen("users.json", "a+");
        
    if (Userfile == NULL) {
        printf("Error: Could not open users.json.\n");
    }

    if(users == 0){
        fprintf(Userfile, "{\n");
    }else{
        fseek(Userfile, -2, SEEK_END); // fiks, den går ikke tilbage og overskriver de felter
        fprintf(Userfile, "},\n");
    }

    
    fprintf(Userfile, "\"user%d\":\n", users + 1);
    fprintf(Userfile, "{\n");
    fprintf(Userfile, "\"username\" : \"%s\", \n", Username);
    for(int i = 0; i < 3; i++){
        fprintf(Userfile, "\"genre%d\" : \"%s\", \n", i, Genre[i]);
    }
    for(int i = 0; i < 3; i++){
        if(i == 2){
            fprintf(Userfile, "\"actors%d\" : \"%s\" \n", i, Actors[i]);
        }else{
            fprintf(Userfile, "\"actors%d\" : \"%s\", \n", i, Actors[i]);
        }
    }
    fprintf(Userfile, "}\n");
    fprintf(Userfile, "}\n");

    fclose(Userfile);
}