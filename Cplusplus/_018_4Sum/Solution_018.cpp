class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        // sort the array
        sort(nums.begin(), nums.end());
        // hash map
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]] = i;
        
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) 
                return res;
            if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3] < target)
                continue;    
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[nums.size() - 1] + nums[nums.size() - 2] < target)
                    continue;
                if (j - 1 > i && nums[j] == nums[j - 1]) 
                    continue;
                for (int k = j + 1; k < nums.size() - 1; k++)
                {
                    if (k - 1 > j && nums[k] == nums[k - 1])
                        continue;
                    int three = nums[i] + nums[j] + nums[k];
                    auto it = map.find(target - three);
                    if (it != map.end() && it->second > k)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        temp.push_back(target - three);
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
};
