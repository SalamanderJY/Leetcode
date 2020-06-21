int longestValidParentheses(char* s) {
    int max = 0;
    int len = strlen(s);
    if (len < 2) {
        return 0;
    }
    int *dp = malloc(len * sizeof(int));
    memset(dp, 0, sizeof(int) * len);
    for (int i = 1; i < len; i++) {
        if (s[i] == ')') {
            if (s[i - 1] == '(') {
                dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
            }
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            max = max > dp[i] ? max : dp[i];
        }
    }
    free(dp);
    return max;
}