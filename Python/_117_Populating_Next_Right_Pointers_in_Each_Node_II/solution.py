# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        tmpRoot = root
        while tmpRoot:
            cur = tmpRoot
            dummy = TreeLinkNode(0)
            tmp = dummy
            while cur:
                if cur.left:
                    tmp.next = cur.left
                    tmp = tmp.next
                if cur.right:
                    tmp.next = cur.right
                    tmp = tmp.next
                cur = cur.next      
            tmpRoot = dummy.next
