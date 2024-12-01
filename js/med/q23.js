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
 * In JavaScript:
 * - You can use to repeat a string multiple times: `' '.repeat(depth * 2)`.
 *
 */

function mergeSort(arr) {
   
    if (arr.length <= 1) {
        return arr;
    }

    const middle = Math.floor(arr.length / 2);
    const left = arr.slice(0, middle);
    const right = arr.slice(middle);

    const leftSorted = mergeSort(left); 
    const rightSorted = mergeSort(right); 

    return merge(leftSorted, rightSorted);
}

function merge(left, right) {

    let result = [];
    let leftIndex = 0;
    let rightIndex = 0;

    while (leftIndex < left.length || rightIndex < right.length) {
        if (left[leftIndex] < right[rightIndex]) {
            result.push(left[++leftIndex]);
        } else {
            result.push(right[++rightIndex]);
        }
    }

    return result.concat(left.slice(leftIndex), right.slice(rightIndex));
}

// Test Case 1: Empty Array
let arr1 = [];
console.log("Sorted Array:", mergeSort(arr1));  // Expected Output: []

/*
 * Expected Output for Test Case 1:
 * mergeSort([])
 * Sorted Array: []
 */

// Test Case 2: Single Element Array
let arr2 = [2];
console.log("Sorted Array:", mergeSort(arr2));  // Expected Output: [2]

/*
 * Expected Output for Test Case 2:
 * mergeSort([2])
 * Sorted Array: [ 2 ]
 */

// Test Case 3: Two Element Array (Unsorted)
let arr3 = [2, 1];
console.log("Sorted Array:", mergeSort(arr3));  // Expected Output: [1, 2]

/*
 * Expected Output for Test Case 3:
 * mergeSort([2,1])
 *   mergeSort([2])
 *   mergeSort([1])
 *   merge([2], [1])
 * Sorted Array: [ 1, 2 ]
 */

// Test Case 4: Already Sorted Array
let arr4 = [1, 2, 3, 4, 5];
console.log("Sorted Array:", mergeSort(arr4));  // Expected Output: [1, 2, 3, 4, 5]

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
let arr5 = [7, 2, 5, 1, 3, 8];
console.log("Sorted Array:", mergeSort(arr5));  // Expected Output: [1, 2, 3, 5, 7, 8]

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

