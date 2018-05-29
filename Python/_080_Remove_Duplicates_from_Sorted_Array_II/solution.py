class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        i = 0
        for j in range(len(nums)):
            if i < 2 or nums[j] > nums[i - 2]:
                nums[i] = nums[j]
                i += 1
        return i
