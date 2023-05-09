#include "sortAndShuffle.h"
#include "inputFunction.h"

int main(void)
{
    int numOfArtists;
    //The array containing artists names
    char artists[4][80];
    //The array containing the sorted artists
    char sortedArtists[4][80];
    //Songs for Artist 1
    char songsArtist1[3][80];
    //Songs for Artist 2
    char songsArtist2[3][80];
    //Songs for Artist 3
    char songsArtist3[3][80];
    //Songs for Artist 4
    char songsArtist4[3][80];
    //The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
    int numSongsPerArtist[4];


    //Function to insert Artists and Songs:
    numOfArtists = insertArtists(artists, songsArtist1, songsArtist2, songsArtist3, songsArtist4, numSongsPerArtist);

    //Sorting Function:
    sortingAlbum(artists, sortedArtists, songsArtist1, songsArtist2,
                 songsArtist3, songsArtist4, numSongsPerArtist, numOfArtists);

    // Shuffling Function:
    shuffleAlbum(sortedArtists, songsArtist1, songsArtist2, songsArtist3,
            songsArtist4, numSongsPerArtist, numOfArtists);

    return 0;
}