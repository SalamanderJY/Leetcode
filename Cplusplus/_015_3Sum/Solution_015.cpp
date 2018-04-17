class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        // sort the array
        sort(nums.begin(), nums.end());
        // hash map
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]] = i;
        
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (nums[i] > 0) return res;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                if (j - 1 > i && nums[j] == nums[j - 1]) continue;
                int two = nums[i] + nums[j];
                if (-two < nums[j]) break;
                if (two > 0) return res;
                auto it = map.find(-two);
                // exists and not traverse
                if (it != map.end() && it->second > j)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(-two);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
