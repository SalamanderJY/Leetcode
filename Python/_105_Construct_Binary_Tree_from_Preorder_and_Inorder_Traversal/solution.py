# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        return self.helper(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1)
        
    def helper(self, preorder, preStart, preEnd, inorder, inStart, inEnd):
        if inStart > inEnd or preStart > preEnd:
            return None
        rootVal = preorder[preStart]
        rootIndex = 0
        for i in range(inStart, inEnd + 1):
            if inorder[i] == rootVal:
                rootIndex = i
                break
        length = rootIndex - inStart
        root = TreeNode(rootVal)
        root.left = self.helper(preorder, preStart + 1, preStart + length, inorder, inStart, rootIndex - 1)
        root.right = self.helper(preorder, preStart + length + 1, preEnd, inorder, rootIndex + 1, inEnd)    
        return root

