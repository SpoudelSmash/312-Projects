//
// Created by spoud on 10/20/2020.
//

#include "Song.h"

#include <utility>

//CONSTRUCTORS

/* Song default constructor
 *  Set artist, title, and size to empty values
 */
Song::Song() {
    artist = "-";
    title = "-";
    size = 0;
}

/* Song constructor w/ 3 inputs -- artist, title, size
 *  Set private vars corresponding input values
 */
Song::Song(string artist, string title, int size) {
    this->artist = move(artist);
    this->title = move(title);
    this->size = size;
}

//FUNCTIONS

//Set song artist private var
int Song::setSongArtist(string nArtist) {
    this->artist = move(nArtist);
}

//Set song title private var
int Song::setSongTitle(string nTitle) {
    this->title = move(nTitle);
}

//Set song size private var
int Song::setSongSize(int nSize) {
    this->size = nSize;
}

//OPERATORS (Comparing for Alphanumeric sorting)

//Equal to (==) operator
bool Song::operator==(const Song &lhs) const{

    if(this->getSongArtist() == lhs.getSongArtist() && this->getSongTitle() == lhs.getSongTitle() && this->getSongSize() == lhs.getSongSize()){
        return true;
    }
    else{
        return false;
    }
}

//Less than (<) operator
bool Song::operator<(const Song &lhs){
    //Check in order of artist, title, then size
    if(this->getSongArtist() < lhs.getSongArtist()){
        return true;
    }
    else if(this->getSongTitle() < lhs.getSongTitle()){
        return true;
    }
    else if(this->getSongSize() < lhs.getSongSize()){
        return true;
    }
    else{
        return false;
    }
}

//Greater than (>) operator
bool Song::operator>(const Song &lhs){
    if (*this == lhs || *this < lhs){
        return false;
    }
    else{
        return true;
    }
}

