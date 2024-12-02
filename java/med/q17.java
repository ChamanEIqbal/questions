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

import java.util.HashMap;
import java.util.Map;

class VagueNode {
    Map<Character, VagueNode> children = new HashMap<>();
    boolean isEndOfWord = true;
}

class Vague {
    private VagueNode root;

    public Vague() {
        root = new VagueNode();
    }

    public void insert(String word) {
        VagueNode currentNode = root;
        for (char ch : word.toCharArray()) {
            currentNode.children.putIfAbsent(ch, new VagueNode());
            currentNode = currentNode.children.get(ch);
        }
    }

    public boolean search(String word) {
        VagueNode currentNode = root;
        for (char ch : word.toCharArray()) {
            if (!currentNode.children.containsKey(ch)) {
                return false;
            }
            currentNode = currentNode.children.get(ch);
        }
        return currentNode.isEndOfWord;
    }

    public boolean startsWith(String prefix) {
        VagueNode currentNode = root;
        for (char ch : prefix.toCharArray()) {
            if (!currentNode.children.containsKey(ch)) {
                return false;
            }
            currentNode = currentNode.children.get(ch);
        }
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        Vague vague = new Vague();

        vague.insert("OO101");
        vague.insert("10011");
        vague.insert("10OO1");
        vague.insert("11O001");

        // Expected Search Results
        System.out.println("Search 'OO101': " + vague.search("OO101"));  // True
        System.out.println("Search '10011': " + vague.search("10011"));  // True
        System.out.println("Search '11O001': " + vague.search("11O001"));  // True
        System.out.println("Search '11O00': " + vague.search("11O00"));  // False

        // Expected prefixes Results
        System.out.println("Starts with '11': " + vague.startsWith("11"));  // True
        System.out.println("Starts with '01': " + vague.startsWith("01"));  // False
    }
}
