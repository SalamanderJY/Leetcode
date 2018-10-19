class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        if num1 == "0" or num2 == "0":
            return "0"
        res = [0] * (len(num1) + len(num2))
        for i in (range(0, len(num1))):
            if num1[len(num1) - 1 - i] == '0':
                continue
            carry = 0
            index = i
            for j in (range(0, len(num2))):
                multiply = res[index] + (ord(num1[len(num1) - 1 - i]) - ord('0')) * (ord(num2[len(num2) - 1 - j]) - ord('0')) + carry
                carry = multiply // 10
                res[index] = multiply % 10
                index += 1
            res[index] += carry
        string = ""
        flag = False
        for i in range(0, len(res)):
            if res[len(res) - 1 - i] == 0 and not flag:
                continue
            else:
                flag = True
                string += str(res[len(res) - 1 - i])
        return string
