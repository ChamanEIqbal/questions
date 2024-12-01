/**
 * You are a cognitive scientist, trying to evaluate different schools of thought;
 * through multiple neural pathways called "Synapse"(s).
 * 
 * Each thought has a description, that you give to identify it. (string)
 * Each thought has a significance level, that you give to identify. (double)
 * Each thought has a set of memories associated with it. (list of strings)
 * 
 * You are researching about the history of Philosophy, and you need to evaluate the significance of different
 * schools of thoughts across philosophy, with their associated concepts; that hold the following significance:
 * 
 * 10 Significance: Enhancement Concept
 * 20 Significance: Main Idea
 * 
 * Since you are a cognitive scientist, You've opted to think in terms of neural-networks.
 * 
 * TASK:
 * Your job here, is to create a synaptic pathway for all neurons, such that you could evaluate
 * different schools of thoughts by decorating them with their known significances.
 * 
 * PATTERN:
 * The Design Pattern used here is "Decorator".
 * 
 * Implement the Synapse class to act as the base decorator for extending the functionality of the Thought class. 
 * Ensure that the decorator classes inherit from Synapse and modify both the getDescription() and 
 * getSignificance() methods. 
 * 
 * The code should produce the expected output as described.
 * 
 */


#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Thought {
public:
    string description;  // The description of the thought
    double significance; // The 'significance' or weight of the thought
    vector<string> memory;  // Memories associated

    Thought() {
        description = "Basic Thought";
        significance = 0;  // The initial significance of the thought is neutral
    }

    string getDescription() {
        return description;
    }

    double getSignificance() {
        return significance;
    }

    string getMemory() {
        string memoryStr = "";
        for (const auto& mem : memory) {
            memoryStr += mem + ", ";
        }
        return memoryStr;
    }

    void addMemory(string newMemory) {
        memory.push_back(newMemory);
    }
};


// Synapse Class here


// Main Neuron Decorator, Enhance the thought with MAIN idea.
class MainNeuronDecorator : public Synapse {
public:
    string coreIdea;

    MainNeuronDecorator(Thought* thought, string coreIdea) : Synapse(thought) {
        this->coreIdea = coreIdea;
    }

    string getDescription() {
        return thought->getDescription() + ", Main Idea: " + coreIdea;
    }

    double getSignificance() {
        return thought->getSignificance() + 20;  // Main Idea adds significant weight to the thought
    }
};

// Enhance the thoughts with a CONCEPT!
class EnhancementNeuron : public Synapse {
public:
    string concept;

    EnhancementNeuron(Thought* thought, string concept) : Synapse(thought) {this->concept = concept;}

    string getDescription() {
        return thought->getDescription() + ", Enhanced with " + concept;
    }

    double getSignificance() {
        return thought->getSignificance() + 10;  // Enhances the thought with extra complexity
    }
};



int main() {
    Thought* basicThought = new Thought();  // starting with a neutral thought
    basicThought = new MainNeuronDecorator(basicThought, "Post Structuralism"); // 20
    basicThought = new EnhancementNeuron(basicThought, "Linguistic Ambiguity");  // 10
    basicThought = new EnhancementNeuron(basicThought, "Semantic Brute Permutations"); // 10
    basicThought = new EnhancementNeuron(basicThought, "Concept of Difference"); // 10
    basicThought = new EnhancementNeuron(basicThought, "Concept of Repetition"); // 10
    basicThought = new MainNeuronDecorator(basicThought, "Platonism"); // 20

    basicThought->addMemory("Deleuzean Essay by Daniel W. Smith");  
    basicThought->addMemory("Plato's Republic, Desmond Lee");  


    cout << "Thought Description: " << basicThought->getDescription() << endl;  
    cout << "Thought Significance: " << basicThought->getSignificance() << endl;
    cout << "Thought Memories: " << basicThought->getMemory() << endl;  

    return 0;

    /**
         * EXAMPLE OUTPUT:
            Thought Description: Basic Thought, Main Idea: Post Structuralism, Enhanced with Linguistic Ambiguity, Enhanced with Semantic Brute Permutations, Enhanced with Concept of Difference, Enhanced with Concept of Repetition, Main Idea: Platonism
            Thought Significance: 80
            Thought Memories: Deleuzean Essay by Daniel W. Smith, Plato's Republic, Desmond Lee
    */
}
