class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        maximum = nums[0]
        index = 0
        while index <= maximum and index < len(nums):
            if index + nums[index] > maximum:
                maximum = index + nums[index]
            index += 1
        return True if maximum >= len(nums) - 1 else False

