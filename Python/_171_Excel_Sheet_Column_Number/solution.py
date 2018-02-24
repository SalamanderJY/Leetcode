class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 1:
            return ord(s[-1]) - 65 + 1
        return ord(s[-1]) - 65 + 1 + self.titleToNumber(s[:-1]) * 26
        