
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

    cout << "Showing Song List:" << endl;
    t.showSongList();

    cout << endl << "Shuffling" << endl << endl;
    t.shuffle();

    Song s1("Edith Piaf", "La Vie En Rose", 22);
    int result = t.addSong(s1);
    cout << "adding song result = " << result << endl << endl;

    cout << "Showing Song List:" << endl;
    t.showSongList();

    Song s2("Pixies", "Hey", 16);
    result = t.addSong(s2);
    cout << endl << "adding song result = " << result << endl;

    Song s3("Chvrches", "Mother We Share", 18);
    result = t.addSong(s3);
    cout << "adding song result = " << result << endl;

    Song s4("Pixies", "Hey", 16);
    result = t.addSong(s4);
    cout << "adding song result = " << result << endl;

    Song s5("Pixies", "Hey", 20);
    result = t.addSong(s5);
    cout << "adding song result = " << result << endl;

    Song s6("Pixies", "Gigantic", 20);
    result = t.addSong(s6);
    cout << "adding song result = " << result << endl;

    Song s7("Eagles", "Hotel California", 60);
    result = t.addSong(s7);
    cout << "add result = " << result << endl;

    Song s8("Aerosmith", "Toys in the Attic", 26);
    result = t.addSong(s8);
    cout << "add result = " << result << endl;

    Song s9("The Doors", "The End", 102);
    result = t.addSong(s9);
    cout << "add result = " << result << endl;

    Song s10;
    result = t.addSong(s10);
    cout << endl << "adding a default song: add result = " << result << endl << endl;

    cout << "Showing Song List:" << endl;
    t.showSongList();

    cout << endl << "Shuffling" << endl << endl;
    t.shuffle();

    cout << "Showing Song List:" << endl;
    t.showSongList();

    cout << endl << "Shuffling" << endl << endl;
    t.shuffle();

    cout << "Showing Song List:" << endl;
    t.showSongList();

    cout << endl << "Sorting" << endl << endl;
    t.sortSongList();

    cout << "Showing Song List:" << endl;
    t.showSongList();

    result = t.removeSong(s2);
    cout << endl << "delete result = " << result << endl << endl;

    cout << "Showing Song List:" << endl;
    t.showSongList();

    result = t.removeSong(s2);
    cout << endl << "delete result = " << result << endl << endl;

    cout << "Showing Song List:" << endl;
    t.showSongList();

    cout << endl << "Adding a song that exceeds memory to UtPod t2" << endl;
    result = t2.addSong(s9);
    cout << "add result = " << result << endl;

    t.clearMemory();
    cout << endl << "Clearing Memory" << endl << endl;

    cout << "Showing Song List:" << endl;
    t.showSongList();


    result = t.addSong(s1);
    cout << endl << "adding song result = " << result << endl;
    cout << "Showing Song List:" << endl;
    t.showSongList();

    result = t.removeSong(s9);
    cout << endl << "Removing a song that is not in the UtPod Linked List: result is " << result << endl << endl;

    cout << "Showing Song List:" << endl;
    t.showSongList();

    t.~UtPod();
    t2.~UtPod();
}