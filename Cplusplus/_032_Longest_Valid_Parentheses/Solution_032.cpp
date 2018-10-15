class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        if (s.size() < 2)
            return 0;
        vector<int> dp(s.size(), 0);
        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] == '(') {
                int j = i + 1 + dp[i + 1];
                if (j < s.size() && s[j] == ')') {
                    dp[i] = dp[i + 1] + 2;
                    if (j + 1 < s.size())
                        dp[i] += dp[j + 1];
                }
                if (dp[i] > max)
                    max = dp[i];
            }
        }
        return max;
    }
};
