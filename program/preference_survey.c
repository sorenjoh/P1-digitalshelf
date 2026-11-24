#include "preference_survey.h"
#include <stdio.h>
#include <string.h>

static int askTextQuestion(const char *prompt, const char *format, char *answer){
    puts(prompt);
    if(scanf(format, answer) != 1){
        return 0;
    }
    if(strcmp(answer, "-1") == 0){
        strcpy(answer, "0");
        return 0;
    }
    return 1;
}

void questions(char genre[10], char actors[30], int* length, char director[30], char studio[30], double* rating){
    strcpy(genre, "0");
    strcpy(actors, "0");
    *length = 0;
    strcpy(director, "0");
    strcpy(studio, "0");
    *rating = 0;

    puts("Answer these optional questions to narrow your search.\nIf you skip them all, recommendations will use your saved preferences.");

    if(!askTextQuestion("What movie genre are you in the mood for? Enter 0 to skip or -1 to skip all remaining questions.", " %9[^\n]", genre)){
        return;
    }

    if(!askTextQuestion("Which actor would you like to see? Enter 0 to skip or -1 to skip all remaining questions.", " %29[^\n]", actors)){
        return;
    }

    puts("How long should the movie be, in minutes? Enter 0 to skip or -1 to skip all remaining questions.");
    if(scanf("%d", length) != 1 || *length == -1){
        *length = 0;
        return;
    }

    if(!askTextQuestion("Which director do you prefer? Enter 0 to skip or -1 to skip all remaining questions.", " %29[^\n]", director)){
        return;
    }

    if(!askTextQuestion("Which studio do you prefer? Enter 0 to skip or -1 to skip all remaining questions.", " %29[^\n]", studio)){
        return;
    }

    puts("What IMDb rating are you looking for? Enter 0 to skip or -1 to skip all remaining questions.");
    if(scanf("%lf", rating) != 1 || *rating == -1){
        *rating = 0;
    }
}
