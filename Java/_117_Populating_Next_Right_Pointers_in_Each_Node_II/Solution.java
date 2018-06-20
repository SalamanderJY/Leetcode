/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void connect(TreeLinkNode root) {
        TreeLinkNode tmpRoot = root;    
        while (tmpRoot != null) {
            TreeLinkNode cur = tmpRoot;
            TreeLinkNode dummy = new TreeLinkNode(0);
            TreeLinkNode tmp = dummy;
            while (cur != null) {
                if (cur.left != null) {
                    tmp.next = cur.left;
                    tmp = tmp.next;
                }
                if (cur.right != null) {
                    tmp.next = cur.right;
                    tmp = tmp.next;
                }
                cur = cur.next;
            }          
            tmpRoot = dummy.next;
        }
    }
}