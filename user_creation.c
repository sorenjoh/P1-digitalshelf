#include "user_creation.h"
#include <stdio.h>

void CreateUser(int users){
    char Username[50];
    printf("write a username: \n");
    scanf("%s", Username);

    char Genre[3][30];
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
    Write_user_to_file(Username, Genre, DislikedGenres, Movies, Actors, users);

}


void Write_user_to_file(char Username[50], char (*Genre)[30], char (*DislikeGenre)[30], char (*Movies)[30], char (*Actors)[30], int users){
    FILE *Userfile = fopen("users.json", "a+");
        
    if (Userfile == NULL) {
        printf("ERROR: Userfile coud not oppen \n");
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
        fprintf(Userfile, "\"dislikeGenre%d\" : \"%s\", \n", i, DislikeGenre[i]);
    }
    for(int i = 0; i < 3; i++){
        fprintf(Userfile, "\"movies%d\" : \"%s\", \n", i, Movies[i]);
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