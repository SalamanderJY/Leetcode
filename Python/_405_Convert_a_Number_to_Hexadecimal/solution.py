class Solution:
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        element = ['0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f']
        if num == 0: return "0"
        result = ""
        if num < 0: num += 2 ** 32
        while num != 0:
            result = element[(num & 15)] + result
            num >>= 4
        return result

