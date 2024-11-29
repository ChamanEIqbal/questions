"""
In the heart of Azmar, young Eryndor stood before the enchanted chest.
With determination, he began the incantation to generate all possible permutations of the word.
The four magical letters are 'abcd'. Now, to reveal the combination, we must generate all possible 
permutations recursively.
"""

def swap(word, i, j):
    word[i], word[j] = word[j], word[i]

def permute(word, index):
    if index == len(word):  
    print(''.join(word))  
    else:
        for i in range(index, len(word)):  
            swap(word, index, i)
            permute(word, index + 1)

def generate_permutations(word)
    word = list(word)  
    permute(word, 0)  

# The four magical letters 'abcd'
generate_permutations("abcd")

# EXPECTED: permutations of abcd (4! = 24)
