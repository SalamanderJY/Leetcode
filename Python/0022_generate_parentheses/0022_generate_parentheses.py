class Solution:
    def generateParentheses(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        self.addParentheses(result, "", n, 0)
        return result
        
    def addParentheses(self, result, string, notAdd, notMatch):
        if notMatch == 0 and notAdd == 0:
            result.append(string)
            return
        if notMatch > 0:
            self.addParentheses(result, string + ')', notAdd, notMatch - 1)
        if notAdd > 0:
            self.addParentheses(result, string + '(', notAdd - 1, notMatch + 1)

