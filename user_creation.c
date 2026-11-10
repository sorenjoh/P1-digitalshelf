#include "user_creation.h"
#include <stdio.h>

void CreateUser(void){
    char Username[50];
    printf("write a username: \n");
    scanf("%s", Username);

    char Genre[3][10];
    printf("write a tre genre: \n");
    scanf("%s", Genre[0]);
    scanf("%s", Genre[1]);
    scanf("%s", Genre[2]);

    char DislikedGenres[3][30];
    printf("Write three different genres you dislike: \n");
    scanf("%s", DislikedGenres[0]);
    scanf("%s", DislikedGenres[1]);
    scanf("%s", DislikedGenres[2]);

    char Movies[3][30];
    printf("write a tre diffrent movies you like: \n");
    scanf("%s", Movies[0]);
    scanf("%s", Movies[1]);
    scanf("%s", Movies[2]);

    char Actors[3][30];
    printf("Write three different actors you like: \n");
    scanf("%s", Actors[0]);
    scanf("%s", Actors[1]);
    scanf("%s", Actors[2]);


    FILE *Userfile = fopen("users.json", "a+");

    if (Userfile == NULL) {
        printf("ERROR: Userfile coud not oppen \n");
    }

    fprintf(Userfile, "{\n");
    fprintf(Userfile, "    \"username\": \"%s\",  \n\n", Username);

    for(int i = 0; i < 3; i++){
    fprintf(Userfile, "    \"genre%d\": \"%s\",  \n", i, Genre[i]);
    }

    for(int i = 0; i < 3; i++){
    fprintf(Userfile, "    \"DislikedGenres%d\": \"%s\",  \n", i, DislikedGenres[i]);
    }

    for(int i = 0; i < 3; i++){
    fprintf(Userfile, "    \"Actors%d\": \"%s\",  \n", i, Actors[i]);
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
