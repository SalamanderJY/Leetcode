class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1)
            return 0;
        vector<int> dp;
        int minimum = prices[0];
        int maximum = 0;
        dp.push_back(0);
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < minimum) {
                minimum = prices[i];
                dp.push_back(0);
            }
            else
                dp.push_back(prices[i] - minimum);
            if (maximum < dp[i])
                maximum = dp[i];
        
        }
        return maximum;
    }
};