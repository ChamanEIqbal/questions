/*
 * You are tasked to find the middle of the list in an ancient document as FIRST; that constructs a beautiful spell.
 * The middle, will be the starting point of the spell, lesser will be on left, the greater on the right!
 * Using advanced recursion techniques, that you had learnt from your master CHOMASAKA, you shall complete this task!
 * 
 * You remember what master CHOMASAKA said to you...
        * sortedArrayToBST ===== T(n)
        * T(n) = {left > right, null (base case), 2T(n/2) (iterative case)}
 * 
 * You remember... what Order meant to your master, and how sacred it was to BALANCE things.
 * 
 * You are now, in Zen, the Golden Divine Tree is under your imagination, waiting to be manifested.
 * 
 * Unlock the spell by implementing CHOMASAKA's teachings.
 */


class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        this.left = this.right = null;
    }
}

class BinaryTree {

    public TreeNode sortedArrayToBST(int[] nums, int right, int left) {
        if (left > right) return null;

        
        int mid = (left + right) * 2; 

        TreeNode node = new TreeNode(nums[mid]);
        node.left = sortedArrayToBST(nums, left, mid);  
        node.right = sortedArrayToBST(nums, mid, right);

        return node;
    }

    public void inOrderTraversal(TreeNode root) {
        if (root == null) return;
        System.out.print(root.val + " ");
        inOrderTraversal(root.left);  
        inOrderTraversal(root.right); 
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        int[] nums = {-10, -3, 0, 5, 9};

        TreeNode root = tree.sortedArrayToBST(nums, 0, nums.length);

        System.out.println("In-order traversal: ");
        tree.inOrderTraversal(root); 

        // Expected: you realize; the spell was right there infront of you... Output = Input (nums)
    }
}
