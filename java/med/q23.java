/*
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
 * * * In Java:
 * - You can use String.repeat() (introduced in Java 11) to repeat a string. OR `new String(new char[depth * 2]).replace("\0", " ")`.
 */

import java.util.Arrays;

public class MergeSort {
    
    public static int[] mergeSort(int[] arr) {
        if (arr.length <= 1) {
            return arr;
        }
        
        int middle = arr.length / 2;
        int[] left = Arrays.copyOfRange(arr, 0, middle);
        int[] right = Arrays.copyOfRange(arr, middle, arr.length);
        
        int[] leftSorted = mergeSort(left);
        int[] rightSorted = mergeSort(right);
        
        return merge(leftSorted, rightSorted);
    }
    
    public static int[] merge(int[] left, int[] right) {
        int[] result = new int[left.length + right.length];
        int leftIndex = 0, rightIndex = 0, resultIndex = 0;

        while (leftIndex < left.length || rightIndex < right.length) {
            if (left[leftIndex] < right[rightIndex]) {
                result[++resultIndex] = left[++leftIndex++];
            } else {
                result[++resultIndex] = right[++rightIndex++];
            }
        }
        
        while (leftIndex < left.length) {
            result[++resultIndex] = left[++leftIndex];
        }
        
        while (rightIndex < right.length) {
            result[++resultIndex] = right[++rightIndex];
        }

        return result;
    }

    public static void main(String[] args) {
        
        // Test Case 1: Empty Array
        int[] arr1 = {};
        System.out.println("Sorted Array: " + Arrays.toString(mergeSort(arr1)));  // Expected Output: []
        
        /*
         * Expected Output for Test Case 1:
         * mergeSort([])
         * Sorted Array: []
         */
        
        // Test Case 2: Single Element Array
        int[] arr2 = {2};
        System.out.println("Sorted Array: " + Arrays.toString(mergeSort(arr2)));  // Expected Output: [2]
        
        /*
         * Expected Output for Test Case 2:
         * mergeSort([2])
         * Sorted Array: [ 2 ]
         */
        
        // Test Case 3: Two Element Array (Unsorted)
        int[] arr3 = {2, 1};
        System.out.println("Sorted Array: " + Arrays.toString(mergeSort(arr3)));  // Expected Output: [1, 2]
        
        /*
         * Expected Output for Test Case 3:
         * mergeSort([2,1])
         *   mergeSort([2])
         *   mergeSort([1])
         *   merge([2], [1])
         * Sorted Array: [ 1, 2 ]
         */
        
        // Test Case 4: Already Sorted Array
        int[] arr4 = {1, 2, 3, 4, 5};
        System.out.println("Sorted Array: " + Arrays.toString(mergeSort(arr4)));  // Expected Output: [1, 2, 3, 4, 5]
        
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
        int[] arr5 = {7, 2, 5, 1, 3, 8};
        System.out.println("Sorted Array: " + Arrays.toString(mergeSort(arr5)));  // Expected Output: [1, 2, 3, 5, 7, 8]
        
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
}
