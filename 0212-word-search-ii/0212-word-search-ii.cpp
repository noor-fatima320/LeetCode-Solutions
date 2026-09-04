class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            word = "";

            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    void insert(string word) {
        TrieNode* current = root;

        for (char c : word) {
            int index = c - 'a';

            if (current->child[index] == nullptr) {
                current->child[index] = new TrieNode();
            }

            current = current->child[index];
        }

        current->word = word;
    }

    int rows, cols;
    vector<string> answer;

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {

        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        char ch = board[r][c];

        if (ch == '#') {
            return;
        }

        int index = ch - 'a';

        if (node->child[index] == nullptr) {
            return;
        }

        TrieNode* next = node->child[index];

        // Complete word mil gaya
        if (next->word != "") {
            answer.push_back(next->word);

            // Duplicate result se bachne ke liye
            next->word = "";
        }

        // Current cell ko visited mark karo
        board[r][c] = '#';

        // Up
        dfs(board, r - 1, c, next);

        // Down
        dfs(board, r + 1, c, next);

        // Left
        dfs(board, r, c - 1, next);

        // Right
        dfs(board, r, c + 1, next);

        // Cell restore
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        rows = board.size();
        cols = board[0].size();

        root = new TrieNode();

        // Saare words Trie mein insert
        for (string word : words) {
            insert(word);
        }

        // Har cell se DFS
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(board, r, c, root);
            }
        }

        return answer;
    }
};