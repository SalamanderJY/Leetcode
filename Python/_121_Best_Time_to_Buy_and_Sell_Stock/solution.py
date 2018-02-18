class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) < 1:
            return 0
        dp = []
        minimum = prices[0]
        maximum = 0
        dp.append(0)
        for i in range(1, len(prices)):
            if prices[i] < minimum:
                minimum = prices[i]
                dp.append(0)
            else:
                dp.append(prices[i] - minimum)
            if maximum < dp[i]:
                maximum = dp[i]
        return maximum
        