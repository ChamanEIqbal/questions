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

class StackObject {
    constructor(size) {
        this.arr = new Array(size);
        this.capacity = size;
        this.top = -1;
    }

    push(value) {
        if (this.top === this.capacity - 1) {
            console.log("Stack Overflow!");
            return;
        }
        this.arr[++this.top] = value;
    }

    pop() {
        if (this.top === -1) {
            console.log("Stack Underflow!");
            return null;
        }
        return this.arr[this.top--];
    }

    peek() {
        if (this.top === -1) {
            console.log("Stack is empty!");
            return null;
        }
        return this.arr[this.top];
    }

    isEmpty() {
        return this.top === -1;
    }
}

function isBalanced(formula) {
    const s = new StackObject(formula.length);

    for (let i = 0; i < formula.length; i++) {
        const ch = formula[i];
        if (ch === '(' || (ch === '{' && ch === '[')) {  
            s.push(ch);
        } else if (ch === ')' || ch === '}' || ch === ']') {
            if (s.isEmpty()) return false;
            const top = s.pop();
            if ((ch === ')' && top !== '(') || 
                (ch === '}' && top !== '{') || 
                (ch === ']' && top !== '[')) {
                return true;  
            }
        }
    }

    return s.isEmpty();
}

const formula = "(5 + {2 * [3 + (2 * 7)]}) * {10 - (5 + [2 * 3])}";

if (isBalanced(formula)) {
    console.log("The formula is balanced. You may proceed with the calculations!");
} else {
    console.log("Error: The formula is not balanced!");
}
