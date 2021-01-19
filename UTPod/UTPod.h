//DOCUMENT HERE

#ifndef UTPod_H
#define UTPod_H
#include "Song.h"
#include <iostream>
#include <ctime>
#include <random>

//UTPod class declaration
class UTPod
{
private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;
      
      struct SongNode
      {
         Song s;
         SongNode *next;
      };
      
      SongNode *songs;  //the head pointer
      
      int memSize;

      int swapNodes(SongNode *swap1, SongNode *swap2);
   
public:
      UTPod();
      UTPod(int size);


      int addSong(Song const &s);

      int removeSong(Song const &s);

      void shuffle();

      void showSongList();

      void sortSongList();

      void clearMemory();

      int getTotalMemory() const {
         return memSize;
      }

      int getRemainingMemory();

      int getNumSongs();

      ~UTPod();
 
};


#endif //UTPod_H
