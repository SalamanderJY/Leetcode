class Solution:
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        # 32 bits integer max
        MAX = 0x7FFFFFFF
        # 32 bits interger min
        MIN = 0x80000000
        # mask to get last 32 bits
        mask = 0xFFFFFFFF
        while a != 0:
            x = (a ^ b) & mask
            a = ((a & b) << 1) & mask
            b = x
        return b if b <= MAX else ~(b ^ mask)

