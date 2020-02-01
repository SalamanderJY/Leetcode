class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0)
            return s;
        bool dp[1000][1000] = { false };
        int start = 0;
        int max = 0;
        string res;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (s.at(i) == s.at(j) && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                }
                if (dp[j][i] && max < i - j + 1) {
                    max = i - j + 1;
                    start = j;
                }
            }
        }
        for (int i = start; i < start + max; i++) {
            res += s[i];
        }
        return res;
    }
};