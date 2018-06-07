class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        backtracking(s, 0, "", res);
        return res;
    }
    
    void backtracking(string s, int index, string path, vector<string> &res) {
        if (index == 4) {
            if (s.size() == 0)
                res.push_back(path.substr(0, path.size() - 1));
            return;
        }
        for (int i = 1; i < 4; ++i) {
            if (i <= s.size()) {
                int num;
                stringstream stream(s.substr(0, 3));  
                stream >> num;
                if (i == 1)
                    backtracking(s.substr(i, s.size() - i), index + 1, path + s.substr(0, i) + ".", res);
                else if (i == 2 && s[0] != '0')
                    backtracking(s.substr(i, s.size() - i), index + 1, path + s.substr(0, i) + ".", res);
                else if (i == 3 && s[0] != '0' && num < 256)
                    backtracking(s.substr(i, s.size() - i), index + 1, path + s.substr(0, i) + ".", res);
            }
        }
    }
};

