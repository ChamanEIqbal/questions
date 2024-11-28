"""
In a far-off kingdom, an ancient artifact known as the "Crown of Numeria" is said to grant the wearer 
extraordinary powers. To claim the crown, a hero must pass the "Trial of Recursion," 
where they must calculate the factorial of a mysterious number 
using the ancient formula passed down through generations. (2 * n!, a secret untill...)

Legend has it that the trial is tricky, with hidden errors woven into the code of the artifact's 
security system. Only by understanding the intricate recursive structure can the hero overcome these 
errors and unlock the crown's power. The first hero to fix the bugs will be granted the Crown of Numeria 
and the title of Grand Sage.

An old wise man has come to you, and said; that the Trial of Recursion is (2 * n!)
BEWARE, THE OLD MAN'S ADVICE IS TRUTHFUL!
"""

def factorial(n)
    if n == 0 or n == 1:
        return 0
    else
        n = 2 * n + factorial(n - 1) 


print(factorial(5))  # Expected: 240
