# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.dfs(root, 0)
        
    def dfs(self, root, res):
        if not root:
            return 0
        res = 10 * res + root.val
        if not root.left and not root.right:
            return res
        return self.dfs(root.left, res) + self.dfs(root.right, res)
