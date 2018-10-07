# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        elif l2 is None:
            return l1
        dummy = ListNode(0)
        tail = dummy
        while l1 != None and l2 != None:
            if l1.val < l2.val:
                node = l1
                tail.next = node
                tail = tail.next
                l1 = l1.next
            else:
                node = l2
                tail.next = node
                tail = tail.next
                l2 = l2.next
        tail.next = l1 if l1 != None else l2
        return dummy.next
