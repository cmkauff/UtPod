

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"
#include <time.h>
#include <random>

using namespace std;

UtPod::UtPod() {
    songs = nullptr;
    podMemSize = MAX_MEMORY;
}

UtPod::UtPod(int size) {
    songs = nullptr;
    if(size > MAX_MEMORY){
        size = MAX_MEMORY;
    }
    else if(size< 0) {
        size = 0;
    }
    else {
        podMemSize = size;
    }
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
    SongNode *previousSong = nullptr;

    while(p1 != nullptr){
        if(p1->s == s){
          if(previousSong == nullptr){
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

void UtPod::shuffle(){

    if (songs != nullptr) {
        SongNode *p1 = songs;                               //count number of nodes
        int nodeCount = 0;
        while (p1 != nullptr){
            p1 = p1->next;
            nodeCount ++;
        }
        srand((unsigned int) time(nullptr));
        SongNode *p2 = songs;
        SongNode *prev1 = nullptr;
        SongNode *swap1 = nullptr;
        SongNode *p3 = songs;
        SongNode *prev2 = nullptr;
        SongNode *swap2 = nullptr;
        for (int i = 0; i < nodeCount; i++) {
            while (p2 != nullptr) {                         //generate random number to select a node
                if ((rand() % nodeCount) == 0) {
                    swap1 = p2;
                    p2 = nullptr;
                }else {
                    prev1 = p2;
                    p2 = p2->next;
                }
            }
            while (p3 != nullptr) {                         //generate random number to select a second node
                if ((rand() % nodeCount) == 0) {
                    swap2 = p3;
                    p3 = nullptr;
                }else {
                    prev2 = p3;
                    p3 = p3->next;
                }
            }
            if (prev1 == nullptr){                          //swap them (this is inefficient rn)
                SongNode *temp;
                songs = swap2;
                prev2->next = swap1;
                temp->next = swap1->next;
                swap1->next = swap2->next;
                swap2->next = temp->next;
            }else if (prev2 == nullptr){
                SongNode *temp;
                songs = swap1;
                prev1->next = swap2;
                temp->next = swap1->next;
                swap1->next = swap2->next;
                swap2->next = temp->next;
            }else if()

        }


    }


}

void UtPod::showSongList(){
    SongNode *p1 = songs;
    while(p1 != nullptr){
        cout << p1->s.getTitle() << ", " << p1->s.getArtist() << ", " << p1->s.getSize() << endl;
        p1 = p1->next;
    }
}

void UtPod::sortSongList() {
    if (songs != nullptr) {
        SongNode *p1 = songs;
        SongNode *p2;
        while(p1->next != nullptr) {
            p2 = p1->next;
            while (p2 != nullptr) {
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
    while(p1 != nullptr){
        temp = p1;
        p1 = p1->next;
        delete(temp);
    }
    songs = nullptr;
}

int UtPod::getRemainingMemory(){
    int remainingSize = podMemSize;
    SongNode *p1 = songs;
    while(p1 != nullptr){
        remainingSize = remainingSize - p1->s.getSize();
        p1 = p1->next;
    }
    return remainingSize;
}

UtPod::~UtPod(){
    SongNode *p1 = songs;
    SongNode *temp;
    while(p1 != nullptr){
        temp = p1;
        p1 = p1->next;
        delete(temp);
    }
}