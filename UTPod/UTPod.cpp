#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
#pragma ide diagnostic ignored "cert-msc51-cpp"
//
// Created by spoud on 10/20/2020.
//
#include "UTPod.h"

//Default constructor
//set the memory size to MAX_MEMORY
using namespace std;

UTPod::UTPod(){
    memSize = MAX_MEMORY;
    songs = nullptr;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UTPod::UTPod(int size) {
    if(size > MAX_MEMORY || size <= 0){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
    songs = nullptr;
}


/* FUNCTION - int addSong
 * attempts to add a new song to the UTPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song
*/

int UTPod::addSong(Song const &s){
    //Check if enough mem to store song
    if(getRemainingMemory() >= s.getSongSize()){
        //Store
        if(songs == nullptr){
            songs = new SongNode; //New song to empty list
            songs->s = s;
        }
        else{
            //Prepend
            SongNode *tmpPtr = songs; //Save ptr to 1st node
            songs = new SongNode;   //Create new node and put at front of list

            //Set new node's values
            songs->next = tmpPtr;
            songs->s = s;
        }
        return SUCCESS;
    }
    else{
        return NO_MEMORY; //Not enough mem
    }
}


/* FUNCTION - int removeSong
 * attempts to remove a song from the UTPod
 * removes the first instance of a song that is in the the UTPod multiple times
     o returns 0 if successful
     o returns -2 if nothing is removed
*/

int UTPod::removeSong(const Song &s) {
    //Set up temp pointer to 1st node of list
    SongNode *tmpPtr = songs;
    SongNode *prevPtr = nullptr;
    //Navigate song list while not NULL
    while (tmpPtr){
        //Compare currently pointed song to input song
        if(tmpPtr->s == s){
            //Remove current node
            //For head node
            if(prevPtr == nullptr){
                songs = tmpPtr->next;   //Set new head node
            }
            else{
                prevPtr->next = tmpPtr->next;   //Set prev node to next node
            }
            delete tmpPtr;
            return SUCCESS;
        }
        prevPtr = tmpPtr;
        tmpPtr = tmpPtr->next;
    }

    return NOT_FOUND;
}


/* FUNCTION - void shuffle
 *  shuffles the songs into random order
    o will do nothing if there are less than two songs in the current list
*/

/*void UTPod::shuffle() {
    //Seed rand func
    srand(time(nullptr));

    SongNode *curPtr = songs->next;
    SongNode *prevPtr = songs;


    int shuffleCount = 50;
    int numSongs = getNumSongs();

    //Go through songs placing them in random locations (2nd node to numsong node)
    while(curPtr && shuffleCount != 0){

        //Find new location to take
        SongNode *prevLoc = nullptr;
        SongNode *newLoc = songs;

        for(int location = rand() % numSongs; location > 0; location--){
            //Save previous
            prevLoc = newLoc;
            newLoc = newLoc->next;
        }

        //Remove Loc
        prevLoc->next = newLoc->next;
        newLoc->next = prevPtr;

        //Swap location with head
        newLoc->next = songs->next;
        songs = newLoc;

        shuffleCount--;
    }


}*/


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)
*/

void UTPod::showSongList() {
    SongNode *tmpPtr = songs;
    if(tmpPtr == nullptr){
        cout << "There are no songs here :(" << endl;
    }
    //Navigate Song list
    while (tmpPtr){
        //Output song info
        cout << tmpPtr->s.getSongTitle() << ", ";
        cout << tmpPtr->s.getSongArtist() << ", ";
        cout << tmpPtr->s.getSongSize() << "MB" << endl;

        tmpPtr = tmpPtr->next;
    }
}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list
*/

void UTPod::sortSongList() {
    //Initialize pointers
    SongNode *prevPtr = songs;
    SongNode *curPtr = prevPtr->next;

    //Go through each SongNode starting at 2nd item
    while(curPtr){
        //Pointers for search algorithm
        SongNode *sorted = songs;
        SongNode *prevSorted = nullptr;

        //Search until cur song < sorted song or until sorted = current
        while(curPtr->s > sorted->s && sorted != curPtr){
            //Check next
            prevSorted = sorted;    //Save prev pointer
            sorted = sorted->next;
        }

        //prevSorted is the new position for current; sorted is position after current
        if(sorted != curPtr){
            //Remove from current position
            prevPtr->next = curPtr->next;

            //Insert at head node
            if(prevSorted == nullptr){
                curPtr->next = songs->next;
                songs = curPtr;
            }
            //Insert current before sorted
            else{
                //Remove next
                //prevPtr->next = curPtr->next;

                //
                prevSorted->next = curPtr;
            }

            curPtr->next = sorted;
        }

        prevPtr = curPtr;
        curPtr= curPtr->next;
    }

}


/* FUNCTION - void clearMemory
 * clears all the songs from memory
*/
void UTPod::clearMemory(){
    SongNode *tmpPtr = nullptr;

    //Go through all songs, deleting each
    while(songs){
        tmpPtr = songs; //Save, to delete after
        songs = songs->next;
        delete tmpPtr;
    }
    //songs ends up as nullptr
}

/* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs
*/

int UTPod::getRemainingMemory() {
    int remMem = memSize;  //Remaining mem count

    SongNode *tmpPtr = songs;   //Point to 1st node
    //tmpPtr = tmpPtr->next;

   //Navigate song list
    while (tmpPtr){
        remMem -= tmpPtr->s.getSongSize();  //Subtract current song node's mem from remMem
        tmpPtr = tmpPtr->next;
    }

    return remMem;

}


UTPod::~UTPod() {
    while (songs) {
        SongNode* next = songs->next;
        delete songs;
        songs = next;
    }
}

int UTPod::getNumSongs() {
    SongNode *tmpPtr = songs;
    int count;
    while(tmpPtr){
        count++;
        tmpPtr = tmpPtr->next;
    }
    return count;
}

#pragma clang diagnostic pop