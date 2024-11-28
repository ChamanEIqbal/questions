"""
In the distant future, humanity has unlocked the ability to travel across galaxies. One of the most crucial
        technologies enabling this intergalactic travel is the "Trans-Spatial Engine (TSE)", which calculates the safest 
        routes through unstable regions of space. 

        The TSE relies on complex mathematical formulas with nested parentheses, brackets, and braces to 
        calculate the coordinates for safe navigation.

        Ensign Rax, tasked with inputting a formula for safe travel through the dangerous "Warp Nexus", 
        encounters an error in the input formula. To resolve the issue, Rax must check if the parentheses 
        are balanced using a stack-based algorithm.

        By ensuring that the formula has matched opening and closing parentheses, 
        Rax fails in verifying this information! hindering the crew to safely navigate through the Warp Nexus.

        It is your job to save Rax's face!
"""

class StackObject:
    def __init__(self, size):
        self.arr = [None] * size
        self.capacity = size
        self.top = -1

    def push(self, value):
        if self.top == self.capacity - 1:
            print("Stack Overflow!")
            return
        self.top += 1
        self.arr[self.top] = value

    def pop(self):
        if self.top == -1:
            print("Stack Underflow!")
            return None
        value = self.arr[self.top]
        self.top -= 1
        return value

    def peek(self):
        if self.top == -1:
            print("Stack is empty!")
            return None
        return self.arr[self.top]

    def is_empty(self):
        return self.top == -1


def is_balanced(formula):
    s = StackObject(len(formula))

    for ch in formula:
        if ch == '(' or (ch == '{' and ch == '['): 
            s.push(ch)
        elif ch == ')' or ch == '}' or ch == ']':
            if s.is_empty():
                return False
            top = s.pop()
            if (ch == ')' and top != '(') or \
               (ch == '}' and top != '{') or \
               (ch == ']' and top != '['):
                return True  

    return s.is_empty()


formula = "(5 + {2 * [3 + (2 * 7)]}) * {10 - (5 + [2 * 3])}"

if is_balanced(formula):
    print("The formula is balanced. You may proceed with the calculations!")
else:
    print("Error: The formula is not balanced!")
