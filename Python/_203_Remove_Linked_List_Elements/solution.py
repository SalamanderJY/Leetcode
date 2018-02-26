# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        fakeHead = ListNode(0)
        fakeHead.next = head
        curr = head
        prev = fakeHead
        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = prev.next
            curr = curr.next
        return fakeHead.next
