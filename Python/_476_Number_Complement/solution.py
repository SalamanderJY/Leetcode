class Solution:
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        # python int 64 bit
        i = 1
        while i <= num:
            i <<= 1
        return (i - 1) ^ num
