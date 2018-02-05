class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        start = len(s) - 1
        
        if len(s) <= 0:
            return 0
        
        else:
            for k in range(1, len(s) + 1):
                if s[len(s) - k] == ' ':
                    start -= 1
                else:
                    break
                    
            if start == -1:
                return 0
            
            for i in range(k, len(s) + 1):
                if s[len(s) - i] != ' ':
                    count += 1
                else:
                    break

            return count        
