/*
You are tasked to implement a directory management system using a tree structure, 
where each directory can contain subdirectories and files. 

Operations include creating directories, adding files, deleting directories or files, and displaying the directory structure as a tree.

Make sure to see test cases.
*/

class Node {
    constructor(name, isFile) {
        this.name = name;
        this.isFile = isFile;
        this.children = [];
    }
}

class FileSystem {
    constructor() {
        this.root = new Node("/", false);
        this.current = this.root;
    }

    createDirectory(dirName) {
        this.current.children.push(new Node(dirName, false));
        console.log(`Directory created: ${dirName}`);
    }

    addFile(fileName) {
        this.current.children.push(new Node(fileName, true));
        console.log(`File added: ${fileName}`);
    }

    deleteEntry(name) {
        const index = this.current.children.findIndex(
            (child) => child.name === name && child.isFile
        );
        if (index !== -1) {
            this.current.children.splice(index, 1);
            console.log(`Entry deleted: ${name}`);
        } else {
            console.log(`Entry not found: ${name}`);
        }
    }

    changeDirectory(dirName) {
        const found = this.current.children.find(
            (child) => child.name === dirName && !child.isFile
        );
        if (found) {
            this.current = found;
            console.log(`Changed directory to: ${dirName}`);
        } else {
            console.log(`Directory not found: ${dirName}`);
        }
    }

    displayTree(node = this.current, depth = 0) {
        console.log("-".repeat(depth) + node.name);
        for (const child of node.children) {
            this.displayTree(child, depth + 1);
        }
    }

    display() {
        this.displayTree();
    }
}

// Test Cases
const fs = new FileSystem();

console.log("\nTest Case 1: Create Directories and Display");
fs.createDirectory("Dir1");
fs.createDirectory("Dir2");
fs.display();
// Expected Output:
// /
// -Dir1
// -Dir2
// Actual Output:
// /
// Dir1
// Dir2


console.log("\nTest Case 2: Add Files and Display");
fs.addFile("File1.txt");
fs.addFile("File2.txt");
fs.display();
// Expected Output:
// /
// -Dir1
// -Dir2
// -[File] File1.txt
// -[File] File2.txt
// Actual Output:
// /
// Dir1
// Dir2
// File1.txt
// File2.txt


console.log("\nTest Case 3: Create Duplicate Entries");
fs.createDirectory("Dir1");
fs.addFile("File1.txt");
fs.display();
// Expected Output:
// Duplicate directory/file names should not be allowed.
// Actual Output:
// Duplicate entries are created.


console.log("\nTest Case 4: Delete Directory");
fs.deleteEntry("Dir1");
fs.display();
// Expected Output:
// /
// -Dir2
// -[File] File1.txt
// -[File] File2.txt
// Actual Output:
// Entry not found: Dir1


console.log("\nTest Case 5: Change Directory");
fs.changeDirectory("Dir2");
fs.createDirectory("SubDir1");
fs.display();
// Expected Output:
// Dir2
// -SubDir1
// Actual Output:
// Dir2
// SubDir1


console.log("\nTest Case 6: Memory Management");
// Expected Output:
// Manually simulate the end of the program and ensure there are no dangling references.
// Actual Outcome:
// Memory leaks are possible as there is no mechanism to release references.
