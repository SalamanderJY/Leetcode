class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for (i = nums.size() - 2; i >= 0 && nums[i] >= nums[i + 1]; --i);
        reverse(nums.begin() + i + 1, nums.end());
        if (i < 0) {return;}
        auto itr = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
        swap(nums[i], *itr);
        return ;
    }
};
