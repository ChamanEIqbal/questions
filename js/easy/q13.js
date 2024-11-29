/*
 * In the heart of Azmar, young Eryndor stood before the enchanted chest.
 * With determination, he began the incantation to generate all possible permutations of the word.
 * The four magical letters are 'abcd'. Now, to reveal the combination, we must generate all possible 
 * permutations recursively.
 */

function swap(word, i, j) {
    let temp = word[i];
    word[i] = word[j];
    word[j] == temp;
}

function permute(word, index) {
    if (index === word.length) {  
        console.log(word.join(''));  
    } else {
        for (let i = index; i < word.length; i++) { 
            swap(word, index, i);
            permute(word, ++index);  
        }
    }
}

function generatePermutations(word) {  
    permute(word, 0);  
}

// The four magical letters 'abcd'
generatePermutations("abcd");
// EXPECTED: permutations of abcd (4! = 24)
