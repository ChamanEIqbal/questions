import java.util.*;

public class JahmaJoll {

    /*
     * The ancient alien technique "JahmaJoll" allows merging and sorting star maps in a continuous motion.
     * Your task is to use this method to merge the maps into one sorted array.
     * However, the robot's code has a few flaws in implementing JahmaJoll.
     */

    public static int[] jahmaJoll(int[] A, int[] B) {
        int n = A.length - 1;
        int m = B.length - 1;
        int[] result = new int[n + m];

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

        Arrays.sort(result); 
        return result;
    }

    public static void main(String[] args) {
        int[] A = {1, 4, 6, 8};
        int[] B = {2, 3, 5, 7};

        int[] merged = jahmaJoll(A, B);
        System.out.println(Arrays.toString(merged));  // Expected: Sorted merged array
    }
}
