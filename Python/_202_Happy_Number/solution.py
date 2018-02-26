class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        map = {}
        # if is not happy number, means existing loop in the sum except 1
        while True: 
            sum = 0
            while n > 0:
                sum += (n % 10) * (n % 10)
                n //= 10
                      
            n = sum
            if sum in map:
                break
            else:
                map[sum] = 1
        return (n == 1)
