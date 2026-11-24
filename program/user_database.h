#ifndef DIGITALSHELF_USER_DATABASE_H
#define DIGITALSHELF_USER_DATABASE_H

enum { MAX_USERS = 10 };

int LoadUsers(char users[MAX_USERS][7][100]);
int SaveUser(const char *username, char genres[3][30], char actors[3][30]);

#endif
