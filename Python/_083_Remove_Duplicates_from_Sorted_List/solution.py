# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        current = head
        while current.next != None:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next
        
        return head
