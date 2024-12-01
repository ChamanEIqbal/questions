"""
In this question, you will implement and debug a merge sort algorithm. Merge sort is a divide and conquer algorithm
that works by dividing the array into halves, recursively sorting them, and then merging the sorted halves!

Your task:
1. Fix the bugs in the provided merge sort implementation.
2. Implement tree-like recursion visualization by printing the recursive calls as the array is split and merged.
3. After every test case, print the recursion tree structure with each merge() call and its depth to showcase the merge sort process.

Test cases:
- Empty array: []
- Single element array: [2]
- Two-element unsorted array: [2, 1]
- Already sorted array: [1, 2, 3, 4, 5]
- Random unsorted array: [7, 2, 5, 1, 3, 8]

After each test case, print out the recursion steps and the final sorted array.
 
 In Python:
 - You can use the string multiplication feature in Python, like `' ' * (depth * 2)` to repeat the space character.
"""

def mergeSort(arr):
    if len(arr) <= 1:
        return arr

    middle = len(arr) // 2
    left = arr[middle:]
    right = arr[:middle]

    leftSorted = mergeSort(left)
    rightSorted = mergeSort(right)

    return merge(leftSorted, rightSorted)

def merge(left, right):
    result = []
    leftIndex = 0
    rightIndex = 0

    while leftIndex < len(left) or rightIndex < len(right):
        if left[leftIndex] < right[rightIndex]:
            leftIndex += 1
            result.append(left[leftIndex])
        else:
            rightIndex += 1
            result.append(right[rightIndex])

    return result + left[leftIndex:] + right[rightIndex:]

# Test Case 1: Empty Array
arr1 = []
print("Sorted Array:", mergeSort(arr1))  # Expected Output: []

"""
Expected Output for Test Case 1:
mergeSort([])
Sorted Array: []
"""

# Test Case 2: Single Element Array
arr2 = [2]
print("Sorted Array:", mergeSort(arr2))  # Expected Output: [2]

"""
Expected Output for Test Case 2:
mergeSort([2])
Sorted Array: [ 2 ]
"""

# Test Case 3: Two Element Array (Unsorted)
arr3 = [2, 1]
print("Sorted Array:", mergeSort(arr3))  # Expected Output: [1, 2]

"""
Expected Output for Test Case 3:
mergeSort([2,1])
  mergeSort([2])
  mergeSort([1])
  merge([2], [1])
Sorted Array: [ 1, 2 ]
"""

# Test Case 4: Already Sorted Array
arr4 = [1, 2, 3, 4, 5]
print("Sorted Array:", mergeSort(arr4))  # Expected Output: [1, 2, 3, 4, 5]

"""
Expected Output for Test Case 4:
mergeSort([1,2,3,4,5])
  mergeSort([1,2])
    mergeSort([1])
    mergeSort([2])
    merge([1], [2])
  mergeSort([3,4,5])
    mergeSort([3])
    mergeSort([4,5])
      mergeSort([4])
      mergeSort([5])
      merge([4], [5])
    merge([3], [4,5])
  merge([1,2], [3,4,5])
Sorted Array: [ 1, 2, 3, 4, 5 ]
"""

# Test Case 5: Random Unsorted Array
arr5 = [7, 2, 5, 1, 3, 8]
print("Sorted Array:", mergeSort(arr5))  # Expected Output: [1, 2, 3, 5, 7, 8]

"""
Expected Output for Test Case 5:
mergeSort([7,2,5,1,3,8])
  mergeSort([7,2,5])
    mergeSort([7])
    mergeSort([2,5])
      mergeSort([2])
      mergeSort([5])
      merge([2], [5])
    merge([7], [2,5])
  mergeSort([1,3,8])
    mergeSort([1])
    mergeSort([3,8])
      mergeSort([3])
      mergeSort([8])
      merge([3], [8])
    merge([1], [3,8])
  merge([2,5,7], [1,3,8])
Sorted Array: [ 1, 2, 3, 5, 7, 8 ]
"""
