int numDecodings(char* s) 
{
    int len = strlen(s);
    if (len == 0 || s[0] == '0')
        return 0;  
    int* dp = malloc(sizeof(int) * (len + 1));
    for (int i = 0; i < len + 1; i++)
        dp[i] = 0;
    dp[0] = dp[1] = 1;   
    for (int i = 1; i < strlen(s); ++i) {
        if (s[i] != '0')
            dp[i + 1] = dp[i];
        if ((s[i - 1] == '1' && s[i] <= '9') || (s[i - 1] == '2' && s[i] <= '6'))
            dp[i + 1] += dp[i - 1];
    }
    int res = dp[len];
    free(dp);
    return res;
}