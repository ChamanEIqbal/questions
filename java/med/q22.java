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

import java.util.ArrayList;
import java.util.List;

class Thought {
    String description;
    double significance;
    List<String> memory;

    public Thought() {
        description = "Basic Thought";
        significance = 0;
        memory = new ArrayList<>();
    }

    public String getDescription() {
        return description;
    }

    public double getSignificance() {
        return significance;
    }

    public String getMemory() {
        return String.join(", ", memory);
    }

    public void addMemory(String newMemory) {
        memory.add(newMemory);
    }
}

// Synapse Class here

class MainNeuronDecorator extends Synapse {
    String coreIdea;

    public MainNeuronDecorator(Thought thought, String coreIdea) {
        super(thought);
        this.coreIdea = coreIdea;
    }

    @Override
    public String getDescription() {
        return thought.getDescription() + ", Main Idea: " + coreIdea;
    }

    @Override
    public double getSignificance() {
        return thought.getSignificance() + 20;  // main Idea adds significant weight to the thought
    }
}

class EnhancementNeuron extends Synapse {
    String concept;

    public EnhancementNeuron(Thought thought, String concept) {
        super(thought);
        this.concept = concept;
    }

    @Override
    public String getDescription() {
        return thought.getDescription() + ", Enhanced with " + concept;
    }

    @Override
    public double getSignificance() {
        return thought.getSignificance() + 10;  // enhances the thought with extra complexity
    }
}

public class Main {
    public static void main(String[] args) {
        Thought basicThought = new Thought();  // starting with a neutral thought
        Thought decoratedThought = new MainNeuronDecorator(basicThought, "Post Structuralism"); // 20
        decoratedThought = new EnhancementNeuron(decoratedThought, "Linguistic Ambiguity");  // 10
        decoratedThought = new EnhancementNeuron(decoratedThought, "Semantic Brute Permutations"); // 10
        decoratedThought = new EnhancementNeuron(decoratedThought, "Concept of Difference"); // 10
        decoratedThought = new EnhancementNeuron(decoratedThought, "Concept of Repetition"); // 10
        decoratedThought = new MainNeuronDecorator(decoratedThought, "Platonism"); // 20

        decoratedThought.addMemory("Deleuzean Essay by Daniel W. Smith");  
        decoratedThought.addMemory("Plato's Republic, Desmond Lee");  

        System.out.println("Thought Description: " + decoratedThought.getDescription());
        System.out.println("Thought Significance: " + decoratedThought.getSignificance());
        System.out.println("Thought Memories: " + decoratedThought.getMemory());

        /**
         * EXAMPLE OUTPUT:
            Thought Description: Basic Thought, Main Idea: Post Structuralism, Enhanced with Linguistic Ambiguity, Enhanced with Semantic Brute Permutations, Enhanced with Concept of Difference, Enhanced with Concept of Repetition, Main Idea: Platonism
            Thought Significance: 80
            Thought Memories: Deleuzean Essay by Daniel W. Smith, Plato's Republic, Desmond Lee
         */
    }
}
