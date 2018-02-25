class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        elif n == 1:
            return nums[0]
        else:
            dp = [] 
            dp.append(nums[0])
            dp.append(max(nums[0], nums[1]))
            for i in range(2, n):
                dp.append(max(dp[i - 2] + nums[i], dp[i - 1]))
            return max(dp[n - 1], dp[n - 2])
