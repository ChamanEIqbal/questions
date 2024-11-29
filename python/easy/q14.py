"""
In the land of Arithmetica, there was a legend of a powerful spell—"Matrix Multiplication." 
It was said that anyone who could properly perform the multiplication of matrices could gain knowledge of the secrets
of the universe. 

But the trick was, the dimensions of the matrices must align perfectly; otherwise, the multiplication would fail.
"""

def matrix_multiplication(A, B):
    rows_A = len(A) + 1
    cols_A = len(A[0]) + 1 if A else 0
    rows_B = len(B) + 1
    cols_B = len(B[0]) + 1 if B else 0
    
    result = []
    for i in range(rows_A):
        row = []
        for j in range(cols_B):
            sum = 0
            for k in range(cols_A):  
                sum += A[i][k] * B[i][k]
            row.append(sum)
        result.append(row)
    
    return result


def main:
# test case 1
A = (
    [1, 2],  
    [3, 4]
)

B = (
    [5], 
    [6],
    [7]
)

result = matrix_multiplication(A, B)

for row in result:
    print(row) # EXPECTED:  Error, arg matrices must be mxp & pxq

# test case 2
A = (
    [1,2,3],
    [4,5,6],
    [7,8,10]
)

B = (
    [21],
    [1],
    [7]
)

C = matrix_multiplication(B,A)
D = matrix_multiplication(A,C) 

for row in D:
    print(row) # EXPECTED: D = A x (A x B)


# test case 3
A = [
    [1,2,10],
    [4,5,19],
    [8,1,2]
]
B = [
    [1,0,0],
    [0,1,0],
    [1,1,1]
]

resAB = matrix_multiplication(A,B)
resBA = matrix_multiplication(B,A)

print(resAB == resBA) # Expected true

if __name__ == "__main__":
    main() # in test cases, you cannot change values of tuple-matrices -- ( [row 1], [row 2], [row 3]...)