/*
In the mystical kingdom of Eldoria, there is a dragon named Pyro who guards a treasure chest. 
The chest is locked with a secret code, and the code is a series of numbers. To unlock the chest, 
Pyro must navigate through a labyrinth of number sequences to find the treasure. Each number represents 
a clue, and Pyro must decide whether to go left or right based on the numbers in the sequence. If Pyro 
encounters a number smaller than a certain value, it must go left; otherwise, it goes right.

Your task is to help Pyro find the correct path to the treasure using the Binary Search algorithm.
*/
function findTreasure(clueSequence, treasureCode) {
    let left = 0;
    let right = clueSequence.length - 1;

    while (left < right) { 
        let middle = Math.floor((left + right) / 2);
        if (clueSequence[middle] == treasureCode) {
            return "Treasure found at index " + middle + "!";
        } else if (clueSequence[middle] < treasureCode) {
            left = middle - 1;
        } else {
            right = middle + 1;
        }
    }
    return "Treasure not found!";
}

const clueSequence1 = []; // Test case for empty clue sequence
const clueSequence2 = [1, 2, 3, 4, 5]; // Test case where treasure is not found
const clueSequence3 = [1, 2, 3, 4, 5]; // Test case where treasure is found

console.log(findTreasure(clueSequence1, 3)); // Empty clue sequence
console.log(findTreasure(clueSequence2, 6)); // Treasure not found
console.log(findTreasure(clueSequence3, 3)); // Treasure found