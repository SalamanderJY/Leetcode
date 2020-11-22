class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        result = []
        if len(matrix) == 0:
            return result
        n = len(matrix)
        m = len(matrix[0])
        count = 1
        begin = 0
        while count <= m * n:
            for i in range(begin, m - begin):
                result.append(matrix[begin][i])
                count += 1
                if count > m * n:
                    return result
            for i in range(begin + 1, n - begin):
                result.append(matrix[i][m - 1 - begin])
                count += 1
                if count > m * n:
                    return result
            i = m - 2 - begin
            while i >= begin:
                result.append(matrix[n - 1 - begin][i])
                count += 1
                if count > m * n:
                    return result
                i -= 1
            i = n - 2 - begin
            while i > begin:
                result.append(matrix[i][begin]);
                count += 1
                if count > m * n:
                    return result
                i -= 1
            begin += 1
        return result

