class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n < 1:
            return None   
        result = "1"     
        for i in range(2, n + 1):
            result = countRecurrent(result)    
        return result

def countRecurrent(string):
        result = ""
        count = 1
        for i in range(1, len(string)):
            if string[i] == string[i - 1]:
                count += 1
            else:
                result += str(count)
                result += string[i - 1]
                count = 1
        result += str(count)
        result += string[len(string) - 1]
        return result