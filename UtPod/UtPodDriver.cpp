
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[]) {
    UtPod t;
    UtPod t2(100);
    cout << "UtPod t called with default constructor size = 512mb" << endl;
    cout << "UtPod t2 called with non-default constructor size = 100mb" << endl;

    Song s1("Edith Piaf", "La Vi En Rose", 22);
    int result = t.addSong(s1);
    cout << "adding song result = " << result << endl;

    t.showSongList();

    Song s2("Pixies", "Hey", 16);
    result = t.addSong(s2);
    cout << "adding song result = " << result << endl;

    t.showSongList();

    Song s3("Chvrches", "Mother We Share", 18);
    result = t.addSong(s3);
    cout << "adding song result = " << result << endl;

    t.showSongList();
    cout << "removing Mother We Share result = " << result << endl;
    t.removeSong(s3);
    t.showSongList();

    Song s4("Pixies", "Hey", 16);
    result = t.addSong(s4);
    cout << "adding song result = " << result << endl;

    Song s8("Pixies", "Hey", 20);
    result = t.addSong(s8);
    cout << "adding song result = " << result << endl;

    t.showSongList();
    t.shuffle();
    t.showSongList();
    cout << endl << "Shuffling" << endl << endl;
    t.shuffle();
    t.showSongList();

    cout << endl << "Sorting" << endl << endl;
    t.sortSongList();
    t.showSongList();

    Song s5("Eeatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s6("Featles", "Hey Jude6", 6);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    Song s7("Geatles", "Hey Jude5", 8);
    result = t.addSong(s7);
    cout << "add result = " << result << endl;
/*
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
*/

}