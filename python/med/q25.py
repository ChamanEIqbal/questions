"""
In the ancient kingdom of Regwarts, a powerful guild of Regex-Wizards harnessed the power of
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
"""


import re

class ArcaneNumber:
    def __init__(self, real, imaginary):
        self.real_part = real
        self.imaginary_part = imaginary

    def add(self, other):
        return ArcaneNumber(self.real_part + other.real_part, self.imaginary_part + other.imaginary_part)

    def subtract(self, other):
        return ArcaneNumber(self.real_part - other.real_part, self.imaginary_part - other.imaginary_part)

    def multiply(self, other):
        return ArcaneNumber(
            self.real_part * other.real_part - self.imaginary_part * other.imaginary_part,
            self.real_part * other.imaginary_part + self.imaginary_part * other.real_part
        )

    def divide(self, other):
        denominator = other.real_part * other.real_part + other.imaginary_part * other.imaginary_part
        return ArcaneNumber(
            (self.real_part * other.real_part + self.imaginary_part * other.imaginary_part) / denominator,
            (self.imaginary_part * other.real_part - self.real_part * other.imaginary_part) / denominator
        )

    def display(self):
        result = str(self.real_part)
        result += " + {}i".format(self.imaginary_part)
        print(result)


def evaluate_postfix(expression):
    arcane_stack = []
    tokens = expression.split()

    real_regex = re.compile(r"^-?\d+$")
    complex_regex = re.compile(r"^-?\d+,-?\d+$")

    for token in tokens:
        if token in ['+', '-', '*', '/']:
            b = arcane_stack.pop()
            a = arcane_stack.pop()
            if token == '+':
                arcane_stack.append(a.add(b))
            elif token == '-':
                arcane_stack.append(a.subtract(b))
            elif token == '*':
                arcane_stack.append(a.multiply(b))
            elif token == '/':
                arcane_stack.append(a.divide(b))
        elif real_regex.match(token):
            real = int(token)
            arcane_stack.append(ArcaneNumber(real, 0))
        elif complex_regex.match(token):
            real, imaginary = map(int, token.split(','))
            arcane_stack.append(ArcaneNumber(real, imaginary))
        else:
            raise ValueError(f"Invalid input: {token}")

    return arcane_stack.pop()

if __name__ == "__main__":
    # Test case 0:
    expression = ""
    try:
        result = evaluate_postfix(expression) # expected, value error raised
    except ValueError as e:
        print(f"Error: {e}")

    # Test case 1:
    expression = "1,-2 2,3 +"
    try:
        result = evaluate_postfix(expression)
        result.display() # expected, "3 + 1i"
    except ValueError as e:
        print(f"Error: {e}")

    # Test case 2:
    expression = "1,2 2,-3 +"
    try:
        result = evaluate_postfix(expression)
        result.display() # expected, "3 - 1i"
    except ValueError as e:
        print(f"Error: {e}")

    # Test case 3:
    expression = "1 2,-3 +"
    try:
        result = evaluate_postfix(expression)
        result.display() # expected, "3 - 3i"
    except ValueError as e:
        print(f"Error: {e}")

    # Test case 4:
    expression = "1 0,0 /"
    try:
        result = evaluate_postfix(expression) # expected, value error raised: divide by zero
    except ValueError as e:
        print(f"Error: {e}")

