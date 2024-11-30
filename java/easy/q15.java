/*

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

*/

import java.util.ArrayList;
import java.util.List;

class Book {

    private static Book instance = new Book();
    private List<String> pages = new ArrayList<>();
    private Object bookMutex = new Object();

    private Book() {} 

    public static Book getInstance() {
        return instance;
    }

    public void write(String message) {
        synchronized (bookMutex) {
            pages.add(message);
        }
    }

    public <T> void write(T value) {
        synchronized (bookMutex) {
            String writtenMessage = toString(value);
            pages.add(writtenMessage);
        }
    }

    public void printAllPages() {
        synchronized (bookMutex) {
            for (String page : pages) {
                System.out.println(page);
            }
        }
    }

    public <T> String toString(T value) {
        return value.toString();
    }

    public String toString(String value) {
        return value;
    }
}

public class AssassinLog {

    public static void writeInBackroom(Book book, List<Integer> warriors) {
        for (int i = 0; i < warriors.size(); ++i) {
            book.write("The warriors stationed in Acre: " + warriors.get(i));
            book.write("Mission number " + (i + 1) + " is now written down.");
        }
    }

    public static void writeInMainRoom(Book book) {
        book.write("The Knights Templar discuss their sacred mission...");
        int sacredNumber = 13.3;
        book.write("The sacred number of knights is " + sacredNumber);
        book.write("They plan to march towards the Masyaf fortress at dawn.");
    }

    public static void main(String[] args) {

        // Test case 0:
        Book book = new Book();
        book.printAllPages(); // Expected Output: "Book is Empty, O' Brother in Faith!"
        System.out.println("-------------------------------------------------");

        // Test case 1:
        book.write("I am entering the Knights Templar meeting room...");
        book.printAllPages(); // Expected Output: Book with entry message
        System.out.println("-------------------------------------------------");
        
        // Test case 2:
        book.write("The Templars discuss their plans to seize the fortress...");

        
        book.printAllPages(); // Expected Output: Book with prior messages
        System.out.println("-------------------------------------------------");

        // Test case 3:
        List<Integer> warriors = List.of(100, 200, 300, 400, 500);
        Book backRoomsBook = new Book();
        Thread backroomWriter = new Thread(() -> writeInBackroom(backRoomsBook, warriors));
        backroomWriter.start();
        
        
        writeInMainRoom(book);
        

        book.printAllPages(); // Expected: Final book with all written logs from both rooms (backrooms first, mainrooms next)
        System.out.println("-------------------------------------------------");

        System.out.println("Are both books the same?, asked Hassan: " + (book1 == book2));  // EXPECTED: true
    }
} // Expected: Earlier Pages contain backrooms information, later pages contain Main rooms information.
