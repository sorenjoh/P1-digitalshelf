#include <stdio.h>
#include <string.h>

void CreateUser(){
    char Username[50];
    printf("write a username: \n");
    scanf("%s", Username);

    char Genre[3][10];
    printf("write a tre genre: \n");
    scanf("%s", Genre[0]);
    scanf("%s", Genre[1]);
    scanf("%s", Genre[2]);

    char Movies[3][30];
    printf("write a tre diffrent movies you like: \n");
    scanf("%s", Movies[0]);
    scanf("%s", Movies[1]);
    scanf("%s", Movies[2]);

    FILE *Userfile = fopen("users.json", "w");
        
    if (Userfile == NULL) {
        printf("ERROR: Userfile coud not oppen \n");
    }

    fprintf(Userfile, "{\n");
    fprintf(Userfile, "    \"username\": \"%s\",  \n\n", Username);

    for(int i = 0; i < 3; i++){
    fprintf(Userfile, "    \"genre%d\": \"%s\",  \n", i, Genre[i]);
    }

    fprintf(Userfile, "\n");

    for(int i = 0; i < 3; i++){
        if(i == 3 - 1){
            fprintf(Userfile, "    \"Movie%d\": \"%s\"  \n", i, Movies[i]);
        }else{
            fprintf(Userfile, "    \"Movie%d\": \"%s\",  \n", i, Movies[i]);
        }
    }
    fprintf(Userfile, "}\n");
    fclose(Userfile);
}


int main(int argv, char** argc){
    char Input[50];

    printf("Hello and welcome to our film recomender \n");
    printf("write you username or \"create\" \n");

    scanf("%s", Input);

    if(strcmp(Input, "create") == 0){
        CreateUser();
    }


    return 0;    
}

