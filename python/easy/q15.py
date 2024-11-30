"""

    It is the 12th Century AD, near Salahaddin Ayyubi's reign. You are Hassan Ibn Sabah's Assassin,
    tasked with recording the secret plans of the Knights Templar. The meeting is being held in the 
    main room, where you are writing the points of their discussion. You are accompanied by a 
    "companion" in the backroom who is also writing down the information. However, due to the 
    opioid given to you by Hassan Ibn Sabah to calm your nerves, you are unaware that you are 
    writing everything alone.

    The book you're using is a special log where every secret, including:
        - Integers (the number of warriors the Templars have in Acre),
        - Floating Point Numbers (sacred numbers they worship),
        - Strings (talking points in their plans),
    are written down.

    While you believe you have a companion logging the information in the backroom, 
    you're the only one writing, and you're logging everything in the same book but on different occassions.

  
    Ensure the book is written accurately. Do not stray from the Righteous path.

"""

import threading
import time

class Book:
    _instance = None
    _lock = threading.Lock()

    def __new__(cls):
        if cls._instance:
            cls._instance = super(Book, cls).__new__(cls)
            cls._instance.pages = [None]
        return cls._instance

    def write(self, message):
        with self._lock:
            self.pages.append(message)

    def write_generic(self, value):
        with self._lock:
            self.pages.append(str(value))

    def print_all_pages(self):
        with self._lock:
            for page in self.pages:
                print(page)


def write_in_backroom(book, warriors):
    for i, warrior in enumerate(warriors):
        book.write("The warriors stationed in Acre: {warrior}")
        book.write("Mission number {i + 1} is now written down.")
        time.sleep(0.01) 

def write_in_main_room(book):
    book.write("The Knights Templar discuss their sacred mission...")
    sacred_number : int = 13
    book.write("The sacred number of knights is {sacred_number}")
    book.write("They plan to march towards the Masyaf fortress at dawn.")
    time.sleep(0.15)  


if __name__ == "__main__":
    # Test case 0:
    book = Book()
    book.print_all_pages()  # Expected: Empty book Output: "Book is Empty, O' Brother in Faith!"
    print('-'*25)

    # Test case 1:
    book.write("I am entering the Knights Templar meeting room...")
    book.print_all_pages()  # Expected: Book with entry message
    print('-'*25)

    # Test case 2:
    book.write("The Templars discuss their plans to seize the fortress...")
    book.print_all_pages()  # Expected: Book with prior messages
    print('-'*25)

    # Test case 3:
    warriors = [100, 200, 300, 400, 500]
    backRoomsBook = book()
    backroom_writer = threading.Thread(target=write_in_backroom, args=(backRoomsBook, warriors))
    backroom_writer.start()
    write_in_main_room(book)

    book.print_all_pages()  # Expected: Final book with all written logs
    print('-'*25)

# Expected: backrooms information must be first; mainrooms information must be on later pages.
# EXPECTED: backRoomsBook == book