#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"

void sortingAlbum(char artists[][80], char sortedArtists[4][80], char songsArtist1[][80], char songsArtist2[][80],
                  char songsArtist3[][80], char songsArtist4[][80],  int numSongsPerArtist[4], int numOfArtists)
{
    //The following function implements Insertion Sort.

    int i, j; //position index variables for sorting.
    char swapArtist[80]; //swapping array to be used while sorting artists
    int swapIndex; //swapping variable to be used while rearranging the numSongsPerArtist array.
    char  swapSongArray[3][80]; //swapping array to be used while rearranging the songArrays to its corresponding artist..
    char sizeOfArtists[4][80], sizeOfSongArray[3][80]; //created array to be used in memcpy function to get the size of the artists array and songs array.

    memcpy(sortedArtists, artists, sizeof(sizeOfArtists)); // a copy of the artist array is copied in sortedArtists array.

    /*The following loop (1)sorts the sortedArtists array. Simultaneously, it also (2)rearranges the
     * numSongsPerArtists array so the number of songs per artist corresponds to the correct artist
     * in the sorted artists array. Similarly, it also (3)adjusts the song arrays. So, the numbered song arrays
     * will be correctly ordered according to the sortedArtists array. */

    for(i=1; i<numOfArtists; i++)
    {
        j=i;
        while (j>0 && strcmp(sortedArtists[j], sortedArtists[j-1]) < 0)
        {
            // (1):
            strcpy(swapArtist,sortedArtists[j]);
            // (2):
            swapIndex = numSongsPerArtist[j];
            // (3):
            if (j==1)
                memcpy(swapSongArray, songsArtist2, sizeof(sizeOfSongArray));
            if (j==2)
                memcpy(swapSongArray, songsArtist3, sizeof(sizeOfSongArray));
            if (j==3)
                memcpy(swapSongArray, songsArtist4, sizeof(sizeOfSongArray));

            // (1):
            strcpy(sortedArtists[j],sortedArtists[j-1]);
            // (2):
            numSongsPerArtist[j] = numSongsPerArtist[j-1];
            // (3):
            if (j==1)
                memcpy(songsArtist2, songsArtist1, sizeof(sizeOfSongArray));
            if (j==2)
                memcpy(songsArtist3, songsArtist2, sizeof(sizeOfSongArray));
            if (j==3)
                memcpy(songsArtist4, songsArtist3, sizeof(sizeOfSongArray));

            // (1):
            strcpy(sortedArtists[j-1],swapArtist);
            // (2):
            numSongsPerArtist[j-1] = swapIndex;
            // (3):
            if (j==1)
                memcpy(songsArtist1, swapSongArray, sizeof(sizeOfSongArray));
            if (j==2)
                memcpy(songsArtist2, swapSongArray, sizeof(sizeOfSongArray));
            if (j==3)
                memcpy(songsArtist3, swapSongArray, sizeof(sizeOfSongArray));

            j--;
        }
    }




    if (numOfArtists > 0)
    {
        for(i=1; i<numSongsPerArtist[0]; i++) // sorting songArtist1 array!
        {
            j=i;
            while (j>0 && strcmp(songsArtist1[j], songsArtist1[j-1]) < 0)
            {
                strcpy(swapArtist,songsArtist1[j]);
                strcpy(songsArtist1[j],songsArtist1[j-1]);
                strcpy(songsArtist1[j-1],swapArtist);

                j--;
            }
        }
    }


    if (numOfArtists > 1)
    {
        for(i=1; i<numSongsPerArtist[1]; i++) // sorting songArtist2 array!
        {
            j=i;
            while (j>0 && strcmp(songsArtist2[j], songsArtist2[j-1]) < 0)
            {
                strcpy(swapArtist,songsArtist2[j]);
                strcpy(songsArtist2[j],songsArtist2[j-1]);
                strcpy(songsArtist2[j-1],swapArtist);

                j--;
            }
        }
    }


    if (numOfArtists > 2)  // sorting songArtist3 array!
    {
        for(i=1; i<numSongsPerArtist[2]; i++)
        {
            j=i;
            while (j>0 && strcmp(songsArtist3[j], songsArtist3[j-1]) < 0)
            {
                strcpy(swapArtist,songsArtist3[j]);
                strcpy(songsArtist3[j],songsArtist3[j-1]);
                strcpy(songsArtist3[j-1],swapArtist);

                j--;
            }
        }
    }


    if (numOfArtists > 3)  // sorting songArtist4 array!
    {
        for(i=1; i<numSongsPerArtist[3]; i++)
        {
            j=i;
            while (j>0 && strcmp(songsArtist4[j], songsArtist4[j-1]) < 0)
            {
                strcpy(swapArtist,songsArtist4[j]);
                strcpy(songsArtist4[j],songsArtist4[j-1]);
                strcpy(songsArtist4[j-1],swapArtist);

                j--;
            }
        }
    }



    //Printing the sorted list of songs:
    int k;
    if (numOfArtists > 0)
    {
        printf("\nSorted list of songs:\n");
        printf("%s\n", sortedArtists[0]);
        for (k=0; k<numSongsPerArtist[0]; ++k)
        {
            printf("\t- %s\n", songsArtist1[k]);
        }
    }

    if (numOfArtists > 1)
    {
        printf("%s\n", sortedArtists[1]);
        for (k=0; k<numSongsPerArtist[1]; ++k)
        {
            printf("\t- %s\n", songsArtist2[k]);
        }
    }

    if (numOfArtists > 2)
    {
        printf("%s\n", sortedArtists[2]);
        for (k=0; k<numSongsPerArtist[2]; ++k)
        {
            printf("\t- %s\n", songsArtist3[k]);
        }
    }

    if (numOfArtists > 3)
    {
        printf("%s\n", sortedArtists[3]);
        for (k=0; k<numSongsPerArtist[3]; ++k)
        {
            printf("\t- %s\n", songsArtist4[k]);
        }
    }



}

