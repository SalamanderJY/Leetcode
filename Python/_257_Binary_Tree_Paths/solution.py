# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root):
        if root == None:
            return []
        return self.dfs(root, str(root.val), [])

    def dfs(self, root, val, paths):
        if not root.left and not root.right:
            paths.append(val)
        if root.left:
            paths = self.dfs(root.left, val + "->" + str(root.left.val), paths)
        if root.right:
            paths = self.dfs(root.right, val + "->" + str(root.right.val), paths)
        return paths

