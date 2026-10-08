class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (dp[r][c] != 0)
            return dp[r][c];

        int best = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m &&
                nc >= 0 && nc < n &&
                matrix[nr][nc] > matrix[r][c]) {

                best = max(best, 1 + dfs(matrix, nr, nc));
            }
        }

        dp[r][c] = best;
        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, 0));

        int answer = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                answer = max(answer, dfs(matrix, r, c));
            }
        }

        return answer;
    }
};