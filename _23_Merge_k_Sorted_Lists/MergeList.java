package _23_Merge_k_Sorted_Lists;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;



public class MergeList {
    public ListNode mergeKLists(ListNode[] lists) {
        Queue<ListNode> heap = new PriorityQueue<ListNode>(new Comparator<ListNode>() {
			@Override
			public int compare(ListNode o1, ListNode o2) {
				// TODO Auto-generated method stub
				return o1.val - o2.val;
			}	
		});
        
        ListNode result = new ListNode(0);
        ListNode temp = result;
        
        for (ListNode listNode : lists) {
			if(listNode != null) {
				heap.add(listNode);
			}
		}
        
        while (!heap.isEmpty()) {
            ListNode cur = heap.poll();
            temp.next = cur;
            if (cur.next != null) {
                heap.add(cur.next);
            }
            temp = temp.next;
        }
               
        return result;
    }
}

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
