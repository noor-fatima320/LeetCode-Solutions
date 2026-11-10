
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);

        dp[0] = 0;

        for (int j = 1; j <= n; j++) {
            for (int jump = 1; jump <= 3; jump++) {
                int i = j - jump;

                if (i >= 0) {
                    long long d = j - i;

                    dp[j] = min(dp[j],
                        dp[i] + costs[j - 1] + d * d);
                }
            }
        }

        return (int)dp[n];
    }
};
