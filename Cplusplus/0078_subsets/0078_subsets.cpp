class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> list;
        if (nums.size() == 0) {
            res.push_back(list);
            return res;
        }
        sort(nums.begin(), nums.end());
        backtracking(res, list, nums, 0);
        return res;
    }
    
    void backtracking(vector<vector<int>> &res, vector<int> list, vector<int> &nums, int pos) {
        res.push_back(list);    
        for (int i = pos; i < nums.size(); i++) {
            list.push_back(nums[i]);
            backtracking(res, list, nums, i + 1);
            list.pop_back();
        }
    }
};