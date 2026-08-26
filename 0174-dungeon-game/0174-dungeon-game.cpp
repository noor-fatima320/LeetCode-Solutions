class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n));

        // Bottom-right cell
        dp[m - 1][n - 1] =
            max(1, 1 - dungeon[m - 1][n - 1]);

        // Last row
        for (int j = n - 2; j >= 0; j--) {

            dp[m - 1][j] =
                max(1, dp[m - 1][j + 1] - dungeon[m - 1][j]);
        }

        // Last column
        for (int i = m - 2; i >= 0; i--) {

            dp[i][n - 1] =
                max(1, dp[i + 1][n - 1] - dungeon[i][n - 1]);
        }

        // Remaining cells
        for (int i = m - 2; i >= 0; i--) {

            for (int j = n - 2; j >= 0; j--) {

                int nextHealth =
                    min(dp[i + 1][j], dp[i][j + 1]);

                dp[i][j] =
                    max(1, nextHealth - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};