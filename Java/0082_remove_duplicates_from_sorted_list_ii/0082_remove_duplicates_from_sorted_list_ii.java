/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode current = head;
        ListNode prev = dummy;
        
        while (current != null && current.next != null) {
            int count = 1;
            while (current.next != null && current.val == current.next.val) {
                current = current.next;
                count++;
            }
            if (count == 1) {
                prev = current;
                current = current.next;
            }
            else {
                current = current.next;
                prev.next = current;
            }
        }
        return dummy.next;
    }
}