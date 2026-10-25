
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size());
    }

    Node* build(vector<vector<int>>& grid, int r, int c, int size) {
        bool same = true;
        int value = grid[r][c];

        for (int i = r; i < r + size; i++) {
            for (int j = c; j < c + size; j++) {
                if (grid[i][j] != value) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }

        if (same) {
            return new Node(value == 1, true);
        }

        Node* root = new Node(true, false);
        int half = size / 2;

        root->topLeft = build(grid, r, c, half);
        root->topRight = build(grid, r, c + half, half);
        root->bottomLeft = build(grid, r + half, c, half);
        root->bottomRight = build(grid, r + half, c + half, half);

        return root;
    }
};
