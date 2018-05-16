class Solution:
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        result = [[0 for i in range(n)] for j in range(n)]
        count = 1
        begin = 0
        while count <= n * n:
            for i in range(begin, n - begin):
                result[begin][i] = count;
                count += 1
                if count > n * n:
                    return result
            for i in range(begin + 1, n - begin):
                result[i][n - 1 - begin] = count
                count += 1
                if count > n * n:
                    return result
            i = n - 2 - begin
            while i >= begin:
                result[n - 1 - begin][i] = count
                count += 1
                if count > n * n:
                    return result
                i -= 1
            i = n - 2 - begin
            while i > begin:
                result[i][begin] = count
                count += 1
                if count > n * n:
                    return result
                i -= 1
            begin += 1
        return result

