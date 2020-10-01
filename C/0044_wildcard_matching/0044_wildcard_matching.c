bool isMatch(char *s, char *p)
{
    int slen = strlen(s);
    int plen = strlen(p);
    int dp[slen + 1][plen + 1];
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = 1;
    for (int i = 1; i <= plen; ++i) {
        if (p[i - 1] == '*') {
            dp[0][i] = 1;
        } else {
            break;
        }
    }

    for (int i = 1; i < slen + 1; i++) {
        for (int j = 1; j < plen + 1; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            }
            else if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    
    return dp[slen][plen];
}