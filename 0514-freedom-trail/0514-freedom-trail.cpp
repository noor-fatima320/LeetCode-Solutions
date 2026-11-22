class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (char ch : key) {
            vector<int> next(n, INT_MAX);

            for (int i = 0; i < n; i++) {
                if (dp[i] == INT_MAX) continue;

                for (int j = 0; j < n; j++) {
                    if (ring[j] == ch) {
                        int diff = abs(i - j);
                        int rotate = min(diff, n - diff);

                        next[j] = min(next[j], dp[i] + rotate + 1);
                    }
                }
            }

            dp = next;
        }

        return *min_element(dp.begin(), dp.end());
    }
};