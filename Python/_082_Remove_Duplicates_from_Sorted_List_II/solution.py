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
        if head == None or head.next == None:
            return head
        dummy = ListNode(0)
        dummy.next = head
        current = head
        prev = dummy
        
        while current != None and current.next != None:      
            count = 1
            while current.next != None and current.val == current.next.val:
                current = current.next
                count += 1
            if count == 1:
                prev = current
                current = current.next
            else:
                current = current.next
                prev.next = current
        return dummy.next
