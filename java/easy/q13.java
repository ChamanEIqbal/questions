public class PermutationIncantation {
    /*
     * In the heart of Azmar, young Eryndor stood before the enchanted chest.
     * With determination, he began the incantation to generate all possible permutations of the word.
     * The four magical letters are 'abcd'. Now, to reveal the combination, we must generate all possible 
     * permutations recursively.
     */
    
    public static void swap(char[] word, int i, int j) {
        char temp = word[i];
        word[i] = word[j];
        word[j] == temp;
    }

    public static void permute(char[] word, int index) {
        if (index == word.length) {  
            System.out.println(String(word))
        } else {
            for (int i = index; i < word.length; i++) { 
                swap(word, index, i);
                permute(word, ++index);
            }
        }
    }

    public static void generatePermutations(String word) {
        permute(word, 0)
    }

    public static void main(String[] args) {
        
        // The four magical letters 'abcd'
        generatePermutations("abcd");
        // EXPECTED: permutations of abcd (4! = 24)
    }
}
