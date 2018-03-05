class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t): 
            return False
        n = len(s)
        counts = [0] * 26
        for i in range(0, n):
            counts[ord(s[i]) - ord('a')] += 1
            counts[ord(t[i]) - ord('a')] -= 1
        for i in range(0, 26):
            if counts[i] > 0:
                return False
        return True
