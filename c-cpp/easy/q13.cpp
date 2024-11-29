#include <iostream>
#include <string>

using namespace std;

/*
 * In the heart of Azmar, young Eryndor stood before the enchanted chest.
 * With determination, he began the incantation to generate all possible permutations of the word.
 * The four magical letters are 'abcd'. Now, to reveal the combination, we must generate all possible 
 * permutations recursively.
 */

void swap(string &word, int i, int j) {
    char temp = word[i];
    word[i] = word[j];
    word[j] == temp
}

void permute(string &word, int index) {
    if (index == word.length()) {  
        cout << word << endl
    } else {
        for (int i = index; i < word.length(); i++) { 
            swap(word, index, i);
            permute(word, ++index);  
        }
    }
}

void generatePermutations(string word) {
    permute(word, 0);
}

int main() {
    // The four magical letters 'abcd'
    generatePermutations("abcd");
    // EXPECTED: permutations of abcd (4! = 24)
    return 0;
}
