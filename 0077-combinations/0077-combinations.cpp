class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(int start, int n, int k) {
        // We have selected k numbers
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++) {
            // Choose
            current.push_back(i);

            // Explore
            backtrack(i + 1, n, k);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(1, n, k);
        return result;
    }
};