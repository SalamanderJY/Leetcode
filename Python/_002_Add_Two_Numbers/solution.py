# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        p, q = l1, l2
        cur = dummy
        carry = 0
        while p or q:
            x = p.val if p else 0
            y = q.val if q else 0
            total = carry + x + y
            carry = total // 10
            cur.next = ListNode(total % 10)
            cur = cur.next
            if p:
                p = p.next
            if q:
                q = q.next
        if carry > 0:
            cur.next = ListNode(carry)
        return dummy.next
