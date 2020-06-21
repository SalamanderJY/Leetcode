class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) < 2:
            return 0
        max_value = 0
        dp = [0] * len(s)
        for i in range(1, len(s)):
            if (s[i] == ')'):
                if (s[i - 1] == '('):
                    dp[i] = (dp[i - 2] if i >= 2 else 0) + 2
                elif (i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == '('):
                    dp[i] = dp[i - 1] + (dp[i - dp[i - 1] - 2] if (i - dp[i - 1]) >= 2 else 0) + 2
            max_value = max(max_value, dp[i]);
        return max_value

