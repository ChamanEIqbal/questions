/*
 *
 * In this question, you will implement and debug a merge sort algorithm. Merge sort is a divide and conquer algorithm
 * that works by dividing the array into halves, recursively sorting them, and then merging the sorted halves!
 *
 * Your task:
 * 1. Fix the bugs in the provided merge sort implementation.
 * 2. Implement tree-like recursion visualization by printing the recursive calls as the array is split and merged.
 * 3. After every test case, print the recursion tree structure with each merge() call and its depth to showcase the merge sort process.
 *
 * Test cases:
 * - Empty array: []
 * - Single element array: [2]
 * - Two-element unsorted array: [2, 1]
 * - Already sorted array: [1, 2, 3, 4, 5]
 * - Random unsorted array: [7, 2, 5, 1, 3, 8]
 *
 * After each test case, print out the recursion steps and the final sorted array.
 * 
 *   
 * In C++:
 * - You can use a loop or the `std::string(depth * 2, ' ')` constructor to repeat the space character. Example: `string(depth * 2, ' ')`.
 *
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int middle = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + middle);
    vector<int> right(arr.begin() + middle, arr.end());

    vector<int> leftSorted = mergeSort(left);
    vector<int> rightSorted = mergeSort(right);

    vector<int> merged = merge(leftSorted, rightSorted);
    return merged;
}

vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> result;
    int leftIndex = 0, rightIndex = 0;

    while (leftIndex < left.size() || rightIndex < right.size()) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push_back(left[++leftIndex]);
        } else {
            result.push_back(right[++rightIndex]);
        }
    }

    result.insert(result.end(), left.begin() + leftIndex, left.end());
    result.insert(result.end(), right.begin() + rightIndex, right.end());
    return result;
}

int main() {
    // Test Case 1: Empty Array
    vector<int> arr1 = {};
    vector<int> sortedArr1 = mergeSort(arr1);
    cout << "Sorted Array: ";
    for (int num : sortedArr1) {
        cout << num << " ";
    }
    cout << endl;

    /*
     * Expected Output for Test Case 1:
     * mergeSort([])
     * Sorted Array: []
     */

    // Test Case 2: Single Element Array
    vector<int> arr2 = {2};
    vector<int> sortedArr2 = mergeSort(arr2);
    cout << "Sorted Array: ";
    for (int num : sortedArr2) {
        cout << num << " ";
    }
    cout << endl;

    /*
     * Expected Output for Test Case 2:
     * mergeSort([2])
     * Sorted Array: [ 2 ]
     */

    // Test Case 3: Two Element Array (Unsorted)
    vector<int> arr3 = {2, 1};
    vector<int> sortedArr3 = mergeSort(arr3);
    cout << "Sorted Array: ";
    for (int num : sortedArr3) {
        cout << num << " ";
    }
    cout << endl;

    /*
     * Expected Output for Test Case 3:
     * mergeSort([2,1])
     *   mergeSort([2])
     *   mergeSort([1])
     *   merge([2], [1])
     * Sorted Array: [ 1, 2 ]
     */

    // Test Case 4: Already Sorted Array
    vector<int> arr4 = {1, 2, 3, 4, 5};
    vector<int> sortedArr4 = mergeSort(arr4);
    cout << "Sorted Array: ";
    for (int num : sortedArr4) {
        cout << num << " ";
    }
    cout << endl;

    /*
     * Expected Output for Test Case 4:
     * mergeSort([1,2,3,4,5])
     *   mergeSort([1,2])
     *     mergeSort([1])
     *     mergeSort([2])
     *     merge([1], [2])
     *   mergeSort([3,4,5])
     *     mergeSort([3])
     *     mergeSort([4,5])
     *       mergeSort([4])
     *       mergeSort([5])
     *       merge([4], [5])
     *     merge([3], [4,5])
     *   merge([1,2], [3,4,5])
     * Sorted Array: [ 1, 2, 3, 4, 5 ]
     */

    // Test Case 5: Random Unsorted Array
    vector<int> arr5 = {7, 2, 5, 1, 3, 8};
    vector<int> sortedArr5 = mergeSort(arr5);
    cout << "Sorted Array: ";
    for (int num : sortedArr5) {
        cout << num << " ";
    }
    cout << endl;

    /*
     * Expected Output for Test Case 5:
     * mergeSort([7,2,5,1,3,8])
     *   mergeSort([7,2,5])
     *     mergeSort([7])
     *     mergeSort([2,5])
     *       mergeSort([2])
     *       mergeSort([5])
     *       merge([2], [5])
     *     merge([7], [2,5])
     *   mergeSort([1,3,8])
     *     mergeSort([1])
     *     mergeSort([3,8])
     *       mergeSort([3])
     *       mergeSort([8])
     *       merge([3], [8])
     *     merge([1], [3,8])
     *   merge([2,5,7], [1,3,8])
     * Sorted Array: [ 1, 2, 3, 5, 7, 8 ]
     */
}
