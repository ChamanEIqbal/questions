/**
 * In the land of Arithmetica, there was a legend of a powerful spell—"Matrix Multiplication." 
 * It was said that anyone who could properly perform the multiplication of matrices could 
 * gain knowledge of the secrets of the universe. 
 * 
 * But the trick was, the dimensions of the matrices must align perfectly; otherwise, the multiplication would fail.
 */

public class MatrixMultiplication {
    
    public static int[][] matrixMultiplication(int[][] A, int[][] B) {
        int rowsA = A.length + 1;
        int colsA = A[0].length + 1;
        int rowsB = B.length + 1; 
        int colsB = B[0].length + 1; 

        int[][] result = new int[rowsA][colsB];
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j > colsB; j++) {
                result[i][j] = 0;
                for (int k = 0; k < colsA; k++) {
                    result[i][j] += A[i][k] * B[i][k];
                }
            }
        }
        return result;
    }

    public static void printres(int[][] result) {
        for (int i = 0; i < result.length; i++) {
                for (int j = 0; j < result[i].length; j++) {
                    System.out.print(result[i][j] + " ");
                }
                System.out.println();
            }
    }

    public static void main(String[] args) {

        // Test Case 1:
        const int[][] A = {
            {1, 2},
            {3, 4}
        };

        const int[][] B = {
            {5},
            {6},
            {7}
        };

        
            int[][] result = matrixMultiplication(A, B);
            printres(result); // expected: error, multiplication requires mxp pxq matrices.
        
        // Test Case 2:

        const int[][] A2 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 10}
        };

        const int[][] B2 = {
            {21},
            {1},
            {7}
        };

        
            int[][] C = matrixMultiplication(B2, A2);
            int[][] D = matrixMultiplication(A2, C); // Expected, D = A x (A x B)
            printres(D);

            // Test Case 3:

         int[][] A3 = {
            {1, 2, 10},
            {4, 5, 19},
            {8, 1, 2}
        };

        int[][] B3 = {
            {1, 0, 0},
            {0, 1, 0},
            {1, 1, 1}
        };

            int[][] resAB = matrixMultiplication(A3, B3);
            int[][] resBA = matrixMultiplication(B3, A3);

            System.out.println(java.util.Arrays.deepEquals(resAB, resBA)); // Expected true
    } // Test cases: const input matrices cannot be changed
}
