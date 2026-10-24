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
