//
// Created by spoud on 10/20/2020.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H
#include <string>

using namespace std;

class Song {
public:
    Song();
    Song(string artist, string title, int size);

    string getSongArtist() const {return artist;}
    string getSongTitle() const {return title;}
    int getSongSize() const {return size;}

    int setSongArtist(string nArtist);
    int setSongTitle(string nTitle);
    int setSongSize(int nSize);

    bool operator==(const Song &lhs) const;
    bool operator<(const Song &lhs);
    bool operator>(const Song &lhs);

private:
    string artist;
    string title;
    int size;
};


#endif //UTPOD_SONG_H
