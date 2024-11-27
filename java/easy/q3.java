/**
 * In a distant future, on a war-torn planet named Syphara, a group of elite space engineers has been 
 * tasked with decrypting a message hidden within an ancient, alien artifact. The message, however, is
 * encoded in reverse. To unlock the secrets of the artifact, they must reverse the alien text without
 * the use of modern technologies that can reverse strings automatically.

* As one of the engineers, you must correct an ancient program to reverse the string manually, using your advanced
* understanding of algorithms. The fate of Syphara depends on your ability to solve this challenge and retrieve
* the precious data hidden within the artifact!
*/

/**
 * SAMPLE INPUT: "tset neila XAE II IV III VI"
 * SAMPLE OUTPUT: "IV III VI II EAX alien test"
 */


public class SypharaArtifact {

    class Engineer {
        public static void reverseString(String str) {
            int start = 0;
            int end = str.length();

            while(start > end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;

                start++;
            }
        }
    }

    public static void main(String[] args) {
    
        System.out.println("Welcome, Engineer. You are tasked with reversing the alien message.");
        System.out.println("Decrypt the text hidden in the artifact!");

        // The device seems to be in an alien language; the variable name is "laIem", here...   
        String laIem = "tset neila XAE II IV III VI"; 
        

        System.out.println("Original Message: " + Ialem);


        laIem = reverseString(laIem);
        

        System.out.println("Reversed Message: " + Ialem);
    }
}