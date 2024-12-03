class Node:
    def __init__(self, name, is_file):
        self.name = name
        self.is_file = is_file
        self.children = []

class FileSystem:
    def __init__(self):
        self.root = Node("/", False)
        self.current = self.root

    def create_directory(self, dir_name):
        self.current.children.append(Node(dir_name, False))
        print(f"Directory created: {dir_name}")

    def add_file(self, file_name):
        self.current.children.append(Node(file_name, True))
        print(f"File added: {file_name}")

    def delete_entry(self, name):
        found = False
        for i, child in enumerate(self.current.children):
            if child.name == name and child.is_file:
                del self.current.children[i]
                print(f"Entry deleted: {name}")
                found = True
                break
        if not found:
            print(f"Entry not found: {name}")

    def change_directory(self, dir_name):
        for child in self.current.children:
            if child.name == dir_name and not child.is_file:
                self.current = child
                print(f"Changed directory to: {dir_name}")
                return
        print(f"Directory not found: {dir_name}")

    def display_tree(self, node, depth):
        print("-" * depth + node.name)
        for child in node.children:
            self.display_tree(child, depth + 1)

    def display(self):
        self.display_tree(self.current, 0)

# Test Cases
fs = FileSystem()

print("\nTest Case 1: Create Directories and Display")
fs.create_directory("Dir1")
fs.create_directory("Dir2")
fs.display()
# Expected Output:
# /
# -Dir1
# -Dir2

print("\nTest Case 2: Add Files and Display")
fs.add_file("File1.txt")
fs.add_file("File2.txt")
fs.display()
# Expected Output:
# /
# -Dir1
# -Dir2
# -[File] File1.txt
# -[File] File2.txt

print("\nTest Case 3: Create Duplicate Entries")
fs.create_directory("Dir1")
fs.add_file("File1.txt")
fs.display()
# Expected Output:
# Duplicate directory/file names should not be allowed.

print("\nTest Case 4: Delete Directory")
fs.delete_entry("Dir1")
fs.display()
# Expected Output:
# /
# -Dir2
# -[File] File1.txt
# -[File] File2.txt

print("\nTest Case 5: Change Directory")
fs.change_directory("Dir2")
fs.create_directory("SubDir1")
fs.display()
# Expected Output:
# Dir2
# -SubDir1
