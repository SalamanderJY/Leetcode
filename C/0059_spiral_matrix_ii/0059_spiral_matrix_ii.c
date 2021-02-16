int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        returnColumnSizes[0][i] = n;
    }

    int** matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * n);
    }
    int m = n;
    int count = 1;
    int begin = 0;
    while (count <= m * n) {
        for (int i = begin; i < m - begin; i++) {
            matrix[begin][i] = count;
            count++;
            if (count > m * n) {
                return matrix;
            }
        }
        for (int i = begin + 1; i < n - begin; i++) {
            matrix[i][m - 1 - begin] = count;
            count++;
            if (count > m * n) {
                return matrix;
            }
        }
        for (int i = m - 2 - begin; i >= begin; i--) {
            matrix[n - 1 - begin][i] = count;
            count++;
            if (count > m * n) {
                return matrix;
            }
        }
        for (int i = n - 2 - begin; i > begin; i--) {
            matrix[i][begin] = count;
            count++;
            if (count > m * n) {
                return matrix;
            }
        }
        begin++;
    }
    return matrix;
}