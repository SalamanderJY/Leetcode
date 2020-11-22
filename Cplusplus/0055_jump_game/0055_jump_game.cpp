class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximum = nums[0];
        int index = 0;
        while (index <= maximum && index < nums.size()) {
            if (index + nums[index] > maximum)
                maximum = index + nums[index];
            index++;
        }
        return maximum >= nums.size() - 1 ? true : false;
    }
};
