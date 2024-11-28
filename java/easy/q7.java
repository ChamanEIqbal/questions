/*
     * You are a space explorer who must solve the riddle to unlock the treasure chamber.
     * The name of the chamber is a palindrome, but the robot seems to have some issues.
     * Fix the robot's logic so it can check if a string is a palindrome correctly.
*/

public class RobotPalindrome {
    
    public static boolean isPalindrome(String str) {
        int left = 0;
        int right = str.length() - 1;


        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {  
                return false;  
            }
            left++;
        }

        return false;  
    }

    public static void main(String[] args) {
        String word = "Racecar";  
        System.out.println(isPalindrome(word))   // robot expects: true
    }
}
