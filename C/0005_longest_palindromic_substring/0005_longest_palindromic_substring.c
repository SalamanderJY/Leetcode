char* longestPalindrome(char* s) {
    if (strlen(s) == 0) {
        return s;
    }
    int start = 0;
    int max = 0;
    int MAX_SIZE = strlen(s) + 1;
    bool **dp = (bool **)malloc(MAX_SIZE * sizeof(bool *));
    for (int i = 0; i < MAX_SIZE; i++) {
        dp[i] = (bool *)malloc(MAX_SIZE * sizeof(bool));
        for (int j = 0; j < MAX_SIZE; j++) {
            dp[i][j] = false;
        }
    }
    char *res = (char *)malloc(MAX_SIZE * sizeof(char));

    for (int i = 0; i < strlen(s); i++) {
        for (int j = 0; j <= i; j++) {
            if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1])) {
                dp[j][i] = true;
            }
            if (dp[j][i] && max < i - j + 1) {
                max = i - j + 1;
                start = j;
            }
        }
    }

    for (int i = start, j = 0; i < start + max; i++, j++) {
        res[j] = s[i];
    }
    res[max] = '\0';
    return res;
}