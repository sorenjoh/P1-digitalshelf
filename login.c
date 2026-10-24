#include "login.h"
#include "user_creation.h"

#include <stdio.h>
#include <string.h>

void login(void)
{
    char Input[50];

    printf("write you username or \"create\" \n");
    scanf("%s", Input);

    if(strcmp(Input, "create") == 0){
        CreateUser();
    }
}
