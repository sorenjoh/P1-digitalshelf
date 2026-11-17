#ifndef DIGITALSHELF_USER_DATABASE_H
#define DIGITALSHELF_USER_DATABASE_H

typedef struct User User;

void Get_User(char (*Usernames)[50], int *users);
void getAll_DATA(char (*user)[7][50]);
#endif
