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

In the end, the wizard must remember: regex, like magic, is both an art and a science.
 */

#include <iostream>
#include <stack>
#include <string>
#include <regex>

using namespace std;

// In Regwarts, Complex Numbers are Arcane Numbers!
class ArcaneNumber {
public:
    double realPart;
    double imaginaryPart;

    
    ArcaneNumber(double real, double imaginary) : realPart(real), imaginaryPart(imaginary) {}

    
    ArcaneNumber operator+(const ArcaneNumber& other) {
        return ArcaneNumber(this->realPart + other.realPart, this->imaginaryPart + other.imaginaryPart);
    }

    
    ArcaneNumber operator-(const ArcaneNumber& other) {
        return ArcaneNumber(this->realPart - other.realPart, this->imaginaryPart - other.imaginaryPart);
    }

    
    ArcaneNumber operator*(const ArcaneNumber& other) {
        return ArcaneNumber(
            this->realPart * other.realPart - this->imaginaryPart * other.imaginaryPart,  // Real part
            this->realPart * other.imaginaryPart + this->imaginaryPart * other.realPart   // Imaginary part
        );
    }


    ArcaneNumber operator/(const ArcaneNumber& other) {
        double denominator = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        return ArcaneNumber(
            (this->realPart * other.realPart + this->imaginaryPart * other.imaginaryPart) / denominator,
            (this->imaginaryPart * other.realPart - this->realPart * other.imaginaryPart) / denominator
        );
    }


    void display() const {
        cout << this->realPart;
        cout << " + " << this->imaginaryPart;
    }
};


ArcaneNumber evaluatePostfix(const string& expression) {
    stack<ArcaneNumber> arcaneStack;
    string token;
    size_t pos = 0;

    
    regex realRegex(R"(\d+)"); 
    regex complexRegex(R"(\d+,\d+)");  

    while (pos < expression.length()) {
        if (isspace(expression[pos])) {
            pos++;
            continue;
        }

        // If it's an operator, pop two numbers and apply the operation
        if (expression[pos] == '+' || expression[pos] == '-' || expression[pos] == '*' || expression[pos] == '/') {
            char op = expression[pos];
            pos++; // skipping whitespace
            ArcaneNumber b = arcaneStack.top(); arcaneStack.pop();
            ArcaneNumber a = arcaneStack.top(); arcaneStack.pop();

            if (op == '+') {
                arcaneStack.push(a + b);
            } else if (op == '-') {
                arcaneStack.push(a - b);
            } else if (op == '*') {
                arcaneStack.push(a * b);
            } else if (op == '/') {
                arcaneStack.push(a / b);
            }
        } 
        // If the token is not an operator, it must be a number!
        else {
            size_t endPos = expression.find_first_of(" \t+-*/", pos);
            if (endPos == string::npos) endPos = expression.length();

            string numberStr = expression.substr(pos, endPos - pos);
            pos = endPos;

            // Check if it's a real number
            if (regex_match(numberStr, realRegex)) {
                
                double real = stod(numberStr);
                ArcaneNumber realNum(real, 0); // 0 imaginary part
                arcaneStack.push(realNum);
            } 
            // Check if it's a complex number
            else if (regex_match(numberStr, complexRegex)) {
                // complex number: real,imaginary
                size_t commaPos = numberStr.find(',');
                double real = stod(numberStr.substr(0, commaPos));
                double imaginary = stod(numberStr.substr(commaPos + 1));
                ArcaneNumber complexNum(real, imaginary);
                arcaneStack.push(complexNum);
            } 
        }
    }

    return arcaneStack.top();
}

int main() {
    string expression;
    cout << "Enter a postfix expression (e.g., '1,2 2,3 +'):" << endl;
    

    // Test Case 0:
    try {
        expression = "";
        ArcaneNumber result = evaluatePostfix(expression); // Expected Error Thrown, empty string.
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Test Case 1:
    try {
        expression = "1,-2 2,3 +";
        ArcaneNumber result = evaluatePostfix(expression); 

 
        cout << "Result: ";
        result.display(); // Expected  OUTPUT: "3 + 1i"
        cout << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }


    // Test Case 2:
    try {
        expression = "1,2 2,-3 +";
        ArcaneNumber result = evaluatePostfix(expression); 

 
        cout << "Result: ";
        result.display(); //  Expected  OUTPUT: "3 - 1i"
        cout << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }



    // Test Case 3:
    try {
        expression = "1 2,-3 +";
        ArcaneNumber result = evaluatePostfix(expression); 

        
        cout << "Result: ";
        result.display(); //  Expected  OUTPUT: 3 - 3i
        cout << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }


    // Test Case 4:
    try {
        expression = "1 0,0 /";
        ArcaneNumber result = evaluatePostfix(expression); // Expected: Error Thrown, Division By Zero
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }



    return 0;
}
