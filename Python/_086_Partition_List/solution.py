# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        if head == None or head.next == None:  
            return head 
        small = ListNode(0) 
        ts = small  
        large = ListNode(0) 
        tl = large  
        while head != None: 
            if head.val < x:  
                ts.next = head 
                ts = ts.next  
            else:
                tl.next = head
                tl = tl.next 
            head = head.next    
        tl.next = None  
        ts.next = large.next 
        return small.next
