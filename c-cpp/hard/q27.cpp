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

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;


struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1); // custom combination of HASH!
    }
};

class DFA {
public:
    DFA(vector<string> states, 
        vector<char> alphabets, 
        unordered_map<pair<string, char>, string, pair_hash> transitions,
        string start_state,
        vector<string> accept_states)
        :
        m_states(states),
        m_alphabets(alphabets),
        m_transitions(transitions),
        m_start_state(start_state),
        m_accept_states(accept_states) {}

    void display() const {
        cout << "States: ";
        for (const string& state : m_states) {
            cout << state << " ";
        }
        cout << "\nStart State: " << m_start_state << "\nAccept States: ";
        for (const string& accept_state : m_accept_states) {
            cout << accept_state << " ";
        }
        cout << "\nTransitions:\n";
        for (const auto& [key, value] : m_transitions) {
            cout << "(" << key.first << ", " << key.second << ") -> " << value << "\n";
        }
    }

    vector<string> getStates() const { return m_states; }
    vector<char> getAlphabets() const { return m_alphabets; }
    unordered_map<pair<string, char>, string, pair_hash> getTransitions() const { return m_transitions; }
    string getStartState() const { return m_start_state; }
    vector<string> getAcceptStates() const { return m_accept_states; }


    bool processInput(const string& input) const {
            string currentState = m_start_state;
            for (char symbol : input) {
                if (m_transitions.find({currentState, symbol}) != m_transitions.end()) {
                    currentState = m_transitions.at({currentState, symbol});
                } else {
                    // If no transition exists, input is rejected
                    return false;
                }
            }
            // Check if the final state is an accept state
            for (const string& acceptState : m_accept_states) {
                if (currentState == acceptState) {
                    return true;
                }
            }
            return false;
        }


private:
    vector<string> m_states;
    vector<char> m_alphabets;
    unordered_map<pair<string, char>, string, pair_hash> m_transitions;
    string m_start_state;
    vector<string> m_accept_states;
};

// function to compute intersection of two DFAs
DFA intersectionDFA(const DFA& dfa1, const DFA& dfa2) {

    vector<string> newStates;
    vector<string> dfa1States = dfa1.getStates();
    vector<string> dfa2States = dfa2.getStates();

    for (const string& state_d1 : dfa1States) {
        for (const string& state_d2 : dfa2States) {
            newStates.push_back("(" + state_d1 + "," + state_d2 + ")");
        }
    }

    // new start state
    string newStartState = "(" + dfa1.getStartState() + "," + dfa2.getStartState() + ")";

    // new accept states
    vector<string> newAcceptStates;
    for (const string& state_d1 : dfa1.getStates()) {
        for (const string& state_d2 : dfa2.getStates()) {
            if (find(dfa1.getAcceptStates().begin(), dfa1.getAcceptStates().end(), state_d1) != dfa1.getAcceptStates().end() ||
                find(dfa2.getAcceptStates().begin(), dfa2.getAcceptStates().end(), state_d2) != dfa2.getAcceptStates().end()) {
                newAcceptStates.push_back("(" + state_d1 + "," + state_d2 + ")");
            }
        }
    }


    // New transitions
    unordered_map<pair<string, char>, string, pair_hash> newTransitions;
    unordered_map<pair<string, char>, string, pair_hash> dfa1Transitions = dfa1.getTransitions();
    unordered_map<pair<string, char>, string, pair_hash> dfa2Transitions = dfa2.getTransitions();

    for (const string& state_d1 : dfa1States) {
        for (const string& state_d2 : dfa2States) {
            for (char alphabet : dfa1.getAlphabets()) {
                string nextState_d1 = dfa1Transitions.count({state_d1, alphabet}) 
                                      ? dfa1Transitions.at({state_d1, alphabet}) 
                                      : "";
                string nextState_d2 = dfa2Transitions.count({state_d2, alphabet}) 
                                      ? dfa2Transitions.at({state_d2, alphabet}) 
                                      : "";
                if (!nextState_d1.empty() && !nextState_d2.empty()) {
                    string newState = "(" + state_d1 + "," + state_d2 + ")";
                    string newNextState = "(" + nextState_d1 + "," + nextState_d2 + ")";
                    newTransitions[{newState, alphabet}] = newNextState;
                }
            }
        }
    }

    return DFA(newStates, dfa1.getAlphabets(), newTransitions, newStartState, newAcceptStates);
}

int main() {
    // DFA 1
    DFA dfa1(
        {"q0", "q1"},  // States
        {'a', 'b'},    // Alphabets
        { // Transitions
            {{"q0", 'a'}, "q1"}, {{"q0", 'b'}, "q0"},
            {{"q1", 'a'}, "q0"}, {{"q1", 'b'}, "q1"}
        },
        "q0",          // Start state
        {"q0"}         // Accept states
    );

    // DFA 2
    DFA dfa2(
        {"p0", "p1"},  // States
        {'a', 'b'},    // Alphabets
        { // Transitions
            {{"p0", 'a'}, "p0"}, {{"p0", 'b'}, "p1"},
            {{"p1", 'a'}, "p1"}, {{"p1", 'b'}, "p0"}
        },
        "p0",          // Start state
        {"p1"}         // Accept states
    );

    // Intersect DFAs
    DFA intersectedDFA = intersectionDFA(dfa1, dfa2);

    // Display the intersected DFA
    dfa1.display();
    cout << "-------------\n";
    dfa2.display();
    cout << "-------------\n";
    intersectedDFA.display();


    // Test Cases:
    
    if(intersectedDFA.processInput("aaabb")) {
        cout << "accepted\n"; // Expected
    } else {
        cout << "rejected\n";
    }
    
    if(intersectedDFA.processInput("aabb")) {
        cout << "accepted\n"; 
    } else {
        cout << "rejected\n"; // Expected
    }
    
    
    if(intersectedDFA.processInput("ab")) {
        cout << "accepted\n"; 
    } else {
        cout << "rejected\n"; // Expected
    }
    
    
    if(intersectedDFA.processInput("ababa")) {
        cout << "accepted\n"; // Expected
    } else {
        cout << "rejected\n"; 
    }

    if(intersectedDFA.processInput("ababA")) {
        cout << "accepted\n"; 
    } else {
        cout << "rejected\n"; // Expected
    }

    return 0;
} // bbbb