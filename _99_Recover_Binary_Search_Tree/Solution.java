package _99_Recover_Binary_Search_Tree;


//Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
 }

public class Solution {
    private TreeNode first = null;
    private TreeNode second =null;
    private TreeNode prev = null;
    Integer last = Integer.MIN_VALUE;

    public void recoverTree(TreeNode root) {
        
        InOrder(root);
        //swap
        int temp;
        temp = first.val;
        first.val = second.val;
        second.val = temp;
        
    }  
        
    public void InOrder(TreeNode root) {
        if(root == null){
            return ;
        }
        InOrder(root.left);
        if(root.val < last) {
            if(first == null) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        last = prev.val;
        InOrder(root.right);
    }
}