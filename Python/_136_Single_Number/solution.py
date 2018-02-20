class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        for i in range(0, len(nums)):
            result ^= nums[i]
        return result
