class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int win[26] = {0};
        int fixwin[26] = {0};
        if (s.size() == 0 || p.size() == 0 || p.size() > s.size())
            return res;
        for (int i = 0; i < p.size(); i++)
            fixwin[p.at(i) - 'a']++;
        for (int i = 0; i < p.size(); i++)
            win[s.at(i) - 'a']++;
        for (int i = 0; i < s.size(); i++) {
            if (isMatch(fixwin, win))
                res.push_back(i);
            
            if ((i + p.length()) < s.size()) {
                win[s.at(i) - 'a']--;
                win[s.at(i + p.size()) - 'a']++;
            } 
            else 
                break;
        }
        return res;
    }
    
    bool isMatch(int fixwin[], int win[]) {
        for (int i = 0; i < 26; i++)
            if (win[i] != fixwin[i])
                return false;
        return true;
    }
    
};