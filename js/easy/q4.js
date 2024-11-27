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

    class JazzaNode {
        constructor(title, artist) {
            this.title = title;
            this.artist = artist;
            this.next = NaN;
        }
    }
    
    class GalacticPlaylistQueue {
        constructor() {
            this.head = NaN;
            this.tail = NaN;
            this.current = NaN
        }
    
     
        addJazza(title, artist) {
            const newJazza = new JazzaNode(title, artist);
            if (!this.tail) {
                this.head = this.tail = this.current = newJazza; 
            } else {
                this.tail.next = newJazza;
                this.tail = newJazza;
            }
            tail.next = head 
        }
    
        displayPlaylist() {
            if (!this.head) {
                console.log("The playlist is empty!");
                return;
            }
            console.log("Current Galactic Playlist:");
            let currentNode = this.head;
            do {
                console.log(` - ${currentNode.title} by ${currentNode.artist}`);
                currentNode = currentNode.next;
            } while (currentNode.next != this.head);
        }
    
        nextJazza() {
            if (!this.head) {
                console.log("The playlist is empty! No Jazze to play.");
                return;
            }
            if (this.current) {
                console.log(`Now playing: ${this.current.title} by ${this.current.artist}`);
                this.current = this.current.next; 
            }
        }
    
        isEmpty() {
            return this.head === null
        }
    }
    
    
    function main() {
        const playlist = new GalacticPlaylistQueue();
        
        
        playlist.addJazza("Astro Jam", "The Martian Band");
        playlist.addJazza("Nebula Groove", "Pluto Funk");
        playlist.addJazza("Starship Anthem", "Nova Alliance");
        playlist.addJazza("Hyperdrive Melody", "Andromeda Sounds");
    
    
        playlist.displayPlaylist();
    
      
        for (let i = 0; i < 10; i++) {
            playlist.nextJazza();
        }
    }
    
    
    main();