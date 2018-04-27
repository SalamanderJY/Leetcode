# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        pre = dummy
        while pre.next != None and pre.next.next != None:
            temp = pre.next.next
            pre.next.next = temp.next
            temp.next = pre.next
            pre.next = temp
            pre = temp.next      
        return dummy.next
