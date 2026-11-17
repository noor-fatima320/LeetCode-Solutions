
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute minimum changes for every substring
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int len = r - l + 1;

                // Try every proper divisor
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    // Check palindrome groups
                    for (int start = 0; start < d; start++) {
                        int left = l + start;
                        int right = r - ((len - 1 - start) % d);

                        while (left < right) {
                            if (s[left] != s[right]) {
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        // dp[i][j] = minimum changes to partition
        // first j characters into i semi-palindromes
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int i = 2 * parts; i <= n; i++) {

                // Last substring starts at j
                for (int j = 2 * (parts - 1); j <= i - 2; j++) {
                    if (dp[parts - 1][j] == INF) continue;

                    dp[parts][i] = min(
                        dp[parts][i],
                        dp[parts - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
