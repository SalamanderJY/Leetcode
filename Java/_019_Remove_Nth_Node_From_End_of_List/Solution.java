/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || n <= 0)
          return null;   
        ListNode tempHead = new ListNode(0);
        tempHead.next = head;
        ListNode first = tempHead;
        ListNode second = tempHead;
        int i = 0;
        while (i < n) {
            second = second.next;
            i++;
        } 
        while (second.next != null) {
            first = first.next;
            second = second.next;
        }  
        first.next = first.next.next;  
        return tempHead.next;
    } 
}
