#include "user_database.h"
#include <stdio.h>

void get_usernames(){

    FILE *Userfile = fopen("users.json", "r");

    if (Userfile == NULL) {
        printf("ERROR: Userfile coud not oppen \n");
    }

    char c;
    while((c = fgetc(Userfile)) != EOF){
        printf("%c", c);

    }



    fclose(Userfile);
}
