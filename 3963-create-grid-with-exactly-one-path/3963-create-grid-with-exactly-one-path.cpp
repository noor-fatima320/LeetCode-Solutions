class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        grid[0][0] = '.';

        for (int j = 1; j < n; j++) {
            grid[0][j] = '.';
        }

        for (int i = 1; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};