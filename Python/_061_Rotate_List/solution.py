# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        length = 0
        it = head
        while it != None:
            length += 1
            it = it.next
        if k > length and length != 0:
            k %= length    
        if k == 0 or k == length or length == 0:
            return head
        fast = head
        while k > 1:
            fast = fast.next
            k -= 1
        slow = head
        prevslow = None
        while fast.next != None:
            fast = fast.next
            prevslow = slow
            slow = slow.next
        prevslow.next = None
        fast.next = head
        head = slow
        return head
