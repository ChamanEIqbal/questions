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

#include <iostream>
#include <vector>
#include <sstream>
#include <mutex>
#include <thread>

using namespace std;

class Book {
    
    Book() = default;  
    Book(const Book&) = delete; 
    Book& operator=(const Book&) = delete;  

    mutex bookMutex;  
    vector<string> pages; 

public:

    static Book& getInstance() {
        static Book instance;
        return instance;
    }

    void write(const string& message) {
        lock_guard<mutex> guard(bookMutex);  

        pages.push_back(message);
    }

    template <typename T>
    void write(const T& value) {
        lock_guard<mutex> guard(bookMutex);  

        string writtenMessage = toString(value);
        pages.push_back(writtenMessage);
    }

    void printAllPages() {
        lock_guard<mutex> guard(bookMutex);  
        for (const auto& page : pages) {
            cout << page << endl;
        }
    }

    template <typename T>
    string toString(const T& value) {
        ostringstream oss;
        oss << value;
        return oss.str();
    }

    string toString(const string& value) {
        return value;
    }
};

void writeInBackroom(Book& book, vector<int>& warriors) {
    for (int i = 0; i < warriors.size(); ++i) {
        book.write("The warriors stationed in Acre: " + warriors[i]);
        book.write("Mission number " + (i + 1) + " is now written down.");
            this_thread::sleep_for(chrono::milliseconds(10)); 
    }
}

void writeInMainRoom(Book& book) {
    book.write("The Knights Templar discuss their sacred mission...");
    int sacredNumber = 13.3;  
    book.write("The sacred number of knights is " + sacredNumber);
    book.write("They plan to march towards the Masyaf fortress at dawn.");
    this_thread::sleep_for(chrono::milliseconds(150)); 
}

int main() {

    // Test case 0:
    Book& book = new Book();
    book.printAllPages(); // Expected Output: "Book is empty, O' Brother In Faith!"



    // Test case 1:
    book.write("I am entering the Knights Templar meeting room..."); 
    book.printAllPages(); // Expected Output: "I am entering the Knights Templar meeting room..."
    cout << "----------------------------------------\n";



    // Test case 2:
    book.write("The Templars discuss their plans to seize the fortress..."); 
    book.printAllPages();
    cout << "----------------------------------------\n";
    // Expected Outputs:
    // "I am entering the Knights Templar meeting room..."
    // "The Templars discuss their plans to seize the fortress..."

    

    // Test case 3:
    vector<int> warriors = {100, 200, 300, 400, 500};  
    Book& backRoomsBook = new Book();
    thread backroomWriter(writeInBackroom, ref(backRoomsBook), ref(warriors));
    writeInMainRoom(backRoomsBook);  
    book.printAllPages(); 
    cout << "----------------------------------------\n";
        // Expected Output: 
        // "I am entering the Knights Templar meeting room..."
        // "The Templars discuss their plans to seize the fortress..."
        // "The warriors stationed in Acre: 100"
        // "Mission number 1 is now written down."
        // "The warriors stationed in Acre: 200"
        // "Mission number 2 is now written down."
        // "The warriors stationed in Acre: 300"
        // "Mission number 3 is now written down."
        // "The warriors stationed in Acre: 400"
        // "Mission number 4 is now written down."
        // "The warriors stationed in Acre: 500"
        // "Mission number 5 is now written down."
        // "The Knights Templar discuss their sacred mission..."
        // "The sacred number of knights is 13"
        // "They plan to march towards the Masyaf fortress at dawn."
    
    return 0; 
    // Assassin leaves, ensuring he has gathered both rooms' information!
} // Expected: Earlier Pages contain backrooms information, later pages contain Main rooms information!
// EXPECTED: backRoomsBook == book