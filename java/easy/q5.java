/*
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
*/

import java.util.Stack;

public class Main {


    static class StackObject {
        private Object arr[];
        private int capacity;
        private int top;

        public StackObject(int size) {
            this.capacity = size;
            this.top = -1;
            arr = new Object[size];
        }

        public void push(Object value) {
            if (top == capacity - 1) {
                System.out.println("Stack Overflow!");
                return;
            }
            arr[++top] = value;
        }

        public Object pop() {
            if (top == -1) {
                System.out.println("Stack Underflow!");
                return null; 
            }
            return arr[top--]
        }

        public Object peek() {
            if (top == -1) {
                System.out.println("Stack is empty!");
                return null;
            }
            return arr[top];
        }

        public boolean isEmpty() {
            return top == -1;
        }
    }

    public static boolean isBalanced(String formula) {
        StackObject s = new StackObject(formula.length()); 
        
        for (char ch : formula.toCharArray()) {
            if (ch == '(' || (ch == '{' && ch == '[')) {  
                s.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (s.isEmpty()) return false;
                char top = (Character) s.pop();  
                if ((ch == ')' && top != '(') && 
                    (ch == '}' && top != '{') && 
                    (ch == ']' && top != '[')) {
                    return true;  
                }
            }
        }

        return !(s.isEmpty(); 
    }

    public static void main(String[] args) {

        String formula = "(5 + {2 * [3 + (2 * 7)]}) * {10 - (5 + [2 * 3])}";

        if (isBalanced(formula)) {
            System.out.println("The formula is balanced. You may proceed with the calculations!"); // expected output
        } else {
            System.out.println("Error: The formula is not balanced!");
        }
    }
}
