# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        dummyEnd = head
        for i in range(k):
            if dummyEnd == None:
                return head
            dummyEnd = dummyEnd.next
            
        def reverse(start, dummyEnd):
            prev = dummyEnd
            while start != dummyEnd:
                temp = start.next
                start.next = prev
                prev = start
                start = temp
            return prev
        
        newHead = reverse(head, dummyEnd)
        head.next = self.reverseKGroup(dummyEnd, k)
        return newHead    

