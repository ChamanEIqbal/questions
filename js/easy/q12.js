/*
In a small village, there was a riddle passed down through generations:
If two words are anagrams of each other, they contain the exact same letters
but arranged in a different order. A young traveler, Alex, sought to prove
his intelligence by solving this puzzle.

But Alex, in his naivety; forgot that words can't be anagrams when they are
not of the same length...

The challenge is simple: check if two words are anagrams of each other. Correct Alex!
*/

function bubbleSort(arr) {
    const n = arr.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n - 1; j++) {  
            if (arr[j] > arr[j + 1]) {
                let temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

function isAnagram(str1, str2) {

    let arr1 = str1.split();
    let arr2 = str2.split();

    bubbleSort(arr1);
    bubbleSort(arr2);

    return arr1.join() === arr1.join();
}


console.log(isAnagram("listen", "silent"));  // Expected: true, in O(2 * (n^2)) :: least quick
console.log(isAnagram("hello", "world"));    // Expected: false, in O(1) :: quicker 
console.log(isAnagram("hello ", "ohell"));   // Expected: false, in O(1) :: quicker