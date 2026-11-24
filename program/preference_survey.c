#include "preference_survey.h"
#include <stdio.h>

void questions(char genre[10], char actors[30], int* length, char director[30], char studio[30], double* rating){

    printf("Here are some optional questions to help you narrow your search.\nIf nothing is answered you will be recomended from your user creation survey\n");

   
    printf("What movie genre are you in the mood for today? If you do not care for picking a genre, type 0\n");
    scanf(" %9[^\n]", genre); 
    
    printf("Which actor would you like to see today? If you do not care for picking an actor, type 0\n");
    scanf(" %29[^\n]", actors);
    
    printf("How long do you want the movie to be in minutes? If you do not care for picking a length, type 0\n");
    scanf("%d", length);

    printf("Do you want a specific director? If you do not care for picking a director, type 0\n");
    scanf(" %29[^\n]", director);

    printf("Studio preferences? If you do not care for picking a studio, type 0\n");
    scanf(" %29[^\n]", studio);

    printf("IMDB rating? If you do not care for picking a rating, type 0\n");
    scanf("%lf", rating);

}
