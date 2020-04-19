# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head == None or n <= 0:
            return None  
        tempHead = ListNode(0)
        tempHead.next = head
        first = tempHead
        second = tempHead
        i = 0
        while i < n:
            second = second.next
            i += 1
        while second.next != None:
            first = first.next
            second = second.next
        first.next = first.next.next  
        return tempHead.next

