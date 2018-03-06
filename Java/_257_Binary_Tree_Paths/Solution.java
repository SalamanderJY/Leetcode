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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result = new ArrayList<String>();
        if (root == null) return result;
        dfs(root, result, "");
        return result;
    }

    private void dfs(TreeNode root, List<String> result, String path) {
        if (root == null) return;
        path += (path.length() == 0 ? "" : "->") + root.val;
        if (root.left == null && root.right == null) {
            result.add(path);
            return;
        }
        dfs(root.left, result, path);
        dfs(root.right, result, path);
    }
}
