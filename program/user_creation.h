#ifndef DIGITALSHELF_USER_CREATION_H
#define DIGITALSHELF_USER_CREATION_H

#include <stdio.h>
#include <string.h>


void CreateUser(char Username[50],int users);
void Write_user_to_file(char Username[50], char (*Genre)[30], char (*Actors)[30], int users);



#endif
