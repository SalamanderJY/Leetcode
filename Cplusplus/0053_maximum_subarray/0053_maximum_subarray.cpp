class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int* dp = new int[nums.size()];
        dp[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i];
            maximum = max(maximum, dp[i]);
        }
        delete[] dp;
        
        return maximum;
    }
};

