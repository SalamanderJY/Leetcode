class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minimum = INT_MAX;
        int res = 0;
        for (int num : nums)
            minimum = min(minimum, num);
        for (int num : nums)
            res += num - minimum;
        return res;
    }
};