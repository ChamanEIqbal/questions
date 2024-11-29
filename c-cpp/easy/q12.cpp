/*
In a small village, there was a riddle passed down through generations:
If two words are anagrams of each other, they contain the exact same letters
but arranged in a different order. A young traveler, Alex, sought to prove
his intelligence by solving this puzzle.

But Alex, in his naivety; forgot that words can't be anagrams when they are
not of the same length...

The challenge is simple: check if two words are anagrams of each other. Correct Alex!
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<char>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {  
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

bool areArraysEqual(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[size-i]) {
            return false;
        }
    }
    return true;
}

bool isAnagram(string str1, string str2) {
    
    vector<char> arr1(str1.begin(), str1.end());
    vector<char> arr2(str2.begin(), str2.end());

    bubbleSort(arr1);
    bubbleSort(arr2);

    int size = sizeof(arr1)/sizeof(int);
    return areArraysEqual(arr1, arr2, size);
}

int main() {
    cout << isAnagram("listen", "silent") << endl;  // Expected: 1 (true)
    cout << isAnagram("hello", "world") << endl;    // Expected: 0 (false)
    cout << isAnagram("hello ", "ohell") << endl;   // Expected: 0 (false)
    return 0;
}
