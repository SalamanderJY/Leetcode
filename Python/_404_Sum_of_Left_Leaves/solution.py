# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def __init__(self):
        self.sum = 0
    
    
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.helper(root, False)
        return self.sum
    
    def helper(self, root, isleft):
        if not root:
            return
        if isleft and not root.left and not root.right:
            self.sum += root.val
        self.helper(root.left, True)
        self.helper(root.right, False)



