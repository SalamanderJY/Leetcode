class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> maps;
        vector<int> res;
        for (auto a : nums1) ++maps[a];
        for (auto a : nums2) {
            if (maps[a]-- > 0) res.push_back(a);
        }
        return res;
    }
};
