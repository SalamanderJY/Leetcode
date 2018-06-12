# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        res = [] 
        level = [root]
        level_num = 1
        while root and level:
            if level_num % 2 == 1:
                res.append([node.val for node in level])
            else:
                temp = [node.val for node in level]
                res.append(temp[::-1])
            level = [kid for node in level for kid in (node.left, node.right) if kid]
            level_num += 1
        return res
