class Solution {
    public int maxSubArray(int[] nums) {
        int maximum = nums[0];
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        
        for (int i = 1; i < nums.length; i++)
        {
            dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i];
            maximum = Math.max(maximum, dp[i]);
        }
        
        return maximum;
    }
}

