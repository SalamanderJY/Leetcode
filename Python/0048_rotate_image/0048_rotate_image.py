class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        for i in range(0, len(matrix) // 2):
            for j in range(0, len(matrix)):
                matrix[len(matrix) - 1 - i][j], matrix[i][j] = matrix[i][j], matrix[len(matrix) - 1 - i][j]
        for i in range(0, len(matrix)):
            for j in range(i + 1, len(matrix)):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
