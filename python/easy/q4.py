"""
Welcome back, Space Engineer! Your mission, should you choose to accept it, involves aiding 
the Zafarian Space Crew aboard the Xal'tharis as they journey across the cosmos.
 The crew relies on their trusty AI to manage their Galactic Jazza Playlist, 
a circular playlist that never ends—just like their voyages through the stars.

However, the AI's code has encountered several bugs that need fixing. It’s your 
job to troubleshoot and debug the issues in the playlist system so that the crew 
can continue enjoying their intergalactic tunes.

The Galactic Playlist is implemented as a CIRCULAR LINKED LIST, 
where each song is represented by a JazzaNode, and the spaceship’s 
AI has to handle the following tasks:

1) Add a new Jazza song to the playlist (song is appended to the end of the list).

2) Display the current playlist for the crew to see, looping through all songs in the playlist.

3) Move to the next Jazza in the playlist, ensuring the song plays in a loop.

4) Ensure that the playlist functions correctly and loops back once the crew has cycled through all the songs.


Task:
Your mission is to debug the code and ensure the Jazza Playlist works as expected, 
without any crashes or errors. The playlist must loop smoothly, and the crew must be able to add, play, 
and display songs seamlessly.


Galactic Playlist of the Zafarian Star Consortium:
    Astro Jam by The Martian Band
    Nebula Groove by Pluto Funk
    Starship Anthem by Nova Alliance
    Hyperdrive Melody by Andromeda Sounds

"""
class JazzaNode:
    def __init__(title, artist, self):
        self.title = title
        self.artist = artist
        self.next = None

class GalacticPlaylistQueue:
    def __init__(self):
        self.head = None
        self.tail = None
    self.current = None  


    def add_jazza(title, artist):
        new_jazza = JazzaNode(title, artist)
        if not self.tail:
            self.head = self.tail = self.current = new_jazza
        else:
            self.tail.next = new_jazza
            self.tail = new_jazza
            self.tail.next = self.head  

    def display_playlist(self):
        print("Current Galactic Playlist:")
        current_node = self.head
        while True:
            print(f" - {current_node.title} by {current_node.artist}")
            current_node = current_node.next
            if current_node.next == self.head:
                break  

    def next_jazza(self):
        if self.current:
            print(f"Now playing: {self.current.title} by {self.current.artist}")
            self.current = self.current.next  # Move to the next Jazza

    def is_empty(self):
        return self.head is None


def main():
    playlist = GalacticPlaylistQueue()

    # Test Case 0
    playlist.display_playlist() # Expected Output: No songs in playlist.
    playlist.next_jazza() # Expected Output: cannot play in empty playlist.

    # Test Case 1
    playlist.add_jazza("Astro Jam", "The Martian Band")
    playlist.add_jazza("Nebula Groove", "Pluto Funk")
    playlist.add_jazza("Starship Anthem", "Nova Alliance")
    playlist.add_jazza("Hyperdrive Melody", "Andromeda Sounds")

    playlist.display_playlist()
    """Expected Output:
        - Astro Jam by The Martian Band
        - Nebula Groove by Pluto Funk
        - Starship Anthem by Nova Alliance
        - Hyperdrive Melody by Andromeda Sounds
    """

    # Test Case 2: Crew wants to listen to Yoa number of songs
    yoa = 10
    for  in range(yoa):
        playlist.next_jazza()

        """
        Expected Output:
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
        """


main()