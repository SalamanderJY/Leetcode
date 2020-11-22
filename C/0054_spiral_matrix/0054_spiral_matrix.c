int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) 
{
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int *)malloc(sizeof(int) * matrixSize * matrixColSize[0]);
    *returnSize = matrixSize * matrixColSize[0];
    int n = matrixSize;
    int m = matrixColSize[0];
    int count = 1;
    int begin = 0;
    while (count <= m * n) {
        for (int i = begin; i < m - begin; i++) {
            result[count - 1] = (matrix[begin][i]);
            count++;
            if(count > m * n)
              return result;
        }
        for (int i = begin + 1; i < n - begin; i++) {
            result[count - 1] = (matrix[i][m - 1 - begin]);
            count++;
            if(count > m * n)
              return result;
        }
        for (int i = m - 2 - begin; i >= begin; i--) {
            result[count - 1] = (matrix[n - 1 - begin][i]);
            count++;
            if(count > m * n)
              return result;
        }
        for (int i = n - 2 - begin; i > begin; i--) {
            result[count - 1] = (matrix[i][begin]);
            count++;
            if (count > m * n)
              return result;
        }
        begin++;
    }
    return result;
}