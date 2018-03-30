class Solution:
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        i = 1
        j = 0
        dp = [0] * (len(s) + 1)
        while i < len(s): 
            if s[i] == s[j]:
                i += 1
                j += 1
                dp[i] = j
            elif j == 0:
                i += 1
            else:
                j = dp[j]
        return dp[len(s)] > 0 and (dp[len(s)] % (len(s) - dp[len(s)]) == 0)
