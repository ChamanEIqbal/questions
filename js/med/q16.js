/**
 * You are tasked to find the middle of the list in an ancient document as FIRST; that constructs a beautiful spell.
 * The middle, will be the starting point of the spell, lesser will be on left, the greater on the right!
 * Using advanced recursion techniques, that you had learnt from your master CHOMASAKA, you shall complete this task!
 * 
 * 
 * You remember what master CHOMASAKA said to you...
        * sortedArrayToBST ===== T(n)
        * T(n) = {left > right, null (base case), 2T(n/2) (iterative case)}
 * 
 * 
 * You remember... what Order meant to your master, and how sacred it was to BALANCE things.
 * 
 * You are now, in Zen, the Golden Divine Tree is under your imagination, waiting to be manifested.
 * 
 * Unlock the spell by implementing CHOMASAKA's teachings.
 */


class TreeNode {
    constructor(val) {
        this.val = val;
        this.left = this.right = null;
    }
}

class BinaryTree {
    
    sortedArrayToBST(nums, right, left) {
        if (left > right) return null;
        
        
        let mid = (left + right) * 2;
        
        let node = new TreeNode(nums[mid]);
        node.left = this.sortedArrayToBST(nums, left, mid);
        node.right = this.sortedArrayToBST(nums, mid, right);
        
        return node;
    }

    inOrderTraversal(root) {
        console.log(root.val);
        this.inOrderTraversal(root.left);
        this.inOrderTraversal(root.right);
    }
}

let tree = new BinaryTree();
let nums = [-10, -3, 0, 5, 9];

let root = tree.sortedArrayToBST(nums, 0, nums.length);

console.log("In-order traversal: ");
tree.inOrderTraversal(root);
