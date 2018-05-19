class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        res = ""
        num = "123456789"
        factorial = [1] * n
        for i in range(1, n): 
            factorial[i] = factorial[i - 1] * i
        k -= 1
        i = n
        while i >= 1:
            j = k // factorial[i - 1]
            k %= factorial[i - 1]
            res += num[j]
            num = num[:j] + num[j+1:]
            i -=1
        return res
