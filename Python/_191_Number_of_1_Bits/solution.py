class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = 0
        for i in range(0, 32):
            if n & 1 > 0:
                result += 1
            n >>= 1
        return result
