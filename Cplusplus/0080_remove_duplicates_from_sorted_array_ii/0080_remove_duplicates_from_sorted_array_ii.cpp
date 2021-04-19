class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != nums[i - 2] || i < 2) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};