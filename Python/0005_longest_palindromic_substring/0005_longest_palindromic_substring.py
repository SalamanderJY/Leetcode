class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0:
            return s
        dp = [[False for i in range(len(s))] for j in range(len(s))]
        start = 0
        maximum = 0
        for i in range(len(s)):
            for j in range(0, i + 1):
                if s[i] == s[j] and (i - j <= 2 or dp[j + 1][i - 1]):
                    dp[j][i] = True
                if dp[j][i] and maximum < i - j + 1:
                    maximum = i - j + 1
                    start = j
        return s[start:start + maximum]
