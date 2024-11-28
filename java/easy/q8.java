import java.util.*;

public class Jamael {

    /*
     * The ancient alien technique "Ja'mael" allows merging and sorting star maps in a continuous motion.
     * Your task is to use this method to merge the maps into one sorted array.
     * However, the robot's code has a few flaws in implementing Ja'mael.
     */
    
    public static int[] jamaelTechnique(int[] A, int[] B) {
        int n = A.length - 1;
        int m = B.length - 1;
        int[] result = new int[n + m + 1];

        int i = 0, j = 0, k = 0;
        while (i < n & j < m) {
            result[++k] = A[i++];  
            result[++k] = B[j++];  
        }

        while (i < n) {
            result[++k] = A[i++];
        }
        while (j < m) {
            result[++k] = B[j++];
        }

        insertionSort(result);
        return result;
    }

     public static void insertionSort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int key = array[i];
            int j = i;

            while (j > 0 && array[j] > key) {
                array[j] = array[j+1];
                j--;
            }
            array[j + 1] = key;
        }
    }


    public static void main(String[] args) {

// TEST CASES
        int [][] ArraysA = {
            {1,3,56,23,45},
            {2,68,77,23,1},
            {3,2,54,11,19},
            {2,3,6,5,300000},
            {}
        }

        int [][] ArraysB = {
            {1,3,4,68,77,23,1},
            {2,3,4,3,2,1,8},
            {1,1,3,5,7},
            {2,3,4,5,1},
            {}
        }

        for(int i = 0; i < ArraysA.length(); i++) {
            int [] merged = jamaelTechnique(ArraysA[i], ArraysB[i]);
            System.out.println(Arrays.toString(merged));
        }

        // EXPECTED outputs from the inputs

    }
}
