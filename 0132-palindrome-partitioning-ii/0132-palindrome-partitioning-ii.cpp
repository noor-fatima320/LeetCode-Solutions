class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        // pal[i][j] tells whether s[i...j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // dp[i] = minimum cuts for first i characters
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = -1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j <= i; j++) {

                if (pal[j][i]) {
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};