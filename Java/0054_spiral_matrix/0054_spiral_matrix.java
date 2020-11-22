class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<Integer>();
        if (matrix.length == 0)
            return result;
        int n = matrix.length;
        int m = matrix[0].length;
        int count = 1;
        int begin = 0;
        while (count <= m * n) {
            for (int i = begin; i < m - begin; i++) {
                result.add(matrix[begin][i]);
                count++;
                if(count > m * n)
                  return result;
            }

            for (int i = begin + 1; i < n - begin; i++) {
                result.add(matrix[i][m - 1 - begin]);
                count++;
                if(count > m * n)
                  return result;
            }

            for (int i = m - 2 - begin; i >= begin; i--) {
                result.add(matrix[n - 1 - begin][i]);
                count++;
                if(count > m * n)
                  return result;
            }

            for (int i = n - 2 - begin; i > begin; i--) {
                result.add(matrix[i][begin]);
                count++;
                if (count > m * n)
                  return result;
            }
            begin++;
        }
        return result;
    }
}
