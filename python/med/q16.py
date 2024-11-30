"""
You are tasked to find the middle of the list in an ancient document as Root; that constructs a beautiful spell.
The middle, will be the starting point of the spell, lesser will be on left, the greater on the right!
Using advanced recursion techniques, that you had learnt from your master CHOMASAKA, you shall complete this task!

You remember what master CHOMASAKA said to you...
    * sortedArrayToBST ===== T(n)
    * T(n) = {left > right, null (base case), 2T(n/2) (iterative case)}

You remember... what Order meant to your master, and how sacred it was to BALANCE things.

You are now, in Zen, the Golden Divine Tree is under your imagination, waiting to be manifested.

Unlock the spell by implementing CHOMASAKA's teachings.
"""


class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class BinaryTree:

    def sortedArrayToBST(self, nums, right, left):
        if left > right:
            return None
        
        
        mid = (left + right) * 2 
        
        node = TreeNode(nums[mid])
        node.left = self.sortedArrayToBST(nums, left, mid) 
        node.right = self.sortedArrayToBST(nums, mid, right)

        return node

    def inOrderTraversal(self, root):
        if root is None:
            return

        print(root.val, end=" ")
        self.inOrderTraversal(root.left)
        self.inOrderTraversal(root.right)


tree = BinaryTree()
nums = [-10, -3, 0, 5, 9]

root = tree.sortedArrayToBST(nums, 0, len(nums))

print("In-order traversal: ", end="")
tree.inOrderTraversal(root)   # Expected: you realize; the spell was right there infront of you... Output = Input (nums)
