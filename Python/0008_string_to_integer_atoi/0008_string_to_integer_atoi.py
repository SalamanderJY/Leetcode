class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        maximum = 2 ** 31 - 1
        if len(str) == 0 or str.isspace(): # Here is sample like "    " all spaces
            return 0     
        result, index, flag = 0, 0, 1      
        while str[index] == ' ':
            index += 1 
        if str[index] == '-':
            flag = -1
            index += 1    
        elif str[index] == '+':
            flag = 1
            index += 1       
        for i in range(index, len(str)):
            if ord(str[i]) < ord('0') or ord(str[i]) > ord('9'):
                break
            if result > maximum // 10 or (result == maximum // 10 and (ord(str[i]) - ord('0') > maximum % 10)):
                return -maximum - 1 if flag == -1 else maximum # MIN INT gives -2147483648 ? fuck the samples
            result = result * 10 + ord(str[i]) - ord('0')        
        return result * flag
