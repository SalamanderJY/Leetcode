class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        # n = 3^m
        temp = math.log10(n) / math.log10(3)
        if temp.is_integer():
            return True
        return False