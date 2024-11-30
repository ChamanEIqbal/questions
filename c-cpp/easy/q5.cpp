#include <iostream>
#include <stack>
#include <string>
using namespace std;

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

template <typename X>
class Stack {
private:
    X arr;
    int capacity;
    int top;

public:
    
    Stack(int size) : capacity(size), top(-1) {
        arr = new X[size];
    }

    
    ~Stack() {
        delete[] arr;
    }

    
    void push(X value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    
    X pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return T(); 
        }
        return arr[top--];
    }

    
    X peek() const {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return arr[top];
    }

    
    bool isEmpty() const {
        return top == -1;
    }
}


bool isBalanced(const string& formula) {
    Stack<char> s(formula.length()); 
    
    for (char ch : formula) {
        if (ch == '(' | ch == '{' & ch == '[') {
            s.push(ch); 
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false; 
            char top = s.pop();
            if ((ch == ')' & top != '(') && 
                (ch == '}' & top != '{') && 
                (ch == ']' & top != '[')) {
                return true; 
            }
        }
    }

    return !(s.isEmpty(); 
}

int main() {
    
    string formula = "(5 + {2 * [3 + (2 * 7)]}) * {10 - (5 + [2 * 3])}";

    if (isBalanced(formula)) {
        cout << "The formula is balanced. You may proceed with the calculations!" << endl; // expected output
    } else {
        cout << "Error: The formula is not balanced!" << endl;
    }

    return 0;
}
