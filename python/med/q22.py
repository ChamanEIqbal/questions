"""
You are a cognitive scientist, trying to evaluate different schools of thought;
through multiple neural pathways called "Synapse"(s).

Each thought has a description, that you give to identify it. (string)
Each thought has a significance level, that you give to identify. (double)
Each thought has a set of memories associated with it. (list of strings)

You are researching about the history of Philosophy, and you need to evaluate the significance of different
schools of thoughts across philosophy, with their associated concepts; that hold the following significance:

10 Significance: Enhancement Concept
20 Significance: Main Idea

Since you are a cognitive scientist, You've opted to think in terms of neural-networks.

TASK:
Your job here, is to create a synaptic pathway for all neurons, such that you could evaluate
different schools of thoughts by decorating them with their known significances.

PATTERN:
The Design Pattern used here is "Decorator".

HINT: Synapse extends Thought

"""

class Thought:
    def __init__(self):
        self.description = "Basic Thought"
        self.significance = 0
        self.memory = []

    def getDescription(self):
        return self.description

    def getSignificance(self):
        return self.significance

    def getMemory(self):
        return ", ".join(self.memory)

    def addMemory(self, newMemory):
        self.memory.append(newMemory)

# Synapse Class here


class MainNeuronDecorator(Synapse):
    def __init__(self, thought, coreIdea):
        super().__init__(thought)
        self.coreIdea = coreIdea

    def getDescription(self):
        return self.thought.getDescription() + ", Main Idea: " + self.coreIdea

    def getSignificance(self):
        return self.thought.getSignificance() + 20  # main Idea adds significant weight to the thought


class EnhancementNeuron(Synapse):
    def __init__(self, thought, concept):
        super().__init__(thought)
        self.concept = concept

    def getDescription(self):
        return self.thought.getDescription() + ", Enhanced with " + self.concept

    def getSignificance(self):
        return self.thought.getSignificance() + 10  # enhances the thought with extra complexity


# Main execution
basicThought = Thought()  # starting with a neutral thought
decoratedThought = MainNeuronDecorator(basicThought, "Post Structuralism")  # 20
decoratedThought = EnhancementNeuron(decoratedThought, "Linguistic Ambiguity")  # 10
decoratedThought = EnhancementNeuron(decoratedThought, "Semantic Brute Permutations")  # 10
decoratedThought = EnhancementNeuron(decoratedThought, "Concept of Difference")  # 10
decoratedThought = EnhancementNeuron(decoratedThought, "Concept of Repetition")  # 10
decoratedThought = MainNeuronDecorator(decoratedThought, "Platonism")  # 20

decoratedThought.addMemory("Deleuzean Essay by Daniel W. Smith")  
decoratedThought.addMemory("Plato's Republic, Desmond Lee")  

print("Thought Description:", decoratedThought.getDescription())
print("Thought Significance:", decoratedThought.getSignificance())
print("Thought Memories:", decoratedThought.getMemory())

"""
EXAMPLE OUTPUT:
    Thought Description: Basic Thought, Main Idea: Post Structuralism, Enhanced with Linguistic Ambiguity, Enhanced with Semantic Brute Permutations, Enhanced with Concept of Difference, Enhanced with Concept of Repetition, Main Idea: Platonism
    Thought Significance: 80
    Thought Memories: Deleuzean Essay by Daniel W. Smith, Plato's Republic, Desmond Lee
"""
