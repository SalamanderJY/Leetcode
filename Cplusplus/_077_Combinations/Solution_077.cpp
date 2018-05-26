class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> stack;
        int x = 1;
        while (1) {
            int l = stack.size();
            if (l == k)
                ans.push_back(stack);
            // there is not enough number to choose OR stack is full.
            if (l == k || k - l > n - x + 1) {
                if (stack.size() == 0)
                    return ans;
                x = stack[stack.size() - 1] + 1;
                stack.pop_back();
            }
            else {
                stack.push_back(x);
                x++;
            }
        }
    }
};