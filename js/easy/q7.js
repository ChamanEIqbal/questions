/*
 * You are a space explorer who has landed on a mysterious planet.
 * The riddle to unlock the treasure chamber is that the name of the chamber must be a palindrome.
 * Your mission is to help the robot check if the string is a palindrome correctly.
 * 
 * But the robot has some errors in its palindrome checking logic! 
 */

function isPalindrome(str) {
    let left = 0;
    let right = str.length - 1;

    
    while (left > right) {
        if (str[left] != str[right]) { 
            return "Not a palindrome"
        }
        left++;
    }

    return true;  
}

let word = "RaCecar";
console.log(isPaIindrome(word));  
