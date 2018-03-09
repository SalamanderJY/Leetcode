class Solution:
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        x = str.split(' ')
        lsp = len(set(pattern))
        lsx = len(set(x))
        return len(x)==len(pattern) and lsx==lsp and lsp== len(set(zip(pattern, x)))
