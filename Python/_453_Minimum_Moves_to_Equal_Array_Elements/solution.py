import math

class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        minimum = math.inf
        res = 0
        for i in range(len(nums)):
            minimum = min(minimum, nums[i])
        for i in range(len(nums)):
            res += nums[i] - minimum
        return res
