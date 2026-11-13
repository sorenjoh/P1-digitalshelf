#include "user_database.h"
#include <stdio.h>
#include <string.h>

void Get_User(char (*Usernames)[50], int *users){ //Get usernames from JSON file
    FILE *Userfile = fopen("users.json", "r");
        
    if (Userfile == NULL) {
        printf("ERROR: Userfile coud not oppen \n");
    }

    char output[50];

    int c;
    int Bool_CauntDown = 0;
    int Counter = 0;
    //int users = 0;
    while((c = fgetc(Userfile)) != EOF){ //tager hver karakter i filen indtil "End of file"
        output[0] = c; //Tilskriver den første karakter i hver karakter-serie
        if(Bool_CauntDown == 1){
            Counter++;
        }
        for(int i = 1; i < 50; i++){ //Laver en karakter-serie på op til 50 karaktere som man kan sammeligne med
            output[i] = fgetc(Userfile);
            if(output[i] == '"'){
                output[i] = 0;
                if(strcmp(output, "username") == 0){ // finder username
                    Bool_CauntDown = 1;
                    (*users)++;
                }
                break;
            }
        }

        if(Counter == 2){
            for(int i = 0; i < 50; i++){ // Gemmer username i egen liste og usernames
            Usernames[*users - 1][i] = output[i];
            }

        Counter = 0;
        Bool_CauntDown = 0;
        }
        for(int i = 0; i < 50; i++){ // clear array
            output[i] = 0;
        }
    }

    fclose(Userfile);
}



void getAll_DATA(char (*user)[7][50]){ //multidimentional arrayis i c håntere der første array som en pointer 
    FILE *Userfile = fopen("users.json", "r"); //åbner json filen i read mode og håntere filadressen med "Userfile"

    if (Userfile == NULL) { //Tjekker om filen ikke blevet åbnet
        printf("ERROR: Userfile coud not oppen \n");
    }

    char output[50]; // liste som håntere midlertidig data som små strings.

    int c;
    int Bool_CauntDown = 0;
    int Counter = 0;
    int users = 0; //antallet af user i json fil
    int datapoint = 0; //Hvilken data der gemmes i array
    while((c = fgetc(Userfile)) != EOF){ //tager hver karakter i filen indtil "End of file"
        output[0] = c; //Tilskriver den første karakter i hver karakter-serie
        if(Bool_CauntDown == 1){ //håntere den tæller der holder styr på hvor mange små strings der dannes.
            Counter++;
        }
        for(int i = 1; i < 50; i++){ //Laver en karakter-serie på op til 50 karaktere som man kan sammeligne med
            output[i] = fgetc(Userfile);
            printf("%c ", output[i]);
            if(output[i] == '"'){
                output[i] = 0;
                if(strcmp(output, "username") == 0){ // finder username
                    Bool_CauntDown = 1;
                    datapoint = 0;
                    users++;
                }else if(strcmp(output, "genre0") == 0){
                    Bool_CauntDown = 1;
                    datapoint = 1;
                }else if(strcmp(output, "genre1") == 0){
                    Bool_CauntDown = 1;
                    datapoint = 2;
                }else if(strcmp(output, "genre2") == 0){
                    Bool_CauntDown = 1;
                    datapoint = 3;
                }else if(strcmp(output, "Movie0") == 0){
                    Bool_CauntDown = 1;
                    datapoint = 4;
                }else if(strcmp(output, "Movie1") == 0){
                    Bool_CauntDown = 1;
                    datapoint = 5;
                }else if(strcmp(output, "Movie2") == 0){
                    Bool_CauntDown = 1;
                    datapoint = 6;
                }
                break;
            }
        }
        if(Counter == 2){
            for(int i = 0; i < 50; i++){ // Gemmer samtlige data.
                user[users - 1][datapoint][i] = output[i];
            }
            Counter = 0;
            Bool_CauntDown = 0;
        }
        for(int i = 0; i < 50; i++){ // clear midlertidig data array
            output[i] = 0;
        }         
    }
               
    fclose(Userfile);
}
