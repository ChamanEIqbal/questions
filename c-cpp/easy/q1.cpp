#include <iostream>
#include <vector>
using namespace std;

/*
In the mystical kingdom of Eldoria, there is a dragon named Pyro who guards a treasure chest. 
The chest is locked with a secret code, and the code is a series of numbers. To unlock the chest, 
Pyro must navigate through a labyrinth of number sequences to find the treasure. Each number represents 
a clue, and Pyro must decide whether to go left or right based on the numbers in the sequence. If Pyro 
encounters a number smaller than a certain value, it must go left; otherwise, it goes right.

Your task is to help Pyro find the correct path to the treasure using the Binary Search algorithm.
*/

string findTreasure(vector<int>& clueSequence, int treasureCode) {
    int left = 0;
    int right = clueSequence.size() - 1;

    while (left < right) {
        int middle = (left + right) / 2;
        if (clueSequence[middle] == treasureCode) {
            return "Treasure found at index " + to_string(middle) + "!";
        } else if (clueSequence[middle] < treasureCode) {
            left = middle - 1;
        } else {
            right = middle + 1;
        }
    }
    return "Treasure not found!";
}

int main() { // Test cases
    vector<int> clueSequence1 = {}; // Test case for empty clue sequence
    vector<int> clueSequence2 = {1, 2, 3, 4, 5}; // Test case where treasure is not found
    vector<int> clueSequence3 = {1, 2, 3, 4, 5}; // Test case where treasure is found

    cout << findTreasure(clueSequence1, 3) << endl; // Expected Output: Empty clue sequence
    cout << findTreasure(clueSequence2, 6) << endl; // Expected Output: Treasure not found
    cout << findTreasure(clueSequence3, 3) << endl; // Expected Output: Treasure found

    return 0;
}
