class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if not head or m == n:
            return head
        dummy = ListNode(0)
        prev = dummy
        dummy.next = head
        for i in range(m - 1):
            prev = prev.next
        curr = prev.next
        for i in range(0, n - m):
            temp = curr.next
            curr.next = curr.next.next
            temp.next = prev.next
            prev.next = temp
        return dummy.next
