class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        sign = -1 if (1 if dividend > 0 else 0) ^ (1 if divisor > 0 else 0) > 0 else 1
        res = 0
        m = abs(dividend)
        n = abs(divisor)
        while m >= n:
            temp, i = n, 1
            while (temp << 1) < m:
                temp <<= 1
                i <<= 1
            m -= temp
            res += i
        if sign < 0:
            res = -res
        return res if res <= 2147483647 else 2147483647
