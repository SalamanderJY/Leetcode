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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> curr = new ArrayList<Integer>();
        dfs(root, sum, res, curr);
        return res;
    }
    
    public void dfs(TreeNode root, int sum, List<List<Integer>> res, List<Integer> curr) {
        if (root == null)
            return;
        if (root.val == sum && root.right == null && root.left == null) {
            curr.add(root.val);
            res.add(curr);
            return;
        }
        curr.add(root.val);
        dfs(root.left, sum - root.val, res, new ArrayList<Integer>(curr));
        dfs(root.right, sum - root.val, res, new ArrayList<Integer>(curr));
    }
}