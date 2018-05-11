class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if (strs.size() == 0) return ans;
        unordered_map<string, vector<string>> map;
        for (auto it : strs) {
            string value = it;
            sort(it.begin(), it.end());
            string key = it;
            map[key].push_back(value);
        }
        for (auto it : map)
            ans.push_back(it.second);
        return ans;
    }
};