class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maximum = nums[0]
        dp = []
        dp.append(nums[0])
        
        for i in range(1, len(nums)):
            if dp[i-1] > 0:
                dp.append(nums[i] + dp[i-1])
            else:
                dp.append(nums[i])
            maximum = max(dp[i], maximum)

        return maximum

