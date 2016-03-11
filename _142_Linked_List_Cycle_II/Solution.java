package _142_Linked_List_Cycle_II;

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = null;
        ListNode slow = null;
        ListNode prev = null;
        ListNode back = null;
        
        fast = head;
        slow = head;
        prev = head;
        if(head == null)
          return null;
        boolean meet = false;
        while(!meet) {
            if(fast.next != null){
                if(fast.next.next != null){
                    fast = fast.next.next;
                }
                else{
                    return null;
                }
            }
            else{
                return null;
            }
            slow = slow.next;
            if(fast == slow){
                back = fast;
                break;
            }
        }
        
        while(!meet) {
            if(prev != back) {
                prev = prev.next;
                back = back.next;
            }
            else{
                break;
            }
        }
        return prev;
    }
}