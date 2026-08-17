
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // Sabse low buying price update karo
            minPrice = min(minPrice, prices[i]);

            // Aaj sell karne par profit
            int profit = prices[i] - minPrice;

            // Maximum profit update karo
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};