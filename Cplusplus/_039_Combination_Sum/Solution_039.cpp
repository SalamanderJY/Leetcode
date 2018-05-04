class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res, temp, candidates, target, 0);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int> current, vector<int>& candidates, int target, int index) {
        if (target < 0 || index >= candidates.size())
            return;
        if (target == 0) {
            res.push_back(current);
            return;
        }
        else {
            current.push_back(candidates[index]);
            backtrack(res, current, candidates, target - candidates[index], index);
            current.erase(current.begin() + current.size() - 1);
            backtrack(res, current, candidates, target, index + 1);
        }
    }
};