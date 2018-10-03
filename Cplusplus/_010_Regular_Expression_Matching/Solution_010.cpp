class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size() == 1)
            return (s.size() == 1 && (s.at(0) == p.at(0) || p.at(0) == '.'));
        if (p.at(1) != '*') {
            if (s.empty()) return false;
            return (s.at(0) == p.at(0) || p.at(0) == '.') && isMatch(s.substr(1), p.substr(1));
        }
        while (!s.empty() && (s.at(0) == p.at(0) || p.at(0) == '.')) {
            if (isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));
    }
};