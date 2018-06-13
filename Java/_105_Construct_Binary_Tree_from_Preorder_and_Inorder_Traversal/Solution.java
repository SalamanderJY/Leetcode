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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }
    
    public TreeNode buildTree(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd) {
        if (inStart > inEnd || preStart > preEnd)
            return null;
        int rootVal = preorder[preStart];
        int rootIndex = 0;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }
        int len = rootIndex - inStart;
        TreeNode root = new TreeNode(rootVal);
        root.left = buildTree(preorder, preStart + 1, preStart + len, inorder, inStart, rootIndex - 1);
        root.right = buildTree(preorder, preStart + len + 1, preEnd, inorder, rootIndex + 1, inEnd);
        
        return root;
    }
}
