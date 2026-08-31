class Solution {
public:

    void dfs(vector<vector<char>>& grid, int row, int col) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return;
        }

        // If it is water, stop
        if (grid[row][col] == '0') {
            return;
        }

        // Mark this land as visited
        grid[row][col] = '0';

        // Visit up
        dfs(grid, row - 1, col);

        // Visit down
        dfs(grid, row + 1, col);

        // Visit left
        dfs(grid, row, col - 1);

        // Visit right
        dfs(grid, row, col + 1);
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        for (int row = 0; row < m; row++) {

            for (int col = 0; col < n; col++) {

                // Found a new island
                if (grid[row][col] == '1') {

                    islands++;

                    // Visit the complete island
                    dfs(grid, row, col);
                }
            }
        }

        return islands;
    }
};