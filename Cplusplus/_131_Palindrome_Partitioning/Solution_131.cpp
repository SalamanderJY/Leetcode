class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> res;
        backtracking(s, 0, path, res);
        return res;
    }
    
    void backtracking(string s, int pos, vector<string>& path, vector<vector<string>>& res) {
        if (pos == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = pos; i < s.size(); i++) {
            if (isPalindrome(s.substr(pos, i - pos + 1))) {
                path.push_back(s.substr(pos, i - pos + 1));
                backtracking(s, i + 1, path, res);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s) {
        int first = 0;
        int end = s.size() - 1;
        while (first < end)
            if (s[first++] != s[end--])
                return false;
        return true;
    }
};