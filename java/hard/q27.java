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

import java.util.*;

class DFA {
    List<String> states;
    List<String> alphabets;
    Map<String, String> transitions;
    String startState;
    List<String> acceptStates;

    public DFA(List<String> states, List<String> alphabets, Map<String, String> transitions, String startState, List<String> acceptStates) {
        this.states = states;
        this.alphabets = alphabets;
        this.transitions = transitions;
        this.startState = startState;
        this.acceptStates = acceptStates;
    }

    public void display() {
        System.out.println("States: " + states);
        System.out.println("Start State: " + startState);
        System.out.println("Accept States: " + acceptStates);
        System.out.println("Transitions:");
        for (Map.Entry<String, String> entry : transitions.entrySet()) {
            System.out.println("(" + entry.getKey() + ") -> " + entry.getValue());
        }
    }

    public boolean processInput(String inputStr) {
        String currentState = startState;
        for (char symbol : inputStr.toCharArray()) {
            String key = currentState + "," + symbol;
            if (transitions.containsKey(key)) {
                currentState = transitions.get(key);
            } else {
                return false;
            }
        }
        return acceptStates.contains(currentState);
    }
}

public class Main {
    public static DFA intersectDFA(DFA dfa1, DFA dfa2) {
        Set<String> newStates = new HashSet<>();
        Set<String> newAcceptStates = new HashSet<>();
        Map<String, String> newTransitions = new HashMap<>();

        for (String state1 : dfa1.states) {
            for (String state2 : dfa2.states) {
                String newState = state1 + "," + state2;
                newStates.add(newState);
                if (dfa1.acceptStates.contains(state1) || dfa2.acceptStates.contains(state2)) {
                    newAcceptStates.add(newState);
                }
            }
        }

        String newStartState = dfa1.startState + "," + dfa2.startState;

        for (String state1 : dfa1.states) {
            for (String state2 : dfa2.states) {
                for (String symbol : dfa1.alphabets) {
                    String key1 = state1 + "," + symbol;
                    String key2 = state2 + "," + symbol;
                    if (dfa1.transitions.containsKey(key1) && dfa2.transitions.containsKey(key2)) {
                        String newState = dfa1.transitions.get(key1) + "," + dfa2.transitions.get(key2);
                        newTransitions.put(state1 + "," + state2 + "," + symbol, newState);
                    }
                }
            }
        }

        return new DFA(new ArrayList<>(newStates), dfa1.alphabets, newTransitions, newStartState, new ArrayList<>(newAcceptStates));
    }

    public static void main(String[] args) {
        DFA dfa1 = new DFA(
            Arrays.asList("q0", "q1"),
            Arrays.asList("a", "b"),
            Map.of(
                "q0,a", "q1", "q0,b", "q0",
                "q1,a", "q0", "q1,b", "q1"
            ),
            "q0",
            Arrays.asList("q0")
        );

        DFA dfa2 = new DFA(
            Arrays.asList("p0", "p1"),
            Arrays.asList("a", "b"),
            Map.of(
                "p0,a", "p0", "p0,b", "p1",
                "p1,a", "p1", "p1,b", "p0"
            ),
            "p1",
            Arrays.asList("p1")
        );

        DFA resultDFA = intersectDFA(dfa1, dfa2);

        System.out.println("DFA 1:");
        dfa1.display();
        System.out.println("\nDFA 2:");
        dfa2.display();
        System.out.println("\nIntersected DFA:");
        resultDFA.display();

        // Test processing inputs
        System.out.println("\nTesting Intersected DFA:");
        String[] testInputs = {"aaabb", "aabb", "ab", "ababa", "ababA"}; // accepted, rejected, rejected, accepted, rejected
        for (String inp : testInputs) {
            String result = resultDFA.processInput(inp) ? "accepted" : "rejected";
            System.out.println("Input '" + inp + "': " + result);
        }
    }
}
