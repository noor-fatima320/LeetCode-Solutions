class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '('
        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // Add ')'
        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};