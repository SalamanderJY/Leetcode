class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, -1);
        int maximum = 0;
        int start = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (map[s[i]] > start)
                start = map[s[i]];
            map[s[i]] = i;
            maximum = max(maximum, i - start);
        }
        return maximum;
    }
};