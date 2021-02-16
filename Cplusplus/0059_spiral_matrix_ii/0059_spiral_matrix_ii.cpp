class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int count = 1;
        int begin = 0;
        while (count <= n * n) {
            for (int i = begin; i < n - begin; i++) {
                result[begin][i] = count;
                count++;
                if (count > n * n)
                  return result;
            }
            count--;
            for (int i = begin; i < n - begin; i++) {
                result[i][n - 1 - begin] = count;
                count++;
                if (count > n * n)
                  return result;
            }
            count--;
            for (int i = n - 1 - begin; i >= begin; i--) {
                result[n - 1 - begin][i] = count;
                count++;
                if (count > n * n)
                  return result;
            }
            count--;
            for (int i = n - 1 - begin; i > begin; i--) {
                result[i][begin] = count;
                count++;
                if (count > n * n)
                  return result;
            }
            begin++;
        }
        return result;
    }
};
