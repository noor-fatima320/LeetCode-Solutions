class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int r, int c, int index) {

        // All characters matched
        if (index == word.length()) {
            return true;
        }

        // Out of bounds
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size()) {
            return false;
        }

        // Current cell doesn't match
        if (board[r][c] != word[index]) {
            return false;
        }

        // Mark as visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore 4 directions
        bool found =
            dfs(board, word, r + 1, c, index + 1) ||
            dfs(board, word, r - 1, c, index + 1) ||
            dfs(board, word, r, c + 1, index + 1) ||
            dfs(board, word, r, c - 1, index + 1);

        // Backtrack
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Try every cell as starting point
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {

                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};