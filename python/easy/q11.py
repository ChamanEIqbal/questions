"""
There was a curious traveller in Eldoria; wandering around. And found an old sage -- The sage asked him this
question:

# "What is the result of raising a number x to the power of y?" *

"I do not know", said the traveller.

Thus said the sage, the old man:
    "The answer, my dear, lies within the recursive call!"

Lo, the traveller -- Convince me that you art curious; and solve this intriguing puzzle for me.
"""

def power(x, y):
    if y == 1:
        return 0
    
    if(y % 2 == 0):
        return power(x, y - 1) * power(x, y - 1) #  CANNOT REMOVE THIS IF BLOCK
    else:
        return x * power(x, y - 1)

x = 2 
y = 6 

result = power(x, y)
print(f"The result of {x} raised to the power of {y} is {result}.") # expected: 64
