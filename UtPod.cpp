

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"
#include <time.h>
#include <random>

using namespace std;

UtPod::UtPod() {
    songs = NULL;
    podMemSize = MAX_MEMORY;
}

UtPod::UtPod(int size) {
    songs = NULL;
    if(size > MAX_MEMORY){
        size = MAX_MEMORY;
    }
    else if(size< 0) {
        size = SUCCESS;
    }
    else {
        podMemSize = size;
    }
}
int UtPod::numSongs(){
    SongNode *p1 = songs;
    int nodeCount = 0;
    while (p1 != NULL) {
        p1 = p1->next;
        nodeCount++;
    }
    return nodeCount;
}
int UtPod::addSong(Song const &s){
    if(s.getTitle() == "" || s.getArtist() == "" || s.getSize() == 0 || s.getSize() > getRemainingMemory() ){
        return NO_MEMORY;
    }
    else {
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = songs;
        songs = temp;
        return SUCCESS;
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
          return SUCCESS;
        }
        previousSong = p1;
        p1 = p1->next;
    }
    return NO_MEMORY;
}

void UtPod::shuffle(){
    if (songs != NULL) {
        srand((unsigned int) time(NULL));
        SongNode *p1 = songs;                               //count number of nodes
        SongNode *p2;

        while (p1 != NULL) {
            p2 = songs;
            for(int i = 0;i<(rand() % numSongs()); i++){
                p2 = p2->next;
            }
            if(p1 != p2) {
                p1->s.swap(p2->s);
            }
            p1 = p1->next;
        }
    }
}

void UtPod::showSongList(){
    SongNode *p1 = songs;
    while(p1 != NULL){
        cout << p1->s.getTitle() << ", " << p1->s.getArtist() << ", " << p1->s.getSize() << endl;
        p1 = p1->next;
    }
}

void UtPod::sortSongList() {
    if (songs != NULL) {
        SongNode *p1 = songs;
        SongNode *p2;
        while(p1->next != NULL) {
            p2 = p1->next;
            while (p2 != NULL) {
                if(p2->s > p1->s){
                    p1->s.swap(p2->s);
                }
                else {
                    p2 = p2->next;
                }
            }
            p1 = p1->next;
        }
    }

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