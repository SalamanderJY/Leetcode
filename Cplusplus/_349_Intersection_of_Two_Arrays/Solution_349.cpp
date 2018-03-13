class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> map(nums1.begin(), nums1.end());
        vector<int> result;
        for (auto a : nums2)
            if (map.count(a)) {
                result.push_back(a);
                map.erase(a);
            }
        return result;
    }
};
