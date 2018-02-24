class Solution {
public:
    int titleToNumber(string s) {
        if (s.length() == 1)
			return s.at(0) - 65 + 1;
		return s.at(s.length() - 1) - 65 + 1 + titleToNumber(s.substr(0, s.length() - 1)) * 26;
    }
};