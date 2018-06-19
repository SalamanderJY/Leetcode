# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        curr = root
        while curr:
            if curr.left:
                temp = curr.left
                while temp.right:
                    temp = temp.right
                temp.right = curr.right
                curr.right = curr.left
                curr.left = None
            curr = curr.right