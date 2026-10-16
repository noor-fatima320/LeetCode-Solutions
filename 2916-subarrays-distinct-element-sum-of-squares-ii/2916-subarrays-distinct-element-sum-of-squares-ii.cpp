
class Solution {
public:
    static const int MOD = 1000000007;

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sum(4 * n, 0);
        vector<long long> sq(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        function<void(int, int, int, int, int, long long)> update =
        [&](int node, int start, int end, int l, int r, long long val) {
            if (l > end || r < start) return;

            if (l <= start && end <= r) {
                long long len = end - start + 1;
                sq[node] = (sq[node] + 2 * val * sum[node] % MOD
                            + len * val % MOD * val % MOD) % MOD;
                sum[node] = (sum[node] + len * val) % MOD;
                lazy[node] = (lazy[node] + val) % MOD;
                return;
            }

            int mid = start + (end - start) / 2;

            if (lazy[node] != 0) {
                long long v = lazy[node];

                for (int child : {node * 2, node * 2 + 1}) {
                    int a = (child == node * 2) ? start : mid + 1;
                    int b = (child == node * 2) ? mid : end;
                    long long len = b - a + 1;

                    sq[child] = (sq[child] + 2 * v * sum[child] % MOD
                                 + len * v % MOD * v % MOD) % MOD;
                    sum[child] = (sum[child] + len * v) % MOD;
                    lazy[child] = (lazy[child] + v) % MOD;
                }

                lazy[node] = 0;
            }

            update(node * 2, start, mid, l, r, val);
            update(node * 2 + 1, mid + 1, end, l, r, val);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        long long ans = 0;
        unordered_map<int, int> last;

        for (int i = 0; i < n; i++) {
            int l = 0;

            if (last.count(nums[i])) {
                l = last[nums[i]] + 1;
            }

            update(1, 0, n - 1, l, i, 1);
            last[nums[i]] = i;

            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};
