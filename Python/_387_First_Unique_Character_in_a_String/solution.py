class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = [0] * 128
        for i in range(0, len(s)):
            count[ord(s[i]) - ord('a')] += 1
        for i in range(0, len(s)):
            if count[ord(s[i]) - ord('a')] == 1:
                return i
        return -1
