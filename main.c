#include "main_menu.h"
#include <stdio.h>
#include <string.h>

#include "preference_survey.h"
#include "user_creation.h"
#include "user_database.h"



int main(int argv, char** argc){

    printf("Hello and welcome to our film recomender \n");
    char Usernames[10][50] = {0};
    int users = 0;
    Get_User(Usernames, &users);
    printf("users: ");

    for(int i = 0; i < 10; i++){
        printf("%s ", Usernames[i]);
    }
    printf("\n");

    char Input[50];
    char Username[50];
    int Userfound = 0;
    int nyuser = 0;
    printf("write you username or \"create\" \n");
    //do{
        scanf("%s", Input);

        if(strcmp(Input, "create") == 0){
            CreateUser(Username, users);
            nyuser = 1;
            /*for (int i = 0; i < 50; i++) {
                Usernames[users][i]=Username[i];
                users+=1;
            }
            printf("\n main:%s %s\n", Username, Usernames[users]);*/
        }
        for(int i = 0; i < 10; i++){
            if(strcmp(Input, Usernames[i]) == 0 || nyuser == 1){
                Userfound = 1;
                char genre[10];
                char actors[30];
                int length;
                char director[30];
                char studio[30];
                double rating;
                questions(genre, actors, &length, director, studio, &rating);
                //printf("%s\n%s\n%d\n%s\n%s\n%lf", genre, actors, length, director, studio, rating);
                break;
            }
        }
        if(Userfound == 0){
            printf("Not a username: try again! \n");
        }
    //}while(Userfound == 0);


    return 0;

    }