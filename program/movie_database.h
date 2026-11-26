#ifndef DIGITALSHELF_MOVIE_DATABASE_H
#define DIGITALSHELF_MOVIE_DATABASE_H


typedef struct {
    char title[100];
    char genre[50];
    int year;
    int duration;
    char director[100];
    float rating;
    char actors[3][100];
} Film;

//Film filmList[] = {0};
void movieLib(void);

void GetMoviesFromFile(void);
void recommender(char userData[10][7][100], char genre[10], char actors[30], int length, char director[30], char studio[30], double rating, int UserNumber);

#endif
