#include "main_menu.h"

void Get_User(){ //Get usernames from JSON file
    FILE *Userfile = fopen("users.json", "r");
        
    if (Userfile == NULL) {
        printf("ERROR: Userfile coud not oppen \n");
    }

    char output[50];
    char Usernames[10][50];

    int c;
    int Bool_CauntDown = 0;
    int Counter = 0;
    int users = 0;
    int SizeOfList = 0;
    while((c = fgetc(Userfile)) != EOF){ //tager hver karakter i filen indtil "End of file"
        output[0] = c; //Tilskriver den første karakter i hver karakter-serie
        if(Bool_CauntDown == 1){
            Counter++;
        }
        for(int i = 1; i < 50; i++){ //Laver en karakter-serie på op til 50 karaktere som man kan sammeligne med
            output[i] = fgetc(Userfile);
            SizeOfList++;
            if(output[i] == '"'){
                output[i] = 0;
                if(strcmp(output, "username") == 0){ // finder username
                    //printf("\nUsername1234 \n"); // test
                    Bool_CauntDown = 1;
                    users++;
                }
                //printf("Sice of string: %d, string: %s\n", SizeOfList, output);
                SizeOfList = 0; 
                break;
            }
        }
        /*
        for(int i = 0; i < 50; i++){ // udskriv array
            printf("%c",output[i]);
        }*/

        if(Counter == 2){
            for(int i = 0; i < 50; i++){ // Gemmer username i egen liste og usernames
            Usernames[users - 1][i] = output[i];//----------------------------------------fejlen ligger på denne linje ----------------------------------//
            }
        //printf("output: %s: ",output);
        //printf("Copy output: %s, user: %d \n", Usernames[0], users - 1);

        Counter = 0;
        Bool_CauntDown = 0;
        }
        for(int i = 0; i < 50; i++){ // clear array
            output[i] = 0;
        }
    }

    for(int i = 0; i < users; i++){ //Udskriver username liste
        printf("user: ");

        for(int j = 0; j < 50; j++){
            printf("%c",Usernames[i][j]);
        }
        printf("\n");

    }

    fclose(Userfile);
}