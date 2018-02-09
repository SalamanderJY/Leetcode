class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
            return 0;
        
        int* dp = new int[n + 2];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 3;
        for (int i = 3; i < n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        
        return dp[n - 1];       
    }
};