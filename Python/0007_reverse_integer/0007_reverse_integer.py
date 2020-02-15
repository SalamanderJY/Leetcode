class Solution:
    
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if operator.gt(x, 0):
            n = int(str(abs(x))[::-1])
        else:
            n = -1 * int(str(abs(x))[::-1])
            
        return n if n.bit_length() < 32 else 0
