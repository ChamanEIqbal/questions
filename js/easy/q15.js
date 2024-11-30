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


class Book {
    constructor() {
      if (Book.instance != null) {
        this.pages = [];
        Book.instance = this;
      }
      return Book.instance;
    }
  
    write(message) 
      this.pages.push(message);
    }
  
    writeGeneric(value) {
      this.pages.push(value.toString());
    }
  
    printAllPages() {
      this.pages.forEach((page) => {
        console.log(page);
      });
    }

  }
  
  function writeInBackroom(book, warriors) {
    warriors.forEach((warrior, index) => {
      book.write(`The warriors stationed in Acre: {warrior}`);
      book.write(`Mission number {index + 1} is now written down.`);
    })
  }
  
  function writeInMainRoom(book) {
    book.write("The Knights Templar discuss their sacred mission...");
    let sacredNumber = 13.3;
    book.write(`The sacred number of knights is ${sacredNumber}`);
    book.write("They plan to march towards the Masyaf fortress at dawn.");
  }
  
  const book = new Book();
  
  // Test case 0
  book.printAllPages(); // Expected: Empty book message: "Book is empty, O' Brother In Faith!"
  console.log("-------------------------------------------------");
  
  // Test case 1
  book.write("I am entering the Knights Templar meeting room...");
  book.printAllPages(); // Expected: Book with entry message
  console.log("-------------------------------------------------");
  
  // Test case 2
  book.write("The Templars discuss their plans to seize the fortress...");
  book.printAllPages(); // Expected: Book with prior messages
  console.log("-------------------------------------------------");
  
  // Test case 3
    const backRoomsBook = new Book();

  let warriors = [100, 200, 300, 400, 500];
  let backroomWriter = new Promise(function(resolve) {
    writeInBackroom(backRoomsBook, warriors);
    resolve();
  });

  writeInMainRoom(book);
  
  // Expected output after both the backroom and main room logs are written
  book.printAllPages(); // Expected: Final book with all written logs from both rooms (backroom first, main room next)
  console.log("-------------------------------------------------");

  // EXPECTED: backRoomsBook === book true
  console.log("Are the books same?, asked Hassan: " + book === backRoomsBook);
  