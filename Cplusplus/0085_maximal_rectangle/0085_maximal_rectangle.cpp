class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        heights.push_back(0);
        vector<int> index;
        for (int i = 0; i < heights.size(); i++) {
            while (index.size() > 0 && heights[index.back()] >= heights[i]) {
                int h = heights[index.back()];
                index.pop_back();
                int sidx = index.size() > 0 ? index.back() : -1;
                ret = max(ret, h * (i - sidx - 1));
            }
            index.push_back(i);
        }
        return ret;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m < 1) return 0;
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxArea = 0;

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (i == 0) {
                    dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else {
                    dp[i][j] = matrix[i][j] == '1' ? dp[i - 1][j] + 1 : 0;
                }
            }
        }

        for (int i = matrix.size() - 1; i >= 0; i--) {
            maxArea= max(maxArea, largestRectangleArea(dp[i]));
        }
        
        return maxArea;
    }
};