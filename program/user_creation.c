#include "user_creation.h"
#include "user_database.h"
#include <stdio.h>

int CreateUser(char username[50]){
    char genres[3][30];
    char actors[3][30];

    puts("Enter a username:");
    if(scanf("%49s", username) != 1){
        return 0;
    }

    puts("Enter three genres you like, one per line:");
    for(int i = 0; i < 3; i++){
        if(scanf(" %29[^\n]", genres[i]) != 1){
            return 0;
        }
    }

    puts("Enter the names of three different actors you like, one per line:");
    for(int i = 0; i < 3; i++){
        if(scanf(" %29[^\n]", actors[i]) != 1){
            return 0;
        }
    }

    if(!SaveUser(username, genres, actors)){
        puts("Error: Could not save the account to users.json.");
        return 0;
    }
    return 1;
}
