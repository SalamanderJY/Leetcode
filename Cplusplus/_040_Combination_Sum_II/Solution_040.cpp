class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(res, temp, candidates, target, 0);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, vector<int> current, vector<int>& candidates, int target, int index) {
        if (target < 0 || index > candidates.size())
            return;
        if (target == 0) {
            res.push_back(current);
            return;
        }
        else {
            current.push_back(candidates[index]);
            backtrack(res, current, candidates, target - candidates[index], index + 1);
            current.erase(current.begin() + current.size() - 1);
            backtrack(res, current, candidates, target, index + 1);
        }
    }
};