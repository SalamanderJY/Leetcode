class Solution:
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """      
        def backtracking(s, pos, path, res):
            if pos == len(s):
                res.append(path)
                return
            for i in range(pos, len(s)):
                substr = s[pos:i + 1]
                if substr == substr[::-1]:
                    backtracking(s, i + 1, path + [substr], res)
        path, res = [], []
        backtracking(s, 0, path, res);
        return res
    