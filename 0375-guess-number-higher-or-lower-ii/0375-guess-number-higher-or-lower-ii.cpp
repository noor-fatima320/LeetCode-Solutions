
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len <= n; len++) {
            for (int left = 1; left + len - 1 <= n; left++) {
                int right = left + len - 1;
                dp[left][right] = INT_MAX;

                for (int guess = left; guess <= right; guess++) {
                    int cost = guess + max(
                        dp[left][guess - 1],
                        dp[guess + 1][right]
                    );

                    dp[left][right] = min(dp[left][right], cost);
                }
            }
        }

        return dp[1][n];
    }
};
