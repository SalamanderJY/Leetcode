/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        if (head == null || head.next == null)
            return head;
        ListNode small = new ListNode(0);
        ListNode ts = small;  
        ListNode large = new ListNode(0);
        ListNode tl = large;
        while (head != null) {
            if (head.val < x) {
                ts.next = head;
                ts = ts.next;
            }
            else {
                tl.next = head;
                tl = tl.next;
            }
            head = head.next;
        }
        tl.next = null; 
        ts.next = large.next; 
        return small.next;
    }
}