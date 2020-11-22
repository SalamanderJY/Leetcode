class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0)
            return result;
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 1;
        int begin = 0;
        while (count <= m * n) {
            for (int i = begin; i < m - begin; i++) {
                result.push_back(matrix[begin][i]);
                count++;
                if(count > m * n)
                  return result;
            }

            for (int i = begin + 1; i < n - begin; i++) {
                result.push_back(matrix[i][m - 1 - begin]);
                count++;
                if(count > m * n)
                  return result;
            }

            for (int i = m - 2 - begin; i >= begin; i--) {
                result.push_back(matrix[n - 1 - begin][i]);
                count++;
                if(count > m * n)
                  return result;
            }

            for (int i = n - 2 - begin; i > begin; i--) {
                result.push_back(matrix[i][begin]);
                count++;
                if (count > m * n)
                  return result;
            }
            begin++;
        }
        return result;
    }
};
