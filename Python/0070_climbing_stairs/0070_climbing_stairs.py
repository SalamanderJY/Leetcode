class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        dp = [0 for i in range(0, n + 2)]
        dp[0] = 1
        dp[1] = 2
        dp[2] = 3
        for i in range(3, n):
            dp[i] = dp[i - 1] + dp[i - 2]
        return dp[n - 1]