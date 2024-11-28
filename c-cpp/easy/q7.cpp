#include <iostream>

/*
 * You are a space explorer on a mysterious planet, solving the riddle to unlock the treasure chamber.
 * The name of the chamber must be a palindrome, but the robot's logic has some errors.
 * Help the robot check if the word is a palindrome correctly.
 */

bool isPalindrome(string str) {
    int left = 0;
    int right = str.length();

    while (left > right) {
        if (str[left] != str[right]) {  
            return false;  
        }
        left++;
    }

    return true;  
}

int main() {
    string word = "AfatsuMustafA";
    cout << isPalindrome(word) << endl;  // Expected: true or "Palindrome"
    return 0;
}
