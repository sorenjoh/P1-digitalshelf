#include "movie_database.h"
#include <stdio.h>
#include <string.h>

#include "preference_survey.h"
#include "user_creation.h"
#include "user_database.h"

int main(int argv, char** argc){

    printf("Welcome to DigitalShelf!\n");
    char Usernames[10][50] = {0};
    int users = 0;
    Get_User(Usernames, &users);
    printf("Users: ");

    for(int i = 0; i < users; i++){
        printf("%s%s", i == 0 ? "" : ", ", Usernames[i]);
    }
    printf("\n");

    char Input[50];
    char Username[50];
    int Userfound = 0;
    int nyuser = 0;

    char genre[10];
    char actors[30];
    int length = 0;
    char director[30];
    char studio[30];
    double rating;
    printf("Enter your username or type \"create\" to create an account.\n");
    do{
        scanf("%s", Input);

        if(strcmp(Input, "create") == 0){
            CreateUser(Username, users);
            nyuser = 1;

        }
        Get_User(Usernames, &users);
        for(int i = 0; i < 10; i++){
            if(strcmp(Input, Usernames[i]) == 0 || nyuser == 1){
                Userfound = 1;

                questions(genre, actors, &length, director, studio, &rating);
                char userData[10][7][100];
                getAll_DATA(userData);
                int UserNumber = i;
                recommender(userData, genre, actors, length, director, studio, rating, UserNumber);
                //printf("%s\n%s\n%d\n%s\n%s\n%lf", genre, actors, length, director, studio, rating);
                break;
            }
        }
        if(Userfound == 0){
            printf("Username not found. Please try again.\n");
        }
    }while(Userfound == 0);



    //movieLib();
    

    return 0;

    }