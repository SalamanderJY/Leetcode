/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        int length = 0;
        ListNode it = head;
        while (it != null) {
            length++;
            it = it.next;
        }        
        if ( k > length && length != 0)
            k %= length;     
        if ( k == 0 || k == length || length == 0)
            return head;   
        ListNode fast = head; 
        while (k > 1) {
            fast = fast.next;
            k--;
        }
        ListNode slow = head, prevslow = null;
        while (fast.next != null) {
            fast = fast.next;
            prevslow = slow;
            slow = slow.next;
        }
        prevslow.next = null;
        fast.next = head;
        head = slow;
        return head;
    }
}