package _117_Populating_Next_Right_Pointers_in_Each_Node_II;


class TreeLinkNode {
    int val;
    TreeLinkNode left, right, next;
    TreeLinkNode(int x) { val = x; }
}

 
//You may only use constant extra space
public class Solution {
    public void connect(TreeLinkNode root) {
        TreeLinkNode head = root;
        
        while(head != null) {
            TreeLinkNode curNode = head;
            TreeLinkNode tmpNextHead = new TreeLinkNode(0);
            TreeLinkNode pre = tmpNextHead;

            while(curNode != null) {
                if(curNode.left != null) {
                    pre.next = curNode.left;
                    pre = pre.next;
                }
                if(curNode.right != null) {
                    pre.next = curNode.right;
                    pre = pre.next;
                }
                curNode = curNode.next;
            }
            
            head = tmpNextHead.next;
        }
    }
}
