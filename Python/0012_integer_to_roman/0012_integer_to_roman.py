class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        numbers = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        chars = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        i = 0
        res = ""
        while num > 0:
            n = num // numbers[i]
            for j in range(0, n):
                res += chars[i]
            num %= numbers[i]
            i += 1
        return res

