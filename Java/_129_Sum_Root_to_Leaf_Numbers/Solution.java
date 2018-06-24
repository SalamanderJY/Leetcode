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
    public int sumNumbers(TreeNode root) {
        return dfs(root, 0);
    }
    
    public int dfs(TreeNode root, int res) {
        if (root == null)
            return 0;
        res = 10 * res + root.val;
        if (root.left == null && root.right == null)
            return res;
        return dfs(root.left, res) + dfs(root.right, res);
    }
}