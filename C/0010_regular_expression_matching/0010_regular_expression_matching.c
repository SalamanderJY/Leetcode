bool isMatch(char* s, char *p) {
    int slen = strlen(s);
    int plen = strlen(p);

    bool dp[slen + 1][plen + 1];
    memset(dp, false, (slen + 1) *(plen + 1) * sizeof(bool));
    dp[0][0] = true;
    // i, j means it is matched or not from s[0:i] and p[0:j].
    for (int i = 0; i <= slen; i++) {
        for (int j = 1; j <= plen; j++) {
            if (i > 0 && (p[j - 1] == s[i - 1] || p[j - 1] == '.')) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (!dp[i][j] && i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[slen][plen];
}