/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummyEnd = head;
        for (int i = 0; i < k; i++) {
            if (dummyEnd == null) {
                return head;
            }
            dummyEnd = dummyEnd.next;
        }
        ListNode newHead = reverse(head, dummyEnd);
        head.next = reverseKGroup(dummyEnd, k);
        return newHead;
    }
    
    public ListNode reverse(ListNode start, ListNode dummyEnd) {
        ListNode prev = dummyEnd;
        while (start != dummyEnd) {
            ListNode temp = start.next;
            start.next = prev;
            prev = start;
            start = temp;
        }
        return prev;
    }
}
