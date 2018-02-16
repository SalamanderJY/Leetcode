# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.balanced = True
    
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.maxDepth(root)
        return self.balanced
        
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        else:
            left_depth = self.maxDepth(root.left) + 1
            right_depth = self.maxDepth(root.right) + 1
            if abs(left_depth - right_depth) > 1:
                self.balanced = False
            return max(left_depth, right_depth)
