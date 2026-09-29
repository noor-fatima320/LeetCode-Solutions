class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Valid parentheses string ki length even honi chahiye
        if ((m + n - 1) % 2 != 0)
            return false;

        // Start '(' hona zaroori hai
        if (grid[0][0] == ')')
            return false;

        // dp[i][j] = possible balance values
        vector<vector<bitset<101>>> dp(m, vector<bitset<101>>(n));

        dp[0][0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                if (grid[i][j] == '(') {
                    if (i > 0)
                        dp[i][j] |= (dp[i - 1][j] << 1);

                    if (j > 0)
                        dp[i][j] |= (dp[i][j - 1] << 1);
                }
                else {
                    if (i > 0)
                        dp[i][j] |= (dp[i - 1][j] >> 1);

                    if (j > 0)
                        dp[i][j] |= (dp[i][j - 1] >> 1);
                }

                // Negative balance ko automatically ignore kiya jata hai
            }
        }

        // End par balance 0 hona chahiye
        return dp[m - 1][n - 1][0];
    }
};