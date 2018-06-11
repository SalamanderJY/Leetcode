# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def helper(root, minimum, maximum):
            if not root:
                return True
            if root.val >= maximum or root.val <= minimum:
                return False
            return helper(root.left, minimum, root.val) and helper(root.right, root.val, maximum)
        return helper(root, -math.inf, math.inf)
