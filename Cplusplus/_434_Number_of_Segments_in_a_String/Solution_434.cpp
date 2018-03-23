class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        for(int i = 0; i < s.size(); i++)
            if(s.at(i) != ' ' && (i == 0 || s.at(i-1) == ' '))
                res++;        
        return res;
    }
};