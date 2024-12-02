# 
# In the mystical kingdom of Eldoria, there is a dragon named Pyro who guards a treasure chest. 
# The chest is locked with a secret code, and the code is a series of numbers. To unlock the chest, 
# Pyro must navigate through a labyrinth of number sequences to find the treasure. Each number represents 
# a clue, and Pyro must decide whether to go left or right based on the numbers in the sequence. If Pyro 
# encounters a number smaller than a certain value, it must go left; otherwise, it goes right.
#
# Your task is to help Pyro find the correct path to the treasure using the Binary Search algorithm.
#
def find_treasure(clue_sequence, treasure_code):
    left = 0
    right = len(clue_sequence) - 1

    while left < right:  
        middle = (left + right) // 2
        if clue_sequence[middle] == treasure_code:
            return f"Treasure found at index {middle}!"
        elif clue_sequence[middle] < treasure_code:
            left = middle - 1
        else:
            right = middle + 1
    return "Treasure not found!"

# Test cases
clue_sequence1 = []  # Empty Case
clue_sequence2 = [1, 2, 3, 4, 5]  # Treasure not found Case
clue_sequence3 = [1, 2, 3, 4, 5]  # Treasure found Case

print(find_treasure(clue_sequence1, 3))  # Expected Output: Empty clue sequence 
print(find_treasure(clue_sequence2, 6))  # Expected Output: Treasure not found
print(find_treasure(clue_sequence3, 3))  # Expected Output: Treasure found
