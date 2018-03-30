class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1;
        int j = 0;
        vector<int> dp(s.size() + 1, 0);
        while (i < s.size()) {
            if (s[i] == s[j]) {
                dp[++i] = ++j;
            }
            else if (j == 0)
                ++i;
            else
                j = dp[j];
        }
        return dp[s.size()] && (dp[s.size()] % (s.size() - dp[s.size()]) == 0);
    }
};

// Consider s as KMP's Pattern String to count the repeat number.