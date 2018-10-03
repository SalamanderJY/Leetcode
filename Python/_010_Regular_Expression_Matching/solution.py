class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        if len(p) == 0: 
            return len(s) == 0
        if len(p) == 1:
            return len(s) == 1 and (s[0] == p[0] or p[0] == '.')
        if p[1] != '*':
            if len(s) == 0:
                return False
            return (s[0] == p[0] or p[0] == '.') and self.isMatch(s[1:], p[1:])
        while len(s) != 0 and (s[0] == p[0] or p[0] == '.'):
            if self.isMatch(s, p[2:]):
                return True
            s = s[1:]
        return self.isMatch(s, p[2:])
    '''
    def isMatch(self, s, p):
        m = len(s)
        n = len(p)
        dp = [[False for j in range(n + 1)] for i in range(m + 1)]

        dp[0][0] = True

        for i in range(0, m + 1):
            for j in range(1, n + 1):
                if i > 0  and (p[j - 1] == s[i - 1] or p[j - 1] == "."):
                    dp[i][j] = dp[i - 1][j - 1]

                elif p[j - 1] == "*":
                    dp[i][j] = dp[i][j - 2]

                    if not dp[i][j] and i > 0 and (p[j - 2] == s[i - 1] or p[j - 2] == "."):
                        dp[i][j] = dp[i - 1][j]

        return dp[m][n]
    '''