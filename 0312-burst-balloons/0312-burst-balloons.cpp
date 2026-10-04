class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> a(n + 2, 1);

        for (int i = 0; i < n; i++) {
            a[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int length = 2; length < n + 2; length++) {
            for (int left = 0; left + length < n + 2; left++) {
                int right = left + length;

                for (int k = left + 1; k < right; k++) {
                    int coins = dp[left][k]
                              + dp[k][right]
                              + a[left] * a[k] * a[right];

                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }

        return dp[0][n + 1];
    }
};