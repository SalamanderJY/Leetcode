class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximum = 0;
        int temp = 0;
        for (int i : nums) 
        {
            if (i == 1)
            {
                temp++;
                maximum = max(maximum, temp);
            }
            else
                temp = 0;
        }
        return maximum;
    }
};