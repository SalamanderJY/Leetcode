package _328_Odd_Even_Linked_List;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

public class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null) {
            return null;
        }
        
        ListNode odd = head;
        ListNode oddHead = head;
        ListNode even = head.next;
        ListNode evenHead = head.next;
        
        while(odd.next != null && even.next != null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = evenHead;
        return oddHead;
    }
}
