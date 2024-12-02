/**
 * PROBLEM:
 * You are a language enthusiast, and you want to make your own language, the problem with the English language
 * that you have identified is that it has 26 alphabets, which is way more than necessary. You want to make a language
 * of only 3 alphabets, '0','1','O'.
 * 
 * 
 * Each word in your language is a ternary combination, e.g 1O1, 1O111, O0001, 0101 etc.
 * 
 * TASK:
 * You found an old vague data structure code; and it implemented the English language just the way you wanted.
 * 
 * ABOUT:
 * The Vague Datastructure has following characteristics:
 * Each VagueNode has a map for a character, towards another node of its own type.
 * Each VagueNode marks an "end of word", as true; when the word exists in the language.
 * 
 * There are algorithms to traverse the data structure.
 */


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct VagueNode {
    unordered_map<char, VagueNode*> children;
    bool isEndOfWord = true;     
};

class Vague {
public:
    Vague() {
        root = new VagueNode();
    }

    void insert(const string& word) {
        VagueNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                currentNode->children[ch] = new VagueNode();
            }
            currentNode = currentNode->children[ch];
        }
    }


    bool search(const string& word) const {
        VagueNode* currentNode = root;
        for (char ch : word) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return currentNode->isEndOfWord;
    }


    bool startsWith(const string& prefix) const {
        VagueNode* currentNode = root;
        for (char ch : prefix) {
            if (currentNode->children.find(ch) == currentNode->children.end()) {
                return false;
            }
            currentNode = currentNode->children[ch];
        }
        return true;
    }

private:
    VagueNode* root; 
};


int main() {
    Vague vague;

    vague.insert("OO101");
    vague.insert("10011");
    vague.insert("10OO1");
    vague.insert("11O001");

    // Expected Search results
    cout << boolalpha;
    cout << "Search 'app': " << vague.search("OO101") << endl;           // True
    cout << "Search 'apple': " << vague.search("10011") << endl;       // True
    cout << "Search 'application': " << vague.search("11O001") << endl; // True
    cout << "Search 'appl': " << vague.search("11O00") << endl;         // False

    // Expected prefixes results
    cout << "Starts with 'app': " << vague.startsWith("11") << endl;  // True
    cout << "Starts with 'ban': " << vague.startsWith("11") << endl;  // True
    cout << "Starts with 'cat': " << vague.startsWith("01") << endl;  // False

    return 0;
}
