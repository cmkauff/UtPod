

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

UtPod::UtPod() {
    songs = NULL;
    podMemSize = MAX_MEMORY;
}

UtPod::UtPod(int size) {
    songs = NULL;
    podMemSize = size;
}

int UtPod::addSong(Song const &s){
    if(s.getSize() > getRemainingMemory() ){
        return -1;
    }
    else {
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;
        return 0;
    }
}

int UtPod::removeSong(Song const &s){
    SongNode *p1 = songs;
    SongNode *previousSong = NULL;

    while(p1 != NULL){
        if(p1->s == s){
          if(previousSong == NULL){
              songs = p1->next;
              delete(p1);
          }
          else{
              previousSong->next = p1->next;
              delete(p1);
          }
          return 0;
        }
        previousSong = p1;
        p1 = p1->next;
    }
    return -1;
}

void UtPod::shuffle(){}

void UtPod::showSongList(){
    SongNode *p1 = songs;
    while(p1 != NULL){
        cout << p1->s.getTitle() << ", " << p1->s.getArtist() << ", " << p1->s.getSize() << endl;
        p1 = p1->next;
    }
}

void UtPod::sortSongList(){
    int count = 0;

}

void UtPod::clearMemory(){
    SongNode *p1 = songs;
    SongNode *temp;
    while(p1 != NULL){
        temp = p1;
        p1 = p1->next;
        delete(temp);
    }
    songs = NULL;
}

int UtPod::getRemainingMemory(){
    int remainingSize = podMemSize;
    SongNode *p1 = songs;
    while(p1 != NULL){
        remainingSize = remainingSize - p1->s.getSize();
        p1 = p1->next;
    }
    return remainingSize;
}

UtPod::~UtPod(){
    SongNode *p1 = songs;
    SongNode *temp;
    while(p1 != NULL){
        temp = p1;
        p1 = p1->next;
        delete(temp);
    }
}