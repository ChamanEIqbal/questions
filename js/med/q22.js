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
 */

class Thought {
    constructor() {
        this.description = "Basic Thought";
        this.significance = 0;
        this.memory = [];
    }

    getDescription() {
        return this.description;
    }

    getSignificance() {
        return this.significance;
    }

    getMemory() {
        return this.memory.join(", ");
    }

    addMemory(newMemory) {
        this.memory.push(newMemory);
    }
}

// Synapse Class here


// Main Neuron Decorator, Enhance the thought with MAIN idea.
class MainNeuronDecorator extends Synapse {
    constructor(thought, coreIdea) {
        super(thought);
        this.coreIdea = coreIdea;
    }

    getDescription() {
        return this.thought.getDescription() + ", Main Idea: " + this.coreIdea;
    }

    getSignificance() {
        return this.thought.getSignificance() + 20;  // main Idea adds significant weight to the thought
    }
}

// Enhance the thoughts with a CONCEPT!
class EnhancementNeuron extends Synapse {
    constructor(thought, concept) {
        super(thought);
        this.concept = concept;
    }

    getDescription() {
        return this.thought.getDescription() + ", Enhanced with " + this.concept;
    }

    getSignificance() {
        return this.thought.getSignificance() + 10;  // enhances the thought with extra complexity
    }
}

const basicThought = new Thought();  // starting with a neutral thought
let decoratedThought = new MainNeuronDecorator(basicThought, "Post Structuralism"); // 20
decoratedThought = new EnhancementNeuron(decoratedThought, "Linguistic Ambiguity");  // 10
decoratedThought = new EnhancementNeuron(decoratedThought, "Semantic Brute Permutations"); // 10
decoratedThought = new EnhancementNeuron(decoratedThought, "Concept of Difference"); // 10
decoratedThought = new EnhancementNeuron(decoratedThought, "Concept of Repetition"); // 10
decoratedThought = new MainNeuronDecorator(decoratedThought, "Platonism"); // 20

decoratedThought.addMemory("Deleuzean Essay by Daniel W. Smith");  
decoratedThought.addMemory("Plato's Republic, Desmond Lee");  

console.log("Thought Description: " + decoratedThought.getDescription());  
console.log("Thought Significance: " + decoratedThought.getSignificance());
console.log("Thought Memories: " + decoratedThought.getMemory());

/**
         * EXAMPLE OUTPUT:
            Thought Description: Basic Thought, Main Idea: Post Structuralism, Enhanced with Linguistic Ambiguity, Enhanced with Semantic Brute Permutations, Enhanced with Concept of Difference, Enhanced with Concept of Repetition, Main Idea: Platonism
            Thought Significance: 80
            Thought Memories: Deleuzean Essay by Daniel W. Smith, Plato's Republic, Desmond Lee
*/
