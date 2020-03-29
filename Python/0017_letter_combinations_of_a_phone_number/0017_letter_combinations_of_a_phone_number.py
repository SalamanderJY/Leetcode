class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) == 0:
            return []
        mapping = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        res = [""]
        for i in range(len(digits)):
            temp = []
            for j in range(len(res)):
                for k in range(len(mapping[ord(digits[i]) - ord('0')])):
                    temp.append(res[j] + mapping[ord(digits[i]) - ord('0')][k])
            res = temp
        return res

