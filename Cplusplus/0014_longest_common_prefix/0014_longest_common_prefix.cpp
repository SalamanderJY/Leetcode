#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min = 0;
        while (strs.size() > 0) {
            for (string s : strs) {
                if (s.size() == min || s.at(min) != strs[0].at(min))
                    return strs[0].substr(0, min);
            }
            min++;
        }
        return "";
    }
};
