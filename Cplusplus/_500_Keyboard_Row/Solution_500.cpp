class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> dict(26);
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for (int i = 0; i < rows.size(); i++) {
            for (auto c : rows[i]) 
                dict[c - 'A'] = 1 << i;
        }
        vector<string> res;
        for (auto w : words) 
        {
            int mark = dict[toupper(w[0]) - 'A'];
            for (int i = 0; i < w.size(); i++) 
            {
                if (mark != dict[toupper(w[i]) - 'A'])
                    break;
                if (i == w.size() - 1)
                    res.push_back(w);
            }
        }
        return res;
    }
};