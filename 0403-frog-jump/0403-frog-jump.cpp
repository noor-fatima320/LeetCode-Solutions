
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (stones[1] != 1) {
            return false;
        }

        unordered_map<int, int> position;
        vector<unordered_set<int>> dp(n);

        for (int i = 0; i < n; i++) {
            position[stones[i]] = i;
        }

        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            for (int jump : dp[i]) {
                for (int change = -1; change <= 1; change++) {
                    int nextJump = jump + change;

                    if (nextJump <= 0) {
                        continue;
                    }

                    long long nextPosition =
                        (long long)stones[i] + nextJump;

                    if (nextPosition > INT_MAX) {
                        continue;
                    }

                    if (position.count((int)nextPosition)) {
                        int nextIndex = position[(int)nextPosition];
                        dp[nextIndex].insert(nextJump);
                    }
                }
            }
        }

        return !dp[n - 1].empty();
    }
};
