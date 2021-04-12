bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int i = matrixSize - 1;
    int j = 0;

    while (i >= 0 && j < matrixColSize[0]) {
        if (matrix[i][j] > target) {
            i--;
        } else if (matrix[i][j] < target) {
            j++;
        } else {
            return true;
        }
    }
    return false;
}