class Solution:
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        remove = [False for i in range(n)]
        for i in range(3, n):
            if i % 2 == 0:
                remove[i] = True
            else:
                remove[i] = False

        for i in range(3, n, 2):
            if not remove[i]:
                if i * i > n:  
                    break
                j = 2
                while i * j < n:
                    remove[i * j] = True
                    j += 1
        count = 0
        for i in range(2, n):
            if not remove[i]:
                count += 1

        return count
