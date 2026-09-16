class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> sum(n, vector<long long>(k + 1, 0));

        // With 0 segments, there is 1 way.
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
            sum[i][0] = i + 1;
        }

        for (int segments = 1; segments <= k; segments++) {
            for (int points = 1; points < n; points++) {

                // Do not use points[points] as the end of a new segment
                dp[points][segments] =
                    dp[points - 1][segments];

                // Start a new segment from some previous point.
                if (points >= 1) {
                    dp[points][segments] =
                        (dp[points][segments] +
                         sum[points - 1][segments - 1]) % MOD;
                }

                sum[points][segments] =
                    (sum[points - 1][segments] +
                     dp[points][segments]) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};