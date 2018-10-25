class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> rightmax(n);
        vector<int> leftmax(n);
        int value = height[n - 1];
        rightmax[n - 1] = value;
        int wall = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (height[i] > value)
                value = height[i];
            rightmax[i] = value;
            wall += height[i];   
        }
        value = height[0];
        leftmax[0] = value;
        for (int i = 0; i < n; ++i) {
            if (height[i] > value)
                value = height[i];
            leftmax[i] = value;
        }
        int water = 0;
        for (int i = 0; i < n; ++i) {
             water += min(leftmax[i], rightmax[i]);
        }
        return water - wall;
    }
};