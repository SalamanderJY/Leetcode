# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True;
        else:
            return self.isSymmetricHelper(root.left, root.right)
    
    def isSymmetricHelper(self, p, q):
        if not p and not q:
            return True
        elif not p or not q:
            return False
        elif p.val != q.val:
            return False
        else:
            return self.isSymmetricHelper(p.left, q.right) and self.isSymmetricHelper(p.right, q.left)
        