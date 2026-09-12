class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 3>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2]};
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int x, int y) {
            if (a[x][0] != a[y][0])
                return a[x][0] < a[y][0];
            return x < y;
        });

        vector<int> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[order[i]][0];
        }

        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            int r = a[order[i]][1];

            nxt[i] = lower_bound(starts.begin(), starts.end(), r + 1)
                     - starts.begin();
        }

        vector<vector<int>> dp(5 * (n + 1));

        auto better = [](const vector<int>& x, const vector<int>& y) {
            if (y.empty())
                return true;

            if (x.empty())
                return false;

            return lexicographical_compare(
                x.begin(), x.end(),
                y.begin(), y.end()
            );
        };

        vector<vector<long long>> score(5, vector<long long>(n + 1, 0));
        vector<vector<vector<int>>> best(
            5, vector<vector<int>>(n + 1)
        );

        for (int k = 1; k <= 4; k++) {
            for (int i = n - 1; i >= 0; i--) {

                score[k][i] = score[k][i + 1];
                best[k][i] = best[k][i + 1];

                int j = nxt[i];

                long long take = a[order[i]][2];

                if (j < n)
                    take += score[k - 1][j];

                vector<int> candidate;
                candidate.push_back(order[i]);

                if (j < n) {
                    for (int x : best[k - 1][j]) {
                        candidate.push_back(x);
                    }
                }

                sort(candidate.begin(), candidate.end());

                if (take > score[k][i] ||
                    (take == score[k][i] &&
                     better(candidate, best[k][i]))) {

                    score[k][i] = take;
                    best[k][i] = candidate;
                }
            }
        }

        return best[4][0];
    }
};