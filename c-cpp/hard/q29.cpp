/*
You are tasked to implement a directory management system using a tree structure, 
where each directory can contain subdirectories and files. 

Operations include creating directories, adding files, deleting directories or files, and displaying the directory structure as a tree.

Make sure to see test cases.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string name;
    bool isFile;
    vector<Node*> children;

    Node(string name, bool isFile) : name(name), isFile(isFile) {}
};

class FileSystem {
private:
    Node* root;
    Node* current;

public:
    FileSystem() {
        root = new Node("/", false);
        current = root;
    }

    void createDirectory(const string& dirName) {
        current->children.push_back(new Node(dirName, false)); 
        cout << "Directory created: " << dirName << endl;
    }

    void addFile(const string& fileName) {
        current->children.push_back(new Node(fileName, true)); 
        cout << "File added: " << fileName << endl;
    }

    void deleteEntry(const string& name) {
        for (auto it = current->children.begin(); it != current->children.end(); ++it) {
            if ((*it)->name == name && (*it)->isFile) {
                delete *it; 
                current->children.erase(it);
                cout << "Entry deleted: " << name << endl;
                return;
            }
        }
        cout << "Entry not found: " << name << endl;
    }

    void changeDirectory(const string& dirName) {
        for (Node* child : current->children) {
            if (child->name == dirName && !child->isFile) {
                current = child;
                cout << "Changed directory to: " << dirName << endl;
                return;
            }
        }
        cout << "Directory not found: " << dirName << endl;
    }

    void displayTree(Node* node, int depth = 0) {
        cout << string(depth, '-') << node->name << endl; 
        for (Node* child : node->children) {
            displayTree(child, depth + 1); 
        }
    }

    void display() {
        displayTree(current);
    }

    ~FileSystem() {
        deleteTree(root); 
    }

private:
    void deleteTree(Node* node) {}
};

int main() {
    FileSystem fs;

    cout << "\nTest Case 1: Create Directories and Display" << endl;
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
    // Bug: Indentation is incorrect.

    cout << "\nTest Case 2: Add Files and Display" << endl;
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
    // Bug: No distinction between directories and files in the display output.

    cout << "\nTest Case 3: Create Duplicate Entries" << endl;
    fs.createDirectory("Dir1");
    fs.addFile("File1.txt");
    fs.display();
    // Expected Output:
    // Duplicate directory/file names should not be allowed.
    // Actual Output:
    // Duplicate entries are created.
    // Bug: The code does not check for duplicate names.

    cout << "\nTest Case 4: Delete Directory" << endl;
    fs.deleteEntry("Dir1");
    fs.display();
    // Expected Output:
    // /
    // -Dir2
    // -[File] File1.txt
    // -[File] File2.txt
    // Actual Output:
    // Entry not found: Dir1
    // Bug: The delete logic does not handle directories.

    cout << "\nTest Case 5: Change Directory" << endl;
    fs.changeDirectory("Dir2");
    fs.createDirectory("SubDir1");
    fs.display();
    // Expected Output:
    // Dir2
    // -SubDir1
    // Actual Output:
    // Dir2
    // SubDir1
    // Bug: Indentation is incorrect.


    cout << "\nTest Case 6: Memory Management" << endl;
    // Manually simulate end of the program and check memory leaks.
    // Expected Output:
    // All dynamically allocated memory should be freed.
    // Actual Outcome:
    // Memory leak occurs as `deleteTree` is not implemented.
}
