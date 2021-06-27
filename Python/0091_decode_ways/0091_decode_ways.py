class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0    
        dp = [0 for i in range(len(s) + 1)]
        dp[0] = 1
        if s[0] != '0':
            dp[1] = 1    
        for i in range(1, len(s)):
            if s[i] != '0':
                dp[i + 1] = dp[i]
            if (s[i - 1] == '1' and ord(s[i]) <= ord('9')) or (s[i - 1] == '2' and ord(s[i]) <= ord('6')):
                dp[i + 1] += dp[i - 1]
        return dp[len(s)]
