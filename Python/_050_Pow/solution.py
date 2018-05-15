class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        temp = n
        if temp == 0:
            return 1
        elif temp < 0:
            temp = -temp
            x = 1.0 / x;
        elif temp == 1:
            return x
        return self.myPow(x * x, temp >> 1) * (1 if n % 2 == 0 else x)
