class Solution {
public:
    int arrangeCoins(int n) {
        return floor((sqrt((double)8 * n + 1) - 1) / 2);
    }
};