#include <stdio.h>
#include <string.h>
#include "inputFunction.h"

int insertArtists(char artists[][80], char songsArtist1[][80], char songsArtist2[][80],
                  char songsArtist3[][80], char songsArtist4[][80],  int numSongsPerArtist[4])
{
    int countArtists = 0;
    int numOfSongs; //Keeps count of the number of songs as inserted for each artist one at a time.
    //The value is then stored in its respective position in the 'numSongsPerArtist' array.
    int artistLength, songLength; //Variables to hold length of string, while adding the null terminator.
    int i, j; // j = artist count for the outer 'for' loop
    // i = song count for inner 'while' loops

    for (j=0; j<4; j++) {
        //Getting the artist name.
        printf("Insert an artist/group name:\n");
        fgets(artists[j],80,stdin);

        if (artists[j][0] =='\n') //If the user pressed enter instead of an artist name, the loop terminates.
        {
            break;
        }

        countArtists++; /* And if the user did not press enter, it implies that an artist name was entered,
          therefore numOfArtists is incremented.*/

        //adding the null terminator:
        artistLength = strlen(artists[j]);
        artists[j][artistLength-1] = '\0';

        /*The integer j checks which nth artist is added, so it can then store their respective songs
        in the correct array.*/
        if (j == 0) { //The following if statement is run to get and store songs for the first artist.
            i=0;
            numOfSongs = 0;
            while (i<3) {
                //Getting songs:
                printf("Insert song %d for %s:\n", i+1, artists[j]);
                fgets(songsArtist1[i], 80,stdin);

                if (songsArtist1[i][0] =='\n') {
                    break;
                }

                //adding the null terminator:
                songLength = strlen(songsArtist1[i]);
                songsArtist1[i][songLength-1] = '\0';

                numOfSongs++; //counts the number of songs entered for this artist.
                i++;
            }
            numSongsPerArtist[j] = numOfSongs; //when the while loop is completed the value of 'numOfSongs is
            //stored in as the jth (i.e 'first' in this case) position of numSongsPerArtist.
        }


        else if (j == 1) { //The following if statement is run to get and store songs for the second artist.
            i=0;
            numOfSongs = 0; //Variable is set to 0, so it can now begin count of songs for the 2nd Artist.
            while (i<3){
                printf("Insert song %d for %s:\n", i+1, artists[j]);
                fgets(songsArtist2[i], 80,stdin);

                if (songsArtist2[i][0] =='\n') {
                    break;
                }

                songLength = strlen(songsArtist2[i]);
                songsArtist2[i][songLength-1] = '\0';

                numOfSongs++;
                i++;
            }
            numSongsPerArtist[j] = numOfSongs; //when the while loop is completed the value of 'numOfSongs is
            //stored in as the jth (i.e 'second' in this case) position of numSongsPerArtist.
        }


        else if (j == 2) {
            i=0;
            numOfSongs = 0;
            while (i<3){
                printf("Insert song %d for %s:\n", i+1, artists[j]);
                fgets(songsArtist3[i], 80,stdin);

                if (songsArtist3[i][0] =='\n') {
                    break;
                }
                songLength = strlen(songsArtist3[i]);
                songsArtist3[i][songLength-1] = '\0';

                numOfSongs++;
                i++;
            }
            numSongsPerArtist[j] = numOfSongs;
        }


        else { //j=3:
            i=0;
            numOfSongs = 0;
            while (i<3){
                printf("Insert song %d for %s:\n", i+1, artists[j]);
                fgets(songsArtist4[i], 80,stdin);

                if (songsArtist4[i][0] =='\n') {
                    break;
                }
                songLength = strlen(songsArtist4[i]);
                songsArtist4[i][songLength-1] = '\0';

                numOfSongs++;
                i++;
            }
            numSongsPerArtist[j] = numOfSongs;
        }
    }

    return countArtists; //Returns the total number of artists entered, which is then stored in
                         //the numOfArtists variable in the main function.
}
