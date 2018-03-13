class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        low, high = 1, num
        while low <= high:
            mid = (low + high) >> 1
            if mid * mid == num: 
                return True
            elif mid * mid < num:
                low = int(mid) + 1
            else:
                high = int(mid) - 1
        return False
