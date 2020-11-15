#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxSubArray(int* nums, int numsSize)
{
    int dp[numsSize];
    memset(dp, 0, sizeof(int) * numsSize);
    dp[0] = nums[0];
    int max = nums[0];

    for (int i = 1; i < numsSize; i++) {
        dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
        max = MAX(dp[i], max);
    }

    return max;
}