class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        result = 0
        for i in range(15, -1, -1):
            if (result + (1 << i)) * (result + (1 << i)) <= x:
                result += (1 << i)
        return result
