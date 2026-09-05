class Solution {
public:
    vector<vector<int>> result;

    void backtrack(int start, int k, int n, vector<int>& current) {
        // Agar k numbers select ho gaye
        if (current.size() == k) {
            if (n == 0) {
                result.push_back(current);
            }
            return;
        }

        // 1 se 9 tak numbers
        for (int i = start; i <= 9; i++) {

            // Agar number n se bara hai to aage bhi
            // koi valid combination nahi banegi
            if (i > n) {
                break;
            }

            current.push_back(i);

            // i + 1: same number dobara use nahi hoga
            backtrack(i + 1, k, n - i, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> current;

        backtrack(1, k, n, current);

        return result;
    }
};