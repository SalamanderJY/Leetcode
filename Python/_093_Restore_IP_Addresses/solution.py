class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        self.backtracking(s, 0, "", res)
        return res
        
    def backtracking(self, s, index, path, res):
        if index == 4:
            if not s:
                res.append(path[0 : len(path) - 1])
            return
        for i in range(1, 4):
            if i <= len(s):
                if i == 1:
                    self.backtracking(s[i:], index + 1, path + s[:i] + ".", res)
                elif i == 2 and s[0] != '0':
                    self.backtracking(s[i:], index + 1, path + s[:i] + ".", res)
                elif i == 3 and s[0] != '0' and int(s[:3]) < 256:
                    self.backtracking(s[i:], index + 1, path + s[:i] + ".", res)

