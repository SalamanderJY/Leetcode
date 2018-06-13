# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        return self.helper(inorder, 0, len(inorder) - 1, postorder, 0, len(postorder) - 1)
        
    def helper(self, inorder, inStart, inEnd, postorder, postStart, postEnd):
        if inStart > inEnd or postStart > postEnd:
            return None
        rootVal = postorder[postEnd]
        rootIndex = 0
        for i in range(inStart, inEnd + 1):
            if inorder[i] == rootVal:
                rootIndex = i
                break
        length = rootIndex - inStart
        root = TreeNode(rootVal)
        root.left = self.helper(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + length - 1)
        root.right = self.helper(inorder, rootIndex + 1, inEnd, postorder, postStart + length, postEnd - 1)    
        return root
