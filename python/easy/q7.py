"""
# You are a space explorer on a mysterious planet, and the key to unlocking the treasure chamber
# is ensuring the name of the chamber is a palindrome. However, the robot is making some errors.
# Help the robot by fixing the palindrome checking logic!
"""
def is_palindrome(s):
    left = 0
    right = len(s) - 1


    while left > right:
        if s[left] != s[right]: 
            return False 
        left += 1
    return True  

word = "raceCar"
print(is_palindrome(word))  # Expected: True or "Palindrome"
