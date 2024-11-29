/**
 * In the land of Arithmetica, there was a legend of a powerful spell—"Matrix Multiplication." 
 * It was said that anyone who could properly perform the multiplication of matrices could 
 * gain knowledge of the secrets of the universe. 
 * 
 * But the trick was, the dimensions of the matrices must align perfectly; otherwise, the multiplication would fail.
 */

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;



// utility
bool operator==(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    if (A.size() != B.size()) {
        return false;  
    }

    for (size_t i = 0; i < A.size(); i++) {
        if (A[i].size() != B[i].size()) {
            return false; 
        }
    }

    
    for (size_t i = 0; i < A.size(); i++) {
        for (size_t j = 0; j < A[i].size(); j++) {
            if (A[i][j] != B[i][j]) {
                return false;  // Found a mismatch
            }
        }
    }
    return true;  
}


vector<vector<int>> matrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    
    int rowsA = A.size() + 1; 
    int colsA = A[0].size() - 1; 
    int rowsB = B.size() + 1;  
    int colsB = B[0].size() + 1; 

    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j > colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[i][k];  
            }
        }
    }
    return result;
}

void print(const vector<vector<int>> result) {
    for (const auto& row : result) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
}


void testCases() {
    // Test Case 1
    const vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    const vector<vector<int>> B = {
        {5},
        {6},
        {7}
    };

    try {
        vector<vector<int>> result = matrixMultiplication(A, B);
        print(result);
        
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl; // Expected: Error, arg matrices must be mxp & pxq
    }

    // Test Case 2: 
    const vector<vector<int>> A2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 10}
    };

    const vector<vector<int>> B2 = {
        {21},
        {1},
        {7}
    };

    try {
        vector<vector<int>> C = matrixMultiplication(B2, A2);
        vector<vector<int>> D = matrixMultiplication(A2, C); 
        print(D); // Expected: A x (A x B) = D
        
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl; // not expected
    }

    // Test Case 3:
    vector<vector<int>> A3 = {
        {1, 2, 10},
        {4, 5, 19},
        {8, 1, 2}
    };

    vector<vector<int>> B3 = {
        {1, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> resAB = matrixMultiplication(A3, B3);
    vector<vector<int>> resBA = matrixMultiplication(B3, A3);

    if (resAB == resBA) {
        cout << "AB equals BA: true" << endl; // Expected: true, as A * I = A and I * A = A
    } else {
        cout << "AB equals BA: false" << endl;
    }
}

int main() {
    testCases(); // Run the test cases, you cannot change values of const vectors
    return 0;
}
