class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0)
            return res;
        string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            vector<string> temp;
            for (int j = 0; j < res.size(); j++) {
                for (int k = 0; k < map[digits[i] - '0'].size(); k++) {
                    temp.push_back(res[j] + map[digits[i] - '0'][k]);
                }
            }
            res = temp;
        }
        return res;
    }
};
