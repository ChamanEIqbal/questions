
/*
     * The ancient alien technique "Ja'mael" allows merging and sorting star maps in a continuous motion.
     * Your task is to use this method to merge the maps into one sorted array.
     * However, the robot's code has a few flaws in implementing Ja'mael.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> jamaelTechnique(vector<int>& A, vector<int>& B) {
    int n = A.size() - 1; 
    int m = B.size() - 1; 
    vector<int> result(n + m + 1);

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

    sort(result.begin(), result.end());
    return result;
}

void insertionSort(vector<int>& array) {
    for (int i = 0; i < array.size(); i++) { 
        int key = array[i];
        int j = i;

        while (j > 0 && array[j] > key) {
            array[j] = array[j+1]; 
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    vector<vector<int>> ArraysA = {
        {1,3,56,23,45},
        {2,68,77,23,1},
        {3,2,54,11,19},
        {2,3,6,5,300000},
        {}
    };

    vector<vector<int>> ArraysB = {
        {1,3,4,68,77,23,1},
        {2,3,4,3,2,1,8},
        {1,1,3,5,7},
        {2,3,4,5,1},
        {}
    };

    for(int i = 0; i < ArraysA.size(); i++) {
        vector<int> merged = jamaelTechnique(ArraysA[i], ArraysB[i]);
        for (int num : merged) {
            cout << num << " ";
        }
        cout << endl;
    }
    // EXPECTED: merged and sorted arrays, A[i],B[i]
    return 0;
}
