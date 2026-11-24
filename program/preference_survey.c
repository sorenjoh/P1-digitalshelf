#include "preference_survey.h"
#include <stdio.h>

void questions(char genre[10], char actors[30], int* length, char director[30], char studio[30], double* rating){

    printf("Answer these optional questions to narrow your search.\nEnter 0 to skip any question. If you skip them all, recommendations will use the preferences you entered when you created your account.\n");

   
    printf("What movie genre are you in the mood for? Enter 0 to skip.\n");
    scanf(" %9[^\n]", genre); 
    
    printf("Which actor would you like to see? Enter 0 to skip.\n");
    scanf(" %29[^\n]", actors);
    
    printf("How long should the movie be, in minutes? Enter 0 to skip.\n");
    scanf("%d", length);

    printf("Which director do you prefer? Enter 0 to skip.\n");
    scanf(" %29[^\n]", director);

    printf("Which studio do you prefer? Enter 0 to skip.\n");
    scanf(" %29[^\n]", studio);

    printf("What IMDb rating are you looking for? Enter 0 to skip.\n");
    scanf("%lf", rating);

}
