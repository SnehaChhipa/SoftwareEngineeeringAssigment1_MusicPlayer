#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sortAndShuffle.h"

void shuffleAlbum(char sortedArtists[4][80], char songsArtist1[][80], char songsArtist2[][80],
                  char songsArtist3[][80], char songsArtist4[][80],  int numSongsPerArtist[4], int numOfArtists)
{
    char preShuffledPlaylist[24][165];
    char spaceHyphen[4] = " - ";
    int i, k, nthSong, repetition, count;


    //Part 1: Creating a preShuffledPlayList (sorted) array which contains all artists with their songs(x2) as each song must appear twice.
    count = 0; //counts the number of entries in the preShuffledPlaylist.
    i = 0; // position variable to fill preShuffledPlaylist array.
    repetition = 1;
    while (repetition <= 2)
    {
        k = 0; // k keeps count of number of Artist.
        while (k < numOfArtists)
        {
            //adding the songs of the kth artist to preShuffledPlaylist array:
            for (nthSong = 0; nthSong < numSongsPerArtist[k]; nthSong++)
            {
                strcpy(preShuffledPlaylist[i], sortedArtists[k]); //copies the artist name.
                strncat(preShuffledPlaylist[i], spaceHyphen, 3); //adds space and hyphen after the artist name.

                //The following statements adds the nth song of the kth artist after its name.
                if (k == 0) //For Artist 1:
                    strncat(preShuffledPlaylist[i], songsArtist1[nthSong], strlen(songsArtist1[nthSong]));
                else if (k == 1) //For Artist 2:
                    strncat(preShuffledPlaylist[i], songsArtist2[nthSong], strlen(songsArtist2[nthSong]));
                else if (k == 2) //For Artist 3:
                    strncat(preShuffledPlaylist[i], songsArtist3[nthSong], strlen(songsArtist3[nthSong]));
                else //For Artist 4:
                    strncat(preShuffledPlaylist[i], songsArtist4[nthSong], strlen(songsArtist4[nthSong]));

                i++;
                count++;
            }
            k++;
        }
        repetition++;
    }




    //Part 2: Shuffling the pre-shuffledPlaylist array in a new array using Fisher Yates Algorithm:
    int p, q; //Variables to be used in shuffling algorithm as position indexes.
    char swapShuffle[126]; //swapping array to be used while shuffling songs.
    char ShuffledPlaylist[24][165]; //A new array for shuffled playlist.

    srand(time(NULL)); //giving the seed to rand();
    bool swapAllowed;

    memcpy(ShuffledPlaylist, preShuffledPlaylist, sizeof(preShuffledPlaylist)); //creating a copy of th pre-shuffledPlaylist.




    //Part 3: Shuffling:
    if (count <= 12)
    {
        printf("\n\n!!Fully shuffling the playlist is not possible as the total number of songs is which is 6 or less.!!\n");
        printf("Shuffling is done as best as possible!:\n");
    }
    p = 1;
    while (p < count)
    {
        q = rand() % (p + 1);
        swapAllowed = true;

        //The following conditions are to check if the song at position p appears
        // within the 5 songs before & after it's new position q.
        // If swapAllowed is false, then the swap cannot happen.
        if (q != p)
        {

            if (count > 12)
            {
                if (q > 0 && q < 5)
                    for (k = 0; k < q && swapAllowed == true; k++)
                    {
                        if (strcmp(ShuffledPlaylist[p], ShuffledPlaylist[k]) == 0)
                            swapAllowed = false;
                    }
                else
                    for (k = (q - 5); q != 0 && k < q && swapAllowed == true; k++)
                    {
                        if (strcmp(ShuffledPlaylist[p], ShuffledPlaylist[k]) == 0)
                            swapAllowed = false;
                    }

                if (q < (count - 5))
                    for (k = (q + 1); k < (q + 6) && swapAllowed == true; k++)
                    {
                        if (strcmp(ShuffledPlaylist[p], ShuffledPlaylist[k]) == 0)
                            swapAllowed = false;
                    }
                else
                    for (k = (q + 1); k < count && swapAllowed == true; k++)
                    {
                        if (strcmp(ShuffledPlaylist[p], ShuffledPlaylist[k]) == 0)
                            swapAllowed = false;
                    }

                //If any of the above conditions if true (i.e. swapAllowed = false)
                //Therefore, there is no need to check for the new position p for song @ q.

                //Otherwise, we must check position p too (to move song q safely)
                //Note that for position p, we only have to check for similarity of songs
                //within the last 5 songs, because further in the loop p will be incremented if a swap happens.
                //So the loop will go through checking conditions at each iteration.

                //Conditions for checking position p:
                if (p < 5)
                    for (k = 0; k < p && swapAllowed == true; k++)
                    {
                        if (strcmp(ShuffledPlaylist[q], ShuffledPlaylist[k]) == 0)
                            swapAllowed = false;
                    }
                else
                    for (k = (p - 5); k < p && swapAllowed == true; k++)
                    {
                        if (strcmp(ShuffledPlaylist[q], ShuffledPlaylist[k]) == 0)
                            swapAllowed = false;
                    }
            }



            //the swap:
            if (q!=p && swapAllowed == true)
            {
                strcpy(swapShuffle, ShuffledPlaylist[q]);
                strcpy(ShuffledPlaylist[q], ShuffledPlaylist[p]);
                strcpy(ShuffledPlaylist[p], swapShuffle);
            }
            else
            {
                swapAllowed = false;
            }


            if (p > 6) //This code is to ensure that when p is greater than 6, then p is only incremented
                // when a swap has happened, to ensure proper shuffling to meet the requirements.
            {
                if (swapAllowed == true)
                    p++;
            }
            else //If p is less than 6, it means that the first 6 elements are already not repeated.
                // So it is safe if they remain un-swapped, and therefore p can be incremented.
            {
                p++;
            }


        }
    }



    //Printing Shuffled list of songs:
    printf("\nShuffled Playlist:\n");
    for (k = 0; k < count; ++k)
    {
        printf("%s\n", ShuffledPlaylist[k]);
    }


}
