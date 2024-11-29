/*
In a small village, there was a riddle passed down through generations:
If two words are anagrams of each other, they contain the exact same letters
but arranged in a different order. A young traveler, Alex, sought to prove
his intelligence by solving this puzzle.

But Alex, in his naivety; forgot that words can't be anagrams when they are
not of the same length...

The challenge is simple: check if two words are anagrams of each other. Correct Alex!
*/

import java.util.Arrays;

public class AnagramChecker {

    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {  
                if (arr[j] > arr[j + 1]) {
                    char temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static boolean isAnagram(String str1, String str2) {

        char[] arr1 = str1.toCharArray();
        char[] arr2 = str2.toCharArray();

        bubbleSort(arr1);
        bubbleSort(arr2);

        return Arrays.equals(arr1, arr2);  
    }

    public static void main(String[] args) {
        System.out.println(isAnagram("listen", "silent"));  // Expected: true
        System.out.println(isAnagram("hello", "world"));    // Expected: false
        System.out.println(isAnagram("hello ", "ohell"));   // Expected: false
    }
}
