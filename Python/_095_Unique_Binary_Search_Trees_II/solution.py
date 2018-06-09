# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def helper(left, right):
            res = []
            if left > right:
                res.append(None)
                return res
            for i in range(left, right + 1):
                leftList = helper(left, i - 1)
                rightList = helper(i + 1, right)
                for j in range(0, len(leftList)):
                    for k in range(0, len(rightList)):
                        root = TreeNode(i)
                        root.left = leftList[j]
                        root.right = rightList[k]
                        res.append(root)
            return res
        if n < 1:
            return []
        return helper(1, n)
