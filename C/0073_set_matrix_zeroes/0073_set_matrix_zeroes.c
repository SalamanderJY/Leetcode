void setZeroes(int** matrix, int matrixSize, int* matrixColSize)
{
    int s1 = 0;
    int s2 = 0;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[i]; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
                if (i == 0) {
                    s1 = 1;
                }
                if (j == 0) {
                    s2 = 1;
                }
            }
        }
    }
    for (int i = 1; i < matrixSize; ++i) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < matrixColSize[i]; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < matrixColSize[0]; ++i) {
        if (matrix[0][i] == 0) {
            for (unsigned j = 1; j < matrixSize; ++j) {
                matrix[j][i] = 0;
            }
        }
    }

    if (s1) {
        for (unsigned i = 1; i < matrixColSize[0]; ++i) {
            matrix[0][i] = 0;
        }
    }
    if (s2) {
        for (unsigned i = 1; i < matrixSize; ++i) {
            matrix[i][0] = 0;
        }
    }
}
