//
// Created by JEK on 3/25/2019.
//
//sasefsad
#include <cstdlib>
#include <string>

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

using namespace std;

class Song {

private:
    
    string artist;
    string title;
    int size;

public:
    //Default constructor
    //set the artist, title and size to blank and zero
    Song();

    //Constructor with artist, title, and size parameters
    // in an artist, title and size.
    Song(string artist, string title, int size);

    /* FUNCTION - string getArtist
     * Gets artist of Song object

     precondition: artist instance is valid

     input params - none

     output params - string of artist name
    */
    string getArtist() const;

    /* FUNCTION - void setArtist
        * Sets artist of Song object

        precondition: string name is valid

        input params - artist name string

        output params - none
       */
    void setArtist(string name);

    /* FUNCTION - string getTitle
        * Gets title of Song object

        precondition: artist instance is valid

        input params - none

        output params - string of title name
       */
    string getTitle() const;

    /* FUNCTION - void setTitle
       * Sets title of Song object

       precondition: string name is valid

       input params - title name string

       output params - none
      */
    void setTitle(string name);

    /* FUNCTION - string getSize
        * Gets size of Song

        precondition: size instance is valid, nonzero

        input params - none

        output params - int of song size
       */
    int getSize() const;

    /* FUNCTION - void setSize
       *Sets size of Song object

       precondition: size is valid

       input params - int of size

       output params - none
      */
    void setSize(int s);

    /* FUNCTION - void swap
       *swaps contents of songs

       input params - song to be switched

       output params - none
    */
    void swap(Song &s2);

    /* FUNCTION - redefinition of boolean operator
       *determines alphabetical precedence of songs

       input params - song to be compared

       output params - whether the lhs is greater than the rhs
    */
    bool operator >(Song const &rhs);

    /* FUNCTION - redefinition of boolean operator
       *determines alphabetical precedence of songs

       input params - song to be compared

       output params - whether the lhs is less than the rhs
    */
    bool operator <(Song const &rhs);

    /* FUNCTION - redefinition of boolean operator
       *determines equivalence of songs

       input params - song to be compared

       output params - whether the lhs is equal to the rhs
    */
    bool operator ==(Song const &rhs);

    };




#endif //UTPOD_SONG_H
