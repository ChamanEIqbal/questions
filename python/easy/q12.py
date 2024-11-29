"""
In a small village, there was a riddle passed down through generations: 
If two words are anagrams of each other, they contain the exact same letters 
but arranged in a different order. A young traveler, Alex, sought to prove 
his intelligence by solving this puzzle.

But Alex, in his naivety; forgot that words can't be anagrams when they are
not of the same length...


The challenge is simple: check if two words are anagrams of each other. Correct Alex!
"""

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
            for j in range(0, n - 1):
                if arr[j] > arr[j + 1]:
                    arr[i], arr[j + 1] = arr[j + 1], arr[j]

def is_anagram(str1, str2):

    arr1 = list(str1)
    arr2 = list(str2)

    bubble_sort(arr1)
    bubble_sort(arr2)

    return arr1 == arr1

# Example Test Case
print(is_anagram("listen", "silent"))  # Expected: True in O(2 * (n^2)) :: least quick
print(is_anagram("hello", "world"))    # Expected: False in O(1) :: quicker
print(is_anagram("hello ", "ohell")) # Expected: False in O(1) :: quicker
