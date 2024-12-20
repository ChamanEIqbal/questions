/**
 * Welcome back, Space Engineer! Your mission, should you choose to accept it, involves aiding 
the Zafarian Space Crew aboard the Xal'tharis as they journey across the cosmos.
 The crew relies on their trusty AI to manage their Galactic Jazza Playlist, 
a circular playlist that never ends—just like their voyages through the stars.

* However, the AI's code has encountered several bugs that need fixing. It’s your 
job to troubleshoot and debug the issues in the playlist system so that the crew 
can continue enjoying their intergalactic tunes.

* The Galactic Playlist is implemented as a CIRCULAR LINKED LIST, 
where each song is represented by a JazzaNode, and the spaceship’s 
AI has to handle the following tasks:

1) Add a new Jazza song to the playlist (song is appended to the end of the list).

2) Display the current playlist for the crew to see, looping through all songs in the playlist.

3) Move to the next Jazza in the playlist, ensuring the song plays in a loop.

4) Ensure that the playlist functions correctly and loops back once the crew has cycled through all the songs.


* Task:
Your mission is to debug the code and ensure the Jazza Playlist works as expected, 
without any crashes or errors. The playlist must loop smoothly, and the crew must be able to add, play, 
and display songs seamlessly.


Galactic Playlist of the Zafarian Star Consortium:
    Astro Jam by The Martian Band
    Nebula Groove by Pluto Funk
    Starship Anthem by Nova Alliance
    Hyperdrive Melody by Andromeda Sounds
 */


#include <iostream>
#define GALACTICPLAYLIST_H 0
#include <string>


using namespace std;

struct JazzaNode {
    string title;
    string artist;
    JazzaNode* next;
    
   
    JazzaNode(jazzaTitle, jazzaArtist) : title(jazzaTitle), artist(jazzaArtist), next(nullptr) {}
};

#if GALACTICPLAYLIST_H

class GalacticPlaylistQueue {
private:
    JazzaNode* head; 
    JazzaNode* tail;  
    JazzaNode* current

public:
    
    GalacticPlaylistQueue() : head(nullptr), tail(nullptr), current(nullptr) {} //constructor

    
    ~GalacticPlaylistQueue() {
        while (head) {
            JazzaNode* temp = head;
            head = head->next;
            delete temp
        }
    } //destructor
   

    void add_jazza(const string& title, const string& artist) {
        JazzaNode* newJazza = new JazzaNode(title, artist);
        if (!tail) { 
            head = tail = current = newJazza;  
        } else {
            tail->next = newJazza;
            tail = newJazza;
        }
        tail->next = head;
    }
     
 
    void display_playlist() {
        cout << "Current Galactic Playlist:" << endl;
        JazzaNode* currentNode = head;
        do {
            cout << " - " << currentNode->title << " by " << currentNode->artist << endl;
            currentNode = currentNode->next;
        } while (currentNode != head);  
    } void add_jazza(const string& title, const string& artist, int id);

    void nextJazza() {
        if (current) {
            cout << "Now playing: " << current->title << " by " << current->artist << endl;
            current = current->next;  // Move to the next Jazza Pointer
        }
    }

   
    bool is_empty() {
        return head == nullptr;
    }
};
#endif



void GalacticPlaylistQueue::add_jazza(const string& title, const string& artist) {
        JazzaNode* newJazza = new JazzaNode(title, artist);
        if (!tail) { 
            head = tail = current = newJazza;  
        } else {
            tail->next = newJazza;
            tail = newJazza;
        }
        tail->next = head;
}

int main() {
    GalacticPlaylistQueue playlist


    // Test Case 0:
    playlist.display_playlist(); // Expected Output: No jazze in playlist...
    playlist.nextJazza(); // Expected Output: Cannot play empty playlist!

    // Test Case 1:

    playlist.add_jazza("Astro Jam", "The Martian Band");
    playlist.add_jazza("Nebula Groove", "Pluto Funk");
    playlist.add_jazza("Starship Anthem", "Nova Alliance");
    playlist.add_jazza("Hyperdrive Melody", "Andromeda Sounds");


    playlist.display_playlist(); 

    /**
         * Expected Output:
        - Astro Jam by The Martian Band
        - Nebula Groove by Pluto Funk
        - Starship Anthem by Nova Alliance
        - Hyperdrive Melody by Andromeda Sounds
         */

    
    // Test Case 2: crew wants to play jazze yoa times
    int yoa = 10;
    for (int i = 1; i < yoa; i++) {  
        playlist.nextJazza();
    }

    /**
         * Expected Output:
        Now Playing:  Astro Jam by The Martian Band (1)
        Now Playing:  Nebula Groove by Pluto Funk (2)
        Now Playing:  Starship Anthem by Nova Alliance (3)
        Now Playing:  Hyperdrive Melody by Andromeda Sounds (4)
        Now Playing:  Astro Jam by The Martian Band (5)
        Now Playing:  Nebula Groove by Pluto Funk (6)
        Now Playing:  Starship Anthem by Nova Alliance (7)
        Now Playing:  Hyperdrive Melody by Andromeda Sounds (8)
        Now Playing:  Astro Jam by The Martian Band (9)
        Now Playing:  Nebula Groove by Pluto Funk (10)
        
         */

    return 0;
}