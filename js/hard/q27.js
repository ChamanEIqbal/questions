/**
    You are given 2 DFAs in this question.
    DFA1 accepts odd number of a's
    DFA2 accepts even number of b's

    you are required to intersect both DFAs and produced matching outputs:

    Ensure, the DFA is correctly architechtured,
    Ensure, the tuples are correctly made after intersection
    Ensure, the output validation matches this criteria:
    odd number of a's and even number of b's.
 */
class DFA {
    constructor(states, alphabets, transitions, startState, acceptStates) {
        this.states = states;
        this.alphabets = alphabets;
        this.transitions = transitions;
        this.startState = startState;
        this.acceptStates = acceptStates;
    }

    display() {
        console.log(`States: ${this.states}`);
        console.log(`Start State: ${this.startState}`);
        console.log(`Accept States: ${this.acceptStates}`);
        console.log("Transitions:");
        for (const [key, value] of Object.entries(this.transitions)) {
            console.log(`(${key}) -> ${value}`);
        }
    }

    processInput(inputStr) {
        let currentState = this.startState;
        for (let symbol of inputStr) {
            const key = `${currentState},${symbol}`;
            if (this.transitions[key]) {
                currentState = this.transitions[key];
            } else {
                return false;
            }
        }
        return this.acceptStates.includes(currentState);
    }
}

function intersectDFA(dfa1, dfa2) {
    let newStates = [];
    let newAcceptStates = [];
    let newTransitions = {};

    for (let state1 of dfa1.states) {
        for (let state2 of dfa2.states) {
            let newState = [state1, state2].join(",");
            newStates.push(newState);
            if (dfa1.acceptStates.includes(state1) || dfa2.acceptStates.includes(state2)) {
                newAcceptStates.push(newState);
            }
        }
    }

    let newStartState = [dfa1.startState, dfa2.startState].join(",");

    for (let state1 of dfa1.states) {
        for (let state2 of dfa2.states) {
            for (let symbol of dfa1.alphabets) {
                const key1 = `${state1},${symbol}`;
                const key2 = `${state2},${symbol}`;
                if (dfa1.transitions[key1] && dfa2.transitions[key2]) {
                    const newState = [dfa1.transitions[key1], dfa2.transitions[key2]].join(",");
                    newTransitions[`${state1},${state2},${symbol}`] = newState;
                }
            }
        }
    }

    return new DFA(newStates, dfa1.alphabets, newTransitions, newStartState, newAcceptStates);
}


let dfa1 = new DFA(
    ["q0", "q1"],
    ['a', 'b'],
    {
        "q0,a": "q1", "q0,b": "q0",
        "q1,a": "q0", "q1,b": "q1"
    },
    "q0",
    ["q0"]
);

let dfa2 = new DFA(
    ["p0", "p1"],
    ['a', 'b'],
    {
        "p0,a": "p0", "p0,b": "p1",
        "p1,a": "p1", "p1,b": "p0"
    },
    "p0",
    ["p1"]
);

let resultDFA = intersectDFA(dfa1, dfa2);

console.log("DFA 1:");
dfa1.display();
console.log("\nDFA 2:");
dfa2.display();
console.log("\nIntersected DFA:");
resultDFA.display();

// Test processing inputs
console.log("\nTesting Intersected DFA:");
let testInputs = ["aaabb", "aabb", "ab", "ababa", "ababA"]; // accepted, rejected, rejected, accepted, rejected
for (let inp of testInputs) {
    let result = resultDFA.processInput(inp) ? "accepted" : "rejected";
    console.log(`Input '${inp}': ${result}`);
}
