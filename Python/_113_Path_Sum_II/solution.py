# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        def helper(root, sum, res, curr):
            if not root:
                return
            if root.val == sum and (not root.right) and (not root.left):
                curr.append(root.val)
                res.append(curr)
                return
            helper(root.left, sum - root.val, res, curr + [root.val])
            helper(root.right, sum - root.val, res, curr + [root.val])
        res = []
        helper(root, sum, res, [])
        return res
