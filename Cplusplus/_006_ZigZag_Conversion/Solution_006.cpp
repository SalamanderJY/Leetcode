class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> result(numRows, "");
        int i = 0;
        int j = 0;
        int back = numRows - 2;
        while (i < s.size()) {
            for (j = 0; j < s.size() && j < numRows && i < s.size(); j++) {
                result[j] += s[i];
                i++;
            }
            for (j = back; j < s.size() && j > 0 && i < s.size(); j--) {
                result[j] += s[i];
                i++;
            }
        }
        for (i = 0; i < numRows - 1; i++)
            result[0] += result[i + 1];
        
        return result[0];
    }
};