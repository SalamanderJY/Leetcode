class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int first = INT_MIN, second = INT_MIN, third = INT_MIN;
        unordered_set<int> set;
        for(int i : nums) {
            set.insert(i);
            if(i == first || i == second || i == third) continue;
            if(i > first) {
                third = second;
                second = first;
                first = i;
            } else if(i > second) {
                third = second;
                second = i;
            } else if(i >= third) {
                third = i;
            }
        }
        return set.size() >= 3 ? third : first;
    }
};