class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        res = []
        win = [0] * 26
        fixwin = [0] * 26
        
        if len(s) == 0 or len(p) == 0 or len(p) > len(s):
            return res
        
        for i in range(len(p)):
            fixwin[ord(p[i]) - ord('a')] += 1
        
        for i in range(len(p)):
            win[ord(s[i]) - ord('a')] += 1
        
        for i in range(len(s)):
            if self.isMatch(fixwin, win):
                res.append(i)
            if i + len(p) < len(s):
                win[ord(s[i]) - ord('a')] -= 1
                win[ord(s[i + len(p)]) - ord('a')] += 1
            else:
                break
        return res
    
    def isMatch(self, fixwin, win):
        for i in range(len(win)):
            if win[i] != fixwin[i]:
                return False
        return True
