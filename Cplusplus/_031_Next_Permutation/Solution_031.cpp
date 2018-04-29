class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // in reverse order, find the first number which is in increasing trend (we call it violated number here)
        int i;
        for (i = nums.size() - 2; i >= 0; --i)
            if (nums[i] < nums[i + 1]) break;
        // reverse all the numbers after violated number
        reverse(nums.begin() + i + 1, nums.end());
        // if violated number not found, because we have reversed the whole array, then we are done!
        if (i == -1) return;
        // else binary search find the first number larger than the violated number
        auto itr = upper_bound(nums.begin() + i + 1, nums.end(), nums[i]);
        // swap them, done!
        swap(nums[i], *itr);
    }
};
