class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0)
                    triangle[i][j] += triangle[i - 1][0];
                else if (j == triangle[i].size() - 1)
                    triangle[i][j] += triangle[i - 1][triangle[i - 1].size() - 1];
                else
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }
        int minimum = INT_MAX;
        for (int i = 0; i < triangle[triangle.size() - 1].size(); ++i)
           minimum = min(triangle[triangle.size() - 1][i], minimum);
        return minimum;
    }
};