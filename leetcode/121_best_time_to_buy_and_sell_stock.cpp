class Solution {
public:
    int maxProfit(vector<int>& prices) {        
            int minBuy = prices[0];
            int maxProfit = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] < minBuy) {
                    minBuy = prices[i];
                } else {
                    maxProfit = max(maxProfit, prices[i] - minBuy);
                }
            }
            return maxProfit;
        }
};