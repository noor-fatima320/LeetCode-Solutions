
class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int r, int c, bool& closed) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        if (grid[r][c] == 1)
            return;

        grid[r][c] = 1;

        if (r == 0 || r == m - 1 || c == 0 || c == n - 1)
            closed = false;

        dfs(grid, r + 1, c, closed);
        dfs(grid, r - 1, c, closed);
        dfs(grid, r, c + 1, closed);
        dfs(grid, r, c - 1, closed);
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    bool closed = true;

                    dfs(grid, i, j, closed);

                    if (closed)
                        count++;
                }
            }
        }

        return count;
    }
};
