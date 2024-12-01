/**
 * In the ancient kingdom of Regwarts, a powerful guild of Regex-Wizards harnessed the power of
*wildcards* to control the flow of data. The wizards had perfected the art of casting regex
spells that could match and transform strings with unparalleled precision. With the collapse
of their kingdom, the guild has fragmented into three factions—Python, JavaScript, and Java—each
controlling a different aspect of the regex universe.

The wizard must venture into each of these factions and learn their different incantations to
reclaim the power of regex. The wizards use special characters, or “wildcards,” to define patterns
for recognizing specific forms of magic (like complex numbers and real numbers) and wield them
in their journey to restore order to the shattered world of Regwarts.

The wizards used various symbols, each with its own unique function:

1. The Asterisk (*) - "The Wild Repeater" - This powerful symbol allows a wizard to invoke
   the repetition of characters. It says, "Match zero or more occurrences of the preceding element."
   In Regwarts, this is used to signify endless loops or infinite occurrences.

2. The Plus Sign (+) - "The Aggressive Repeater" - A close kin of the asterisk, but the Plus
   only accepts one or more occurrences. It demands that at least one of the preceding character
   must exist in the string, or the magic spell will fail.

3. The Question Mark (?) - "The Optional Conjurer" - This character lets the wizard make part
   of the pattern optional. It says, "The preceding element may appear once or not at all,"
   offering flexibility to patterns that need to allow for both presence and absence.

4. The Caret (^) - "The Boundary Sentinel" - The Caret, or ^, is a mystical symbol that
   represents the beginning of a string. It is used to ensure that a match occurs only at the
   start of a sequence, guarding the entry into Regwarts itself.

5. The Dollar Sign ($) - "The End of the Spell" - The Dollar Sign is equally important as the
   Caret. It signifies the end of the string, ensuring the wizard's spell ends exactly at this point.

6. The Escape-D Sign (\d) - "The Arcane Representor" - The \d sign is most important as it signifies decimal
   numbers [0-9]

With these symbols, the wizard casts the spell known as "the Regex Equation," where a complex
series of magic steps validates and processes magical numbers in the form of real and complex numbers.

The Regex spells are written in different dialects across the factions, but each wizard knows that
mastering them is the key to solving the ancient puzzle of Regwarts's lost prophecy.

The regex used here allows the wizard to validate and parse magical strings, like complex numbers
(e.g., '1,2' for 1 + 2i) and real numbers (e.g., '3' for 3.0). The characters help determine
whether these magical forms are correctly structured, ensuring the wizards' spells function properly.

In the end, the wizard must remember: regex, like magic, is both an art and a science, you must
 */

import java.util.Stack;
import java.util.regex.*;

class ArcaneNumber {
    double realPart;
    double imaginaryPart;

    // Constructor to initialize a complex number
    public ArcaneNumber(double real, double imaginary) {
        this.realPart = real;
        this.imaginaryPart = imaginary;
    }

    // Addition of complex numbers
    public ArcaneNumber add(ArcaneNumber other) {
        return new ArcaneNumber(this.realPart + other.realPart, this.imaginaryPart + other.imaginaryPart);
    }

    // Subtraction of complex numbers
    public ArcaneNumber subtract(ArcaneNumber other) {
        return new ArcaneNumber(this.realPart - other.realPart, this.imaginaryPart - other.imaginaryPart);
    }

    // Multiplication of complex numbers
    public ArcaneNumber multiply(ArcaneNumber other) {
        return new ArcaneNumber(
            this.realPart * other.realPart - this.imaginaryPart * other.imaginaryPart,
            this.realPart * other.imaginaryPart + this.imaginaryPart * other.realPart
        );
    }

    // Division of complex numbers
    public ArcaneNumber divide(ArcaneNumber other) {
        double denominator = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        return new ArcaneNumber(
            (this.realPart * other.realPart + this.imaginaryPart * other.imaginaryPart) / denominator,
            (this.imaginaryPart * other.realPart - this.realPart * other.imaginaryPart) / denominator
        );
    }

    // Display a complex number
    public void display() {
        System.out.print(this.realPart);
        System.out.print("+ " + this.imaginaryPart);
}

public class ComplexPostfixCalculator {
    public static ArcaneNumber evaluatePostfix(String expression) {
        Stack<ArcaneNumber> arcaneStack = new Stack<>();
        String[] tokens = expression.split("\\s+");

        Pattern realPattern = Pattern.compile("\\d+");
        Pattern complexPattern = Pattern.compile("\\d+,\\d+");

        for (String token : tokens) {
            if (token.matches("[+\\-*/]")) { // Operator
                ArcaneNumber b = arcaneStack.pop();
                ArcaneNumber a = arcaneStack.pop();
                switch (token) {
                    case "+":
                        arcaneStack.push(a.add(b));
                        break;
                    case "-":
                        arcaneStack.push(a.subtract(b));
                        break;
                    case "*":
                        arcaneStack.push(a.multiply(b));
                        break;
                    case "/":
                        arcaneStack.push(a.divide(b));
                        break;
                }
            } else if (realPattern.matcher(token).matches()) {  // Arcane Number
                double real = Double.parseDouble(token);
                arcaneStack.push(new ArcaneNumber(real, 0));
            } else if (complexPattern.matcher(token).matches()) { 
                String[] parts = token.split(",");
                double real = Double.parseDouble(parts[0]);
                double imaginary = Double.parseDouble(parts[1]);
                arcaneStack.push(new ArcaneNumber(real, imaginary));
            } else {
                throw new IllegalArgumentException("Invalid input: " + token);
            }
        }

        return arcaneStack.pop();
    }

    public static void main(String[] args) {
            // Test case 0:
            String expression = "";
            try {
                ArcaneNumber result = evaluatePostfix(expression); 
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage()); // Error thrown, empty string
            }

            // Test case 1:
            expression = "1,-2 2,3 +";
            try {
                ArcaneNumber result = evaluatePostfix(expression);
                result.display(); // Expected  OUTPUT: "3 + 1i"
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }

            // Test case 2:
            expression = "1,2 2,-3 +";
            try {
                ArcaneNumber result = evaluatePostfix(expression);
                result.display(); //  Expected  OUTPUT: "3 - 1i"
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }

            // Test case 3:
            expression = "1 2,-3 +";
            try {
                ArcaneNumber result = evaluatePostfix(expression);
                result.display(); //  Expected  OUTPUT: 3 - 3i
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }

            // Test case 4:
            expression = "1 0,0 /";
            try {
                ArcaneNumber result = evaluatePostfix(expression); // Expected: Error Thrown, Division By Zero
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }
}