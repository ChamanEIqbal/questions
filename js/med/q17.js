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
class VagueNode {
    constructor() {
        this.children = {};
        this.isEndOfWord = true;
    }
}

class Vague {
    constructor() {
        this.root = new VagueNode();
    }

    insert(word) {
        let currentNode = this.root;
        for (const char of word) {
            if (!currentNode.children[char]) {
                currentNode.children[char] = new VagueNode();
            }
            currentNode = currentNode.children[char];
        }
    }

    search(word) {
        let currentNode = this.root;
        for (const char of word) {
            if (!currentNode.children[char]) {
                return false;
            }
            currentNode = currentNode.children[char];
        }
        return currentNode.isEndOfWord;
    }

    startsWith(prefix) {
        let currentNode = this.root;
        for (const char of prefix) {
            if (!currentNode.children[char]) {
                return false;
            }
            currentNode = currentNode.children[char];
        }
        return true;
    }
}

function testCases() {
const vague = new Vague();


vague.insert("OO101");
vague.insert("10011");
vague.insert("10OO1");
vague.insert("11O001");
vague.insert ("abcd"); // Expected Output: cannot add English Alphabets!

// Expected search results
console.log("Search 'OO101':", vague.search("OO101"));  // True
console.log("Search '10011':", vague.search("10011"));  // True
console.log("Search '11O001':", vague.search("11O001"));  // True
console.log("Search '11O00':", vague.search("11O00"));  // False

// Expected prefixes results
console.log("Starts with '11':", vague.startsWith("11"));  // True
console.log("Starts with '01':", vague.startsWith("01"));  // False
} // Test cases;

testCases();