#include "movie_database.h"
#include <stdio.h>
#include <string.h>

#include "preference_survey.h"
#include "user_creation.h"
#include "user_database.h"

int main(void){
    puts("Welcome to DigitalShelf!");
    char userData[MAX_USERS][7][100];
    int users = LoadUsers(userData);
    if(users < 0){
        puts("Error: Could not read users.json.");
        return 1;
    }

    printf("Users: ");
    for(int i = 0; i < users; i++){
        printf("%s%s", i == 0 ? "" : ", ", userData[i][0]);
    }
    printf("\n");

    char input[50];
    int userNumber = -1;
    puts("Enter your username or type \"create\" to create an account.");
    while(userNumber < 0){
        if(scanf("%49s", input) != 1){
            return 0;
        }

        if(strcmp(input, "create") == 0){
            if(users == MAX_USERS){
                puts("The user database is full.");
                continue;
            }
            if(!CreateUser(input)){
                return 1;
            }
            users = LoadUsers(userData);
            if(users < 0){
                puts("Error: Could not read users.json.");
                return 1;
            }
            if(users > 0 && strcmp(input, userData[users - 1][0]) == 0){
                userNumber = users - 1;
            }
        }

        for(int i = 0; userNumber < 0 && i < users; i++){
            if(strcmp(input, userData[i][0]) == 0){
                userNumber = i;
            }
        }
        if(userNumber < 0){
            puts("Username not found. Please try again.");
        }
    }

    char genre[10], actors[30], director[30], studio[30];
    int length;
    double rating;
    questions(genre, actors, &length, director, studio, &rating);
    recommender(userData, genre, actors, length, director, studio, rating, userNumber);
    return 0;
}
