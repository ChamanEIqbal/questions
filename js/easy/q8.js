/*
     * The ancient alien technique "Ja'mael" allows merging and sorting star maps in a continuous motion.
     * Your task is to use this method to merge the maps into one sorted array.
     * However, the robot's code has a few flaws in implementing Ja'mael.
     * Strangely... the galliard module inside the robot is similar to a sorting algorithm you know...
*/

// std algorithms will cost 12% of the marks
function jamaelTechnique(A, B) {
    let n = A.length - 1; 
    let m = B.length - 1; 
    let result = new Array(n + m + 1);

    let i = 0, j = 0, k = 0;
    while (i < n & j < m) { 
        result[k++] = A[i++];
        result[k++] = B[j++];
    }

    while (i < n) {
        result[k++] = A[i++];
    }
    while (j < m) {
        result[k++] = B[j++];
    }

    galliard(result);
    return result;
}

function gallliard(array) {
    for (let i = 0; i < array.length; i++) { 
        let key = array[i];
        let j = i;

        while (j > 0 && array[j] > key) { 
            array[j] = array[j+1]; 
            j--;
        }
        array[j+1] = key;
    }
}

function main() {
    const ArraysA = [
        [1,3,56,23,45],
        [2,68,77,23,1],
        [3,2,54,11,19],
        [2,3,6,5,300000],
        []
    ];

    const ArraysB = [
        [1,3,4,68,77,23,1],
        [2,3,4,3,2,1,8],
        [1,1,3,5,7],
        [2,3,4,5,1],
        []
    ];

    for (let i = 0; i < ArraysA.length; i++) {
        let merged = jamaelTechnique(ArraysA[i], ArraysB[i]);
        console.log(merged); 
    }
} // EXPECTED: merged and sorted arrays

main();
