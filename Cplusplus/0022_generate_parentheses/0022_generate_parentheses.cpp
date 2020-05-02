class Solution {
public:
    vector<string> generateParentheses(int n) {
        vector<string> result;
        addParentheses(result, "", n, 0);
        return result;
    }
    
    void addParentheses(vector<string> &result, string str, int notAdd, int notMatch) {
        if (notMatch == 0 && notAdd == 0) {
            result.push_back(str);
            return;
        }
        if (notMatch > 0)
            addParentheses(result, str + ')', notAdd, notMatch - 1);
        if (notAdd > 0)
            addParentheses(result, str + '(', notAdd - 1, notMatch + 1);
    }
};
