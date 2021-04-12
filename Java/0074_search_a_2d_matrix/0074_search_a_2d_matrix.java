class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0)
            return false;
        int i = matrix.length - 1;
        int j = 0;
        while (i >= 0 && j <= matrix[0].length - 1) {
            if (target > matrix[i][j])
                ++j;
            else if (target < matrix[i][j])
                --i;
            else
                return true;
        }
        return false;
    }
}