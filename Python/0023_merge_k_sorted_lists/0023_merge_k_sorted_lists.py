# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# import heapq

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head = ListNode(0)
        current = head
        heap = []
        for l in lists:
            if l != None:
                heapq.heappush(heap, (l.val, id(l), l))
        while len(heap) > 0:
            val, _, current.next = heapq.heappop(heap)
            current = current.next
            after = current.next
            if after != None:
                heapq.heappush(heap, (after.val, id(after), after))
        return head.next
