class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[j] > nums[i])
                {
                    mapping[nums[i]] = nums[j];
                    break;
                }
                if (j == nums.size() - 1)
                    mapping[nums[i]] = -1;
            }
        }       
        vector<int> res;
        for (int num : findNums)
            res.push_back(mapping[num]);
        return res;
    }
};