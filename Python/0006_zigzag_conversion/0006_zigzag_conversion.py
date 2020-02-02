class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        result = [str("")] * numRows
        i = 0;
        j = 0;
        back = numRows - 2
        while i < len(s):
            for j in range(len(s)):
                if j < numRows and i < len(s):
                    result[j] += s[i]
                    i += 1
                else:
                    break
            for j in reversed(range(1, back + 1)):
                if j > 0 and i < len(s):
                    result[j] += s[i]
                    i += 1
                else:
                    break
        for i in range(numRows - 1):
            result[0] += result[i + 1]    
        return result[0]
