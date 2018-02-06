class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        for i in range(0, len(digits))[::-1]:
            if digits[i] == 9: 
                digits[i] = 0
            else:
                digits[i] += 1
                return digits
        if digits[0] == 0:
            digits = [1] + digits
        return digits
