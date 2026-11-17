#ifndef DIGITALSHELF_PREFERENCE_SURVEY_H
#define DIGITALSHELF_PREFERENCE_SURVEY_H

#include "user_database.h"
typedef struct Preferences Preferences;

void questions(char genre[10], char actors[30], int* length, char director[30], char studio[30], double* rating);

#endif
