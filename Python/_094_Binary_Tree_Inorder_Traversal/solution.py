# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # Recursive Method
        # def dfs(root):
        #     if not root:
        #         return
        #     dfs(root.left)
        #     res.append(root.val)
        #     dfs(root.right)
        #     return
        # res = []
        # dfs(root)
        # return res
        
        # Iterative Method
        res, stack = [], []
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            res.append(root.val)
            root = root.right
        return res

