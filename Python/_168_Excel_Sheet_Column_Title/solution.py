class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = ""
        while n > 0:
            n -= 1
            res = chr(n % 26 + 65) + res
            n //= 26
        return res