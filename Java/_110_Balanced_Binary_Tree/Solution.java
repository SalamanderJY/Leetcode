/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public boolean balanced = true;
    
    public boolean isBalanced(TreeNode root) {
        maxDepth(root);
        return balanced;
    }
    
    
    public int maxDepth(TreeNode root) {
        if (root == null)
            return 0;
        else
        {
            int leftDepth = maxDepth(root.left) + 1;
            int rightDepth = maxDepth(root.right) + 1;
            if (Math.abs(leftDepth - rightDepth) > 1)
                balanced = false;
            return Math.max(leftDepth, rightDepth);
        }
    }
}