"""
    You are given 2 DFAs in this question.
    DFA1 accepts odd number of a's
    DFA2 accepts even number of b's

    you are required to intersect both DFAs and produced matching outputs:

    Ensure, the DFA is correctly architechtured,
    Ensure, the tuples are correctly made after intersection
    Ensure, the output validation matches this criteria:
    odd number of a's and even number of b's.
"""

from typing import List, Dict, Tuple


class DFA:
    def __init__(self, states: List[str], alphabets: List[str], transitions: Dict[Tuple[str, str], str], start_state: str, accept_states: List[str]):
        self.states = states
        self.alphabets = alphabets
        self.transitions = transitions
        self.start_state = start_state
        self.accept_states = accept_states

    def display(self):
        print(f"States: {self.states}")
        print(f"Start State: {self.start_state}")
        print(f"Accept States: {self.accept_states}")
        print("Transitions:")
        for (state, char), next_state in self.transitions.items():
            print(f"({state}, {char}) -> {next_state}")

    def process_input(self, input_str: str) -> bool:
        current_state = self.start_state
        for symbol in input_str:
            if (current_state, symbol) in self.transitions:
                current_state = self.transitions[(current_state, symbol)]
            else:
                return False
        return current_state in self.accept_states


def intersect_dfa(dfa1: DFA, dfa2: DFA) -> DFA:
    new_states = []
    new_accept_states = []
    new_transitions = {}

    for state1 in dfa1.states:
        for state2 in dfa2.states:
            new_state = (state1, state2)
            new_states.append(new_state)
            if state1 in dfa1.accept_states or state2 in dfa2.accept_states:
                new_accept_states.append(new_state)

    new_start_state = (dfa1.start_state, dfa2.start_state)

    for (state1, char), next_state1 in dfa1.transitions.items():
        for (state2, _), next_state2 in dfa2.transitions.items():
            if char in dfa1.alphabets and char in dfa2.alphabets:
                new_transitions[((state1, state2), char)] = (next_state1, next_state2)

    return DFA(
        states=new_states,
        alphabets=dfa1.alphabets,
        transitions=new_transitions,
        start_state=new_start_state,
        accept_states=new_accept_states
    )


# Test Case:
dfa1 = DFA(
    states=["q0", "q1"],
    alphabets=['a', 'b'],
    transitions={
        ("q0", 'a'): "q1", ("q0", 'b'): "q0",
        ("q1", 'a'): "q0", ("q1", 'b'): "q1"
    },
    start_state="q0",
    accept_states=["q0"]
)

dfa2 = DFA(
    states=["p0", "p1"],
    alphabets=['a', 'b'],
    transitions={
        ("p0", 'a'): "p0", ("p0", 'b'): "p1",
        ("p1", 'a'): "p1", ("p1", 'b'): "p0"
    },
    start_state="p0",
    accept_states=["p1"]
)

intersected_dfa = intersect_dfa(dfa1, dfa2)

print("DFA 1:")
dfa1.display()
print("\nDFA 2:")
dfa2.display()
print("\nintersected DFA:")
intersected_dfa.display()

# Test processing inputs
print("\nTesting intersected DFA:")
test_inputs = ["aaabb", "aabb", "ab", "ababa", "ababA"] # accepted, rejected, rejected, accepted, rejected
for inp in test_inputs:
    result = "accepted" if intersected_dfa.process_input(inp) else "rejected"
    print(f"Input '{inp}': {result}")
