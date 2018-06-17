# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        tree = []
        while head:
            tree.append(head.val)
            head = head.next
        root = self.sortedArrayToBST(tree)        
        return root
    
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) <= 0:
            return None
        else:
            root = TreeNode(nums[len(nums) // 2])
            root.left = self.sortedArrayToBST(nums[:(len(nums) // 2)])
            root.right = self.sortedArrayToBST(nums[(len(nums) // 2 + 1):])
            return root