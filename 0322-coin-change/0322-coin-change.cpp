class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // dp[i] = minimum coins needed to make amount i
        vector<int> dp(amount + 1, amount + 1);
        
        // 0 amount needs 0 coins
        dp[0] = 0;
        
        // Calculate answer for every amount
        for (int i = 1; i <= amount; i++) {
            
            // Try every coin
            for (int coin : coins) {
                
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If amount is still impossible
        if (dp[amount] == amount + 1) {
            return -1;
        }
        
        return dp[amount];
    }
};