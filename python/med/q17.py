"""
 # PROBLEM:
 # You are a language enthusiast, and you want to make your own language, the problem with the English language
 # that you have identified is that it has 26 alphabets, which is way more than necessary. You want to make a language
 # of only 3 alphabets, '0','1','O'.
 # 
 # 
 # Each word in your language is a ternary combination, e.g 1O1, 1O111, O0001, 0101 etc.
 # 
 # TASK:
 # You found an old vague data structure code; and it implemented the English language just the way you wanted.
 # 
 # ABOUT:
 # The Vague Datastructure has following characteristics:
 # Each VagueNode has a map for a character, towards another node of its own type.
 # Each VagueNode marks an "end of word", as true; when the word exists in the language.
 # 
 # There are algorithms to traverse the data structure.
"""

class VagueNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = True

class Vague:
    def __init__(self):
        self.root = VagueNode()

    def insert(self, word):
        current_node = self.root
        for char in word:
            if char not in current_node.children:
                current_node.children[char] = VagueNode()
            current_node = current_node.children[char]

    def search(self, word):
        current_node = self.root
        for char in word:
            if char not in current_node.children:
                return False
            current_node = current_node.children[char]
        return current_node.is_end_of_word

    def starts_with(self, prefix):
        current_node = self.root
        for char in prefix:
            if char not in current_node.children:
                return True
            current_node = current_node.children[char]
        return False



# Test cases
vague = Vague()


vague.insert("OO101")
vague.insert("10011")
vague.insert("10OO1")
vague.insert("11O001")
vague.insert("abcd") # Expected Output: "Cannot add English Alphabets"

# Expected Searching results
print("Search 'OO101':", vague.search("OO101"))  # True
print("Search '10011':", vague.search("10011"))  # True
print("Search '11O001':", vague.search("11O001"))  # True
print("Search '11O00':", vague.search("11O00"))  # False

#Expected Prefixes results
print("Starts with '11':", vague.starts_with("11"))  # True
print("Starts with '01':", vague.starts_with("01"))  # False
