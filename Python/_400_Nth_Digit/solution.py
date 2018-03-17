class Solution:
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        start = 1
        length = 1
        base = 9
        while n // length > base:
            n = n - length * base
            length += 1
            start *= 10
            base *= 10
        target = start + (n - 1) // length
        reminder = (n - 1) % length     
        return int(list(str(target))[reminder])
