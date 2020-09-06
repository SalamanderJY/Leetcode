class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> list;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, ans, list, 0, target);
        return ans;
    }

    void dfs(vector<int>& candidates, vector<vector<int>> &ans, vector<int> &list, int index, int target) {
        if (target == 0) {
            ans.push_back(list);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (target - candidates[i] < 0) 
                break;
            list.push_back(candidates[i]);
            dfs(candidates, ans, list, i, target - candidates[i]);
            list.pop_back();
        }
    }
};