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
            ListNode temp1 = pre.next
            ListNode temp2 = pre.next.next
            pre.next = temp2
            temp1.next = temp2.next
            temp2.next = temp1
            pre = pre.next.next   
        return dummy.next
