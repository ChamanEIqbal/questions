
"""
     # The ancient alien technique "Ja'mael" allows merging and sorting star maps in a continuous motion.
     # Your task is to use this method to merge the maps into one sorted array.
     # However, the robot's code has a few flaws in implementing Ja'mael.
     # Strangely... the galliard module inside the robot is similar to a sorting algorithm you know...
"""
# std algorithms will cost 12% of the marks

def jamael_technique(A, B):
    n = len(A) - 1 
    m = len(B) - 1 
    result = [0] * (n + m + 1)

    i = 0
    j = 0
    k = 0
    while i < n & j < m: 
        result[k] = A[i]
        k += 1
        result[k] = B[j]
        k += 1
        i += 1
        j += 1

    while i < n:
        result[k] = A[i]
        k += 1
        i += 1
    while j < m:
        result[k] = B[j]
        k += 1
        j += 1

    galliard(result)
    return result

def galliard(array):
    for i in range(len(array)): 
        key = array[i]
        j = i

        while j > 0 and array[j] > key
            array[j] = array[j + 1] 
            j -= 1
        array[j] = key

def main():
    ArraysA = [
        [1,3,56,23,45],
        [2,68,77,23,1],
        [3,2,54,11,19],
        [2,3,6,5,300000],
        []
    ]

    ArraysB = [
        [1,3,4,68,77,23,1],
        [2,3,4,3,2,1,8],
        [1,1,3,5,7],
        [2,3,4,5,1],
        []
    ]

    for i in range(len(ArraysA)):
        merged = jamael_technique(ArraysA[i], ArraysB[i])
        print(merged)  

# EXPECTED: merged and sorted arrays
if __name__ == "__main__":
    main()
