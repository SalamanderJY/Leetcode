class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[nums.size() - 1];
        int closestSum = sum;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    sum = nums[left] + nums[right] + nums[i];
                    if (sum < target) {
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        left++;
                    }
                    else if (sum > target) {
                        while (left < right && nums[right] == nums[right - 1])
                            right--;
                        right--;
                    }
                    else return sum;
                    if (abs(sum - target) < abs(closestSum - target))
                        closestSum = sum;
                }
            }
        }
        return closestSum;
    }
};
