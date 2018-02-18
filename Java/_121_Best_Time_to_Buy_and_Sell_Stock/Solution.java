class Solution {
    public int maxProfit(int[] prices) {
        if (prices.length < 1)
            return 0;
        int minimum = prices[0];
        int maximum = 0;
        for (int i = 1; i < prices.length; i++)
        {
            int temp = 0;
            if (prices[i] < minimum) 
                minimum = prices[i];
            else
                temp = prices[i] - minimum;
            if (maximum < temp)
                maximum = temp;       
        }
        return maximum;
    }
}