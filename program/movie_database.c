#include "movie_database.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
    Film filmList[] = {
        {"Groundhog Day", "Comedy", 1993, 101, "Harold Ramis", 8.0, {"Bill Murray", "Andie MacDowell", "Chris Elliott"}},
        {"Superbad", "Comedy", 2007, 113, "Greg Mottola", 7.6, {"Jonah Hill", "Michael Cera", "Christopher Mintz-Plasse"}},
        {"The Grand Budapest Hotel", "Comedy", 2014, 99, "Wes Anderson", 8.1, {"Ralph Fiennes", "Tony Revolori", "F. Murray Abraham"}},
        {"The Hangover", "Comedy", 2009, 100, "Todd Phillips", 7.7, {"Bradley Cooper", "Ed Helms", "Zach Galifianakis"}},
        {"Mean Girls", "Comedy", 2004, 97, "Mark Waters", 7.1, {"Lindsay Lohan", "Rachel McAdams", "Lacey Chabert"}},
        {"Bridesmaids", "Comedy", 2011, 125, "Paul Feig", 6.8, {"Kristen Wiig", "Maya Rudolph", "Rose Byrne"}},
        {"Dumb and Dumber", "Comedy", 1994, 107, "Peter Farrelly", 7.3, {"Jim Carrey", "Jeff Daniels", "Lauren Holly"}},
        {"The 40-Year-Old Virgin", "Comedy", 2005, 116, "Judd Apatow", 7.1, {"Steve Carell", "Catherine Keener", "Paul Rudd"}},
        {"Grown Ups", "Comedy", 2010, 102, "Dennis Dugan", 6.0, {"Adam Sandler", "Kevin James", "Chris Rock"}},

        {"The Dark Knight", "Action", 2008, 152, "Christopher Nolan", 9.1, {"Christian Bale", "Heath Ledger", "Aaron Eckhart"}},
        {"Die Hard", "Action", 1988, 132, "John McTiernan", 8.2, {"Bruce Willis", "Alan Rickman", "Bonnie Bedelia"}},
        {"Mad Max: Fury Road", "Action", 2015, 120, "George Miller", 8.1, {"Tom Hardy", "Charlize Theron", "Nicholas Hoult"}},
        {"John Wick", "Action", 2014, 101, "Chad Stahelski", 7.4, {"Keanu Reeves", "Michael Nyqvist", "Willem Dafoe"}},
        {"Mission: Impossible - Fallout", "Action", 2018, 147, "Christopher McQuarrie", 7.7, {"Tom Cruise", "Henry Cavill", "Rebecca Ferguson"}},
        {"Top Gun: Maverick", "Action", 2022, 130, "Joseph Kosinski", 8.2, {"Tom Cruise", "Miles Teller", "Jennifer Connelly"}},
        {"The Raid: Redemption", "Action", 2011, 101, "Gareth Evans", 7.6, {"Iko Uwais", "Joe Taslim", "Donny Alamsyah"}},
        {"Speed", "Action", 1994, 116, "Jan de Bont", 7.3, {"Keanu Reeves", "Sandra Bullock", "Dennis Hopper"}},
        {"Transformers: Revenge of the Fallen", "Action", 2009, 149, "Michael Bay", 6.0, {"Shia LaBeouf", "Megan Fox", "Josh Duhamel"}},

        {"The Exorcist", "Horror", 1973, 122, "William Friedkin", 8.1, {"Ellen Burstyn", "Linda Blair", "Max von Sydow"}},
        {"Halloween", "Horror", 1978, 91, "John Carpenter", 7.7, {"Donald Pleasence", "Jamie Lee Curtis", "P. J. Soles"}},
        {"The Shining", "Horror", 1980, 146, "Stanley Kubrick", 8.4, {"Jack Nicholson", "Shelley Duvall", "Danny Lloyd"}},
        {"The Conjuring", "Horror", 2013, 112, "James Wan", 7.5, {"Vera Farmiga", "Patrick Wilson", "Lili Taylor"}},
        {"Sinners", "Horror", 2025, 137, "Ryan Coogler", 7.5, {"Michael B. Jordan", "Hailee Steinfeld", "Miles Caton"}},
        {"Hereditary", "Horror", 2018, 127, "Ari Aster", 7.3, {"Toni Collette", "Alex Wolff", "Milly Shapiro"}},
        {"A Quiet Place", "Horror", 2018, 90, "John Krasinski", 7.5, {"Emily Blunt", "John Krasinski", "Millicent Simmonds"}},
        {"The Blair Witch Project", "Horror", 1999, 81, "Daniel Myrick, Eduardo Sanchez", 6.5, {"Heather Donahue", "Joshua Leonard", "Michael C. Williams"}},
        {"The Nun", "Horror", 2018, 96, "Corin Hardy", 5.4, {"Taissa Farmiga", "Demian Bichir", "Jonas Bloquet"}},

        {"Star Wars: Episode IV - A New Hope", "Sci-Fi", 1977, 121, "George Lucas", 8.6, {"Mark Hamill", "Harrison Ford", "Carrie Fisher"}},
        {"Blade Runner", "Sci-Fi", 1982, 117, "Ridley Scott", 8.1, {"Harrison Ford", "Rutger Hauer", "Sean Young"}},
        {"The Matrix", "Sci-Fi", 1999, 136, "Lana Wachowski, Lilly Wachowski", 8.7, {"Keanu Reeves", "Laurence Fishburne", "Carrie-Anne Moss"}},
        {"Inception", "Sci-Fi", 2010, 148, "Christopher Nolan", 8.8, {"Leonardo DiCaprio", "Joseph Gordon-Levitt", "Marion Cotillard"}},
        {"Interstellar", "Sci-Fi", 2014, 169, "Christopher Nolan", 8.7, {"Matthew McConaughey", "Anne Hathaway", "Jessica Chastain"}},
        {"Arrival", "Sci-Fi", 2016, 116, "Denis Villeneuve", 7.9, {"Amy Adams", "Jeremy Renner", "Forest Whitaker"}},
        {"The Martian", "Sci-Fi", 2015, 144, "Ridley Scott", 8.0, {"Matt Damon", "Jessica Chastain", "Chiwetel Ejiofor"}},
        {"Dune", "Sci-Fi", 2021, 155, "Denis Villeneuve", 8.0, {"Timothee Chalamet", "Rebecca Ferguson", "Zendaya"}},
        {"Dune: Part Two", "Sci-Fi", 2024, 166, "Denis Villeneuve", 8.4, {"Timothee Chalamet", "Zendaya", "Rebecca Ferguson"}},
        {"Jupiter Ascending", "Sci-Fi", 2015, 127, "Lana Wachowski, Lilly Wachowski", 5.3, {"Mila Kunis", "Channing Tatum", "Eddie Redmayne"}},

        {"The Lord of the Rings: The Fellowship of the Ring", "Fantasy", 2001, 178, "Peter Jackson", 8.9, {"Elijah Wood", "Ian McKellen", "Viggo Mortensen"}},
        {"The Lord of the Rings: The Two Towers", "Fantasy", 2002, 179, "Peter Jackson", 8.8, {"Elijah Wood", "Ian McKellen", "Viggo Mortensen"}},
        {"The Lord of the Rings: The Return of the King", "Fantasy", 2003, 201, "Peter Jackson", 9.0, {"Elijah Wood", "Ian McKellen", "Viggo Mortensen"}},
        {"Harry Potter and the Sorcerer's Stone", "Fantasy", 2001, 152, "Chris Columbus", 7.7, {"Daniel Radcliffe", "Rupert Grint", "Emma Watson"}},
        {"Harry Potter and the Prisoner of Azkaban", "Fantasy", 2004, 142, "Alfonso Cuaron", 7.9, {"Daniel Radcliffe", "Rupert Grint", "Emma Watson"}},
        {"Pirates of the Caribbean: The Curse of the Black Pearl", "Fantasy", 2003, 143, "Gore Verbinski", 8.1, {"Johnny Depp", "Orlando Bloom", "Keira Knightley"}},
        {"The Princess Bride", "Fantasy", 1987, 98, "Rob Reiner", 8.0, {"Cary Elwes", "Robin Wright", "Mandy Patinkin"}},
        {"Pan's Labyrinth", "Fantasy", 2006, 118, "Guillermo del Toro", 8.2, {"Ivana Baquero", "Sergi Lopez", "Maribel Verdu"}},
        {"Big Fish", "Fantasy", 2003, 125, "Tim Burton", 8.0, {"Ewan McGregor", "Albert Finney", "Billy Crudup"}},

        {"Toy Story", "Animation", 1995, 81, "John Lasseter", 8.3, {"Tom Hanks", "Tim Allen", "Don Rickles"}},
        {"Shrek", "Animation", 2001, 90, "Andrew Adamson, Vicky Jenson", 7.9, {"Mike Myers", "Eddie Murphy", "Cameron Diaz"}},
        {"Finding Nemo", "Animation", 2003, 100, "Andrew Stanton, Lee Unkrich", 8.2, {"Albert Brooks", "Ellen DeGeneres", "Alexander Gould"}},
        {"Spirited Away", "Animation", 2001, 124, "Hayao Miyazaki", 8.6, {"Rumi Hiiragi", "Miyu Irino", "Mari Natsuki"}},
        {"WALL-E", "Animation", 2008, 98, "Andrew Stanton", 8.4, {"Ben Burtt", "Elissa Knight", "Jeff Garlin"}},
        {"The Aristocats", "Animation", 1970, 78, "Wolfgang Reitherman", 7.1, {"Phil Harris", "Eva Gabor", "Sterling Holloway"}},
        {"The Land Before Time", "Animation", 1988, 69, "Don Bluth", 7.4, {"Gabriel Damon", "Candace Hutson", "Judith Barsi"}},
        {"Spider-Man: Into the Spider-Verse", "Animation", 2018, 117, "Bob Persichetti, Peter Ramsey, Rodney Rothman", 8.4, {"Shameik Moore", "Jake Johnson", "Hailee Steinfeld"}},
        {"The Wild Robot", "Animation", 2024, 102, "Chris Sanders", 8.1, {"Lupita Nyong'o", "Pedro Pascal", "Kit Connor"}},

        {"Se7en", "Thriller", 1995, 127, "David Fincher", 8.6, {"Brad Pitt", "Morgan Freeman", "Gwyneth Paltrow"}},
        {"The Silence of the Lambs", "Thriller", 1991, 118, "Jonathan Demme", 8.6, {"Jodie Foster", "Anthony Hopkins", "Ted Levine"}},
        {"Prisoners", "Thriller", 2013, 153, "Denis Villeneuve", 8.2, {"Hugh Jackman", "Jake Gyllenhaal", "Paul Dano"}},
        {"Gone Girl", "Thriller", 2014, 149, "David Fincher", 8.1, {"Ben Affleck", "Rosamund Pike", "Neil Patrick Harris"}},
        {"Shutter Island", "Thriller", 2010, 138, "Martin Scorsese", 8.2, {"Leonardo DiCaprio", "Mark Ruffalo", "Ben Kingsley"}},
        {"Nightcrawler", "Thriller", 2014, 117, "Dan Gilroy", 7.8, {"Jake Gyllenhaal", "Rene Russo", "Riz Ahmed"}},
        {"The Sixth Sense", "Thriller", 1999, 107, "M. Night Shyamalan", 8.2, {"Bruce Willis", "Haley Joel Osment", "Toni Collette"}},
        {"Get Out", "Thriller", 2017, 104, "Jordan Peele", 7.8, {"Daniel Kaluuya", "Allison Williams", "Catherine Keener"}},
        {"The Girl with the Dragon Tattoo", "Thriller", 2011, 158, "David Fincher", 7.8, {"Daniel Craig", "Rooney Mara", "Christopher Plummer"}},

        {"The Notebook", "Romance", 2004, 123, "Nick Cassavetes", 7.8, {"Ryan Gosling", "Rachel McAdams", "James Garner"}},
        {"Before Sunrise", "Romance", 1995, 101, "Richard Linklater", 8.1, {"Ethan Hawke", "Julie Delpy"}},
        {"Before Sunset", "Romance", 2004, 80, "Richard Linklater", 8.1, {"Ethan Hawke", "Julie Delpy"}},
        {"Before Midnight", "Romance", 2013, 109, "Richard Linklater", 7.9, {"Ethan Hawke", "Julie Delpy"}},
        {"Pride & Prejudice", "Romance", 2005, 129, "Joe Wright", 7.8, {"Keira Knightley", "Matthew Macfadyen", "Donald Sutherland"}},
        {"About Time", "Romance", 2013, 123, "Richard Curtis", 7.8, {"Domhnall Gleeson", "Rachel McAdams", "Bill Nighy"}},
        {"Notting Hill", "Romance", 1999, 124, "Roger Michell", 7.2, {"Hugh Grant", "Julia Roberts", "Rhys Ifans"}},
        {"Pretty Woman", "Romance", 1990, 119, "Garry Marshall", 7.1, {"Richard Gere", "Julia Roberts", "Hector Elizondo"}},
        {"Titanic", "Romance", 1997, 194, "James Cameron", 7.9, {"Leonardo DiCaprio", "Kate Winslet", "Billy Zane"}},

        {"The Godfather", "Crime", 1972, 175, "Francis Ford Coppola", 9.2, {"Marlon Brando", "Al Pacino", "James Caan"}},
        {"Pulp Fiction", "Crime", 1994, 154, "Quentin Tarantino", 8.8, {"John Travolta", "Samuel L. Jackson", "Uma Thurman"}},
        {"Goodfellas", "Crime", 1990, 145, "Martin Scorsese", 8.7, {"Ray Liotta", "Robert De Niro", "Joe Pesci"}},
        {"The Departed", "Crime", 2006, 151, "Martin Scorsese", 8.5, {"Leonardo DiCaprio", "Matt Damon", "Jack Nicholson"}},
        {"Heat", "Crime", 1995, 170, "Michael Mann", 8.3, {"Al Pacino", "Robert De Niro", "Val Kilmer"}},
        {"Scarface", "Crime", 1983, 170, "Brian De Palma", 8.3, {"Al Pacino", "Michelle Pfeiffer", "Steven Bauer"}},
        {"The Usual Suspects", "Crime", 1995, 106, "Bryan Singer", 8.5, {"Kevin Spacey", "Gabriel Byrne", "Chazz Palminteri"}},
        {"Casino", "Crime", 1995, 178, "Martin Scorsese", 8.2, {"Robert De Niro", "Sharon Stone", "Joe Pesci"}},
        {"The Irishman", "Crime", 2019, 209, "Martin Scorsese", 7.8, {"Robert De Niro", "Al Pacino", "Joe Pesci"}},

        {"Grease", "Musical", 1978, 110, "Randal Kleiser", 7.2, {"John Travolta", "Olivia Newton-John", "Stockard Channing"}},
        {"The Rocky Horror Picture Show", "Musical", 1975, 100, "Jim Sharman", 7.4, {"Tim Curry", "Susan Sarandon", "Barry Bostwick"}},
        {"The Blues Brothers", "Musical", 1980, 133, "John Landis", 7.9, {"John Belushi", "Dan Aykroyd", "Carrie Fisher"}},
        {"Moulin Rouge!", "Musical", 2001, 127, "Baz Luhrmann", 7.6, {"Nicole Kidman", "Ewan McGregor", "Richard Roxburgh"}},
        {"Chicago", "Musical", 2002, 113, "Rob Marshall", 7.2, {"Renee Zellweger", "Catherine Zeta-Jones", "Richard Gere"}},
        {"Hairspray", "Musical", 2007, 117, "Adam Shankman", 6.7, {"Nikki Blonsky", "John Travolta", "Zac Efron"}},
        {"Mamma Mia!", "Musical", 2008, 108, "Phyllida Lloyd", 6.5, {"Meryl Streep", "Amanda Seyfried", "Pierce Brosnan"}},
        {"Les Miserables", "Musical", 2012, 158, "Tom Hooper", 7.5, {"Hugh Jackman", "Russell Crowe", "Anne Hathaway"}},
        {"La La Land", "Musical", 2016, 128, "Damien Chazelle", 8.0, {"Ryan Gosling", "Emma Stone", "John Legend"}},

        {"Gandhi", "Biography", 1982, 191, "Richard Attenborough", 8.0, {"Ben Kingsley", "Rohini Hattangadi", "Roshan Seth"}},
        {"A Beautiful Mind", "Biography", 2001, 135, "Ron Howard", 8.2, {"Russell Crowe", "Jennifer Connelly", "Ed Harris"}},
        {"The Pursuit of Happyness", "Biography", 2006, 117, "Gabriele Muccino", 8.0, {"Will Smith", "Jaden Smith", "Thandiwe Newton"}},
        {"The Social Network", "Biography", 2010, 120, "David Fincher", 7.8, {"Jesse Eisenberg", "Andrew Garfield", "Justin Timberlake"}},
        {"The Theory of Everything", "Biography", 2014, 123, "James Marsh", 7.7, {"Eddie Redmayne", "Felicity Jones", "Charlie Cox"}},
        {"The Imitation Game", "Biography", 2014, 114, "Morten Tyldum", 8.0, {"Benedict Cumberbatch", "Keira Knightley", "Matthew Goode"}},
        {"Bohemian Rhapsody", "Biography", 2018, 134, "Bryan Singer", 7.9, {"Rami Malek", "Lucy Boynton", "Gwilym Lee"}},
        {"Oppenheimer", "Biography", 2023, 180, "Christopher Nolan", 8.2, {"Cillian Murphy", "Emily Blunt", "Robert Downey Jr."}},
        {"The Wolf of Wall Street", "Biography", 2013, 180, "Martin Scorsese", 8.2, {"Leonardo DiCaprio", "Jonah Hill", "Margot Robbie"}}
    };
*/

Film filmList[100];
void GetMoviesFromFile(void){
    Film filmList[100];

void GetMoviesFromFile(void){

    FILE *MovieFile = fopen("Movies.csv", "r");

    if(MovieFile == NULL){
        printf("ERROR: Moviefile could not open\n");
        return;
    }

    const int CharAmount = 100;
    char Movies[CharAmount];

    int c;
    int posInfilmList = 0;
    int datapoint = 0;
    int AntalCaraktere = 0;
    int NyLinje = 0;

    // Nulstil alle film
    memset(filmList, 0, sizeof(filmList));

    while((c = fgetc(MovieFile)) != EOF &&
          posInfilmList < 100){

        NyLinje = 0;
        AntalCaraktere = 0;

        // Indlæser et helt felt fra CSV-filen
        for(int i = 0; ; ){

            if(c == ','){
                break;

            }else if(c == '\n' || c == EOF){
                NyLinje = 1;
                break;

            }else if(c != '\r'){

                // Sørger for, at arrayet ikke overfyldes
                if(i < CharAmount - 1){
                    Movies[i] = c;
                    AntalCaraktere++;
                    i++;
                }
            }

            c = fgetc(MovieFile);
        }
        // Afslutter vores string
        Movies[AntalCaraktere] = '\0';

        // Overfører data til vores struct
        for(int i = 0; i <= AntalCaraktere; i++){

            if(datapoint == 0){
                filmList[posInfilmList].title[i] = Movies[i];

            }else if(datapoint == 1){
                if(i < 49){
                    filmList[posInfilmList].genre[i] = Movies[i];
                }

            }else if(datapoint == 2){
                filmList[posInfilmList].year = atoi(Movies);
                break;

            }else if(datapoint == 3){
                filmList[posInfilmList].duration = atoi(Movies);
                break;

            }else if(datapoint == 4){
                filmList[posInfilmList].director[i] = Movies[i];

            }else if(datapoint == 5){
                filmList[posInfilmList].rating = atof(Movies);
                break;

            }else if(datapoint == 6){
                filmList[posInfilmList].actors[0][i] = Movies[i];

            }else if(datapoint == 7){
                filmList[posInfilmList].actors[1][i] = Movies[i];

            }else if(datapoint == 8){
                filmList[posInfilmList].actors[2][i] = Movies[i];

            }else{
                printf("ERROR: Overflow af datapoints\n");
                break;
            }
        }

        // Først nu går vi videre til næste felt eller film
        if(NyLinje == 1){
            posInfilmList++;
            datapoint = 0;
        }else{
            datapoint++;
        }

        // Tømmer midlertidig string
        AntalCaraktere = 0;

        for(int i = 0; i < CharAmount; i++){
            Movies[i] = '\0';
        }

        if(c == EOF){
            break;
        }
    }

    fclose(MovieFile);

    printf("Antal indlaeste film: %d\n", posInfilmList);

    // Printer alle indlæste film
    for(int i = 0; i < posInfilmList; i++){

        printf("%s, %s, %d, %d, %s, %.1f, %s, %s, %s\n",
            filmList[i].title,
            filmList[i].genre,
            filmList[i].year,
            filmList[i].duration,
            filmList[i].director,
            filmList[i].rating,
            filmList[i].actors[0],
            filmList[i].actors[1],
            filmList[i].actors[2]);
    }

    printf("\n");
}
        
}



void movieLib(void) {

    int movieCount = sizeof(filmList) / sizeof(filmList[0]);

    for (int i = 0; i < movieCount; i++) {
        printf("Title: %s\n", filmList[i].title);
        printf("Genre: %s\n", filmList[i].genre);
        printf("Year: %d\n", filmList[i].year);
        printf("Duration: %d minutes\n", filmList[i].duration);
        printf("Director: %s\n", filmList[i].director);
        printf("Rating: %.1f\n", filmList[i].rating);
        printf("Actors:\n");

        for (int j = 0; j < 3; j++) {
            if (filmList[i].actors[j][0] != '\0') {
                printf("  - %s\n", filmList[i].actors[j]);
            }
        }

        printf("--------------------\n");
    }

    
}


void recommender(char userData[10][7][100], char genre[10], char actors[30], int length, char director[30], char studio[30], double rating, int UserNumber){
    int points[100] = {0};
        double Max = 0;
        double Min = 0;
    for(int i = 0; i < 100; i++){
        if(strcmp(filmList[i].genre, genre) == 0){
            points[i] = points[i] + 3;
            //printf("Movie %d (%s): + 3 points for genre\n", i, filmList[i].title);
        }
        int actorCount = sizeof(filmList[i].actors) / sizeof(filmList[i].actors[0]);

        for(int j = 0; j < actorCount; j++){
            if(strcmp(filmList[i].actors[j], actors) == 0){
                points[i] = points[i] + 3;
                //printf("Movie %d (%s): + 3 points for actor\n", i, filmList[i].title);
            }
        }
        Max = length + 15;
        Min = length - 15;
        if(Min < filmList[i].duration && Max > filmList[i].duration){
            points[i] = points[i] + 3;
            //printf("Movie %d (%s): + 3 points for length\n", i, filmList[i].title);
        }
        if(strcmp(filmList[i].director, director) == 0){
            points[i] = points[i] + 3;
            //printf("Movie %d (%s): + 3 points for director\n", i, filmList[i].title);
        }
        Max = rating + 0.5;
        Min = rating - 0.5;
        if(Min < filmList[i].rating && Max > filmList[i].rating){
            points[i] = points[i] + 3;
            //printf("Movie %d (%s): + 3 points for rating\n", i, filmList[i].title);
        }

        if(strcmp(filmList[i].genre, userData[UserNumber][1]) == 0){
            points[i] = points[i] + 1;
            //printf("Movie %d (%s): + 1 point for genre 1\n", i, filmList[i].title);
        }
        if(strcmp(filmList[i].genre, userData[UserNumber][2]) == 0){
            points[i] = points[i] + 1;
            //printf("Movie %d (%s): + 1 point for genre 2\n", i, filmList[i].title);
        }
        if(strcmp(filmList[i].genre, userData[UserNumber][3]) == 0){
            points[i] = points[i] + 1;
            //printf("Movie %d (%s): + 1 point for genre 3\n", i, filmList[i].title);
        }
       
        if(strcmp(filmList[i].actors[0], userData[UserNumber][4]) == 0){
            points[i] = points[i] + 1;
            //printf("Movie %d (%s): + 1 point for actor 1\n", i, filmList[i].title);
        }
        if(strcmp(filmList[i].actors[1], userData[UserNumber][5]) == 0){
            points[i] = points[i] + 1;
            //printf("Movie %d (%s): + 1 point for actor 2\n", i, filmList[i].title);
        }
        if(strcmp(filmList[i].actors[2], userData[UserNumber][6]) == 0){
            points[i] = points[i] + 1;
            //printf("Movie %d (%s): + 1 point for actor 3\n", i, filmList[i].title);
        }
    }
    int movieCount = sizeof(filmList) / sizeof(filmList[0]); // Dette vier ikke! Vi ønsker at få de 3 film med højest antal poing

    int ChoosenMovis[3][2] = {0}; //Oprette array til at indholde vore 3 film vi vil anbefale. Indholder: {[point (point fra points), pos (pos i filmList)]}  //[2] film med flest point, [1] film med 2. flest point, [0] film med 3. flest point.
   for(int k = 0; k < movieCount; k++){ // Gennemkøre alle elementer i vores filmList (filmList size)
        if(points[k] < ChoosenMovis[0][0]){ //tjekker om filmen på pos k har flere point end ChoosenMovis på plads 0

        }else if(points[k] <= ChoosenMovis[1][0]){ //tjekker om filmen på pos k har flere point end ChoosenMovis på plads 1
            ChoosenMovis[0][0] = points[k];
            ChoosenMovis[0][1] = k;

        }else if(points[k] <= ChoosenMovis[2][0]){//tjekker om filmen på pos k har flere point end ChoosenMovis på plads 2
            ChoosenMovis[0][0] = ChoosenMovis[1][0];
            ChoosenMovis[0][1] = ChoosenMovis[1][1];

            ChoosenMovis[1][0] = points[k];
            ChoosenMovis[1][1] = k;
        }else{ //tjekker om filmen på pos k har flere point end 
            ChoosenMovis[0][0] = ChoosenMovis[1][0];
            ChoosenMovis[0][1] = ChoosenMovis[1][1];

            ChoosenMovis[1][0] = ChoosenMovis[2][0];
            ChoosenMovis[1][1] = ChoosenMovis[2][1];

            ChoosenMovis[2][0] = points[k];
            ChoosenMovis[2][1] = k;
        }
   }
    printf("Recommended movies and their scores:\n");

   for(int k = 0; k < 3; k++){
    printf("%s (score: %d)\n", filmList[ChoosenMovis[k][1]].title, ChoosenMovis[k][0]);
   }
/*
   for(int i = 0; i < 100; i++){
    printf("Index: %d, score: %d, movie: %s\n", i, points[i], filmList[i].title);
   }
*/
   }


