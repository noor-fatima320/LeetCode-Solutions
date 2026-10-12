class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;

        for (int left = 0; left < n; left++) {
            vector<int> rowSum(m, 0);

            for (int right = left; right < n; right++) {
                for (int r = 0; r < m; r++) {
                    rowSum[r] += matrix[r][right];
                }

                set<int> prefix;
                prefix.insert(0);
                int sum = 0;

                for (int x : rowSum) {
                    sum += x;

                    auto it = prefix.lower_bound(sum - k);

                    if (it != prefix.end()) {
                        ans = max(ans, sum - *it);
                    }

                    prefix.insert(sum);
                }

                if (ans == k) {
                    return k;
                }
            }
        }

        return ans;
    }
};