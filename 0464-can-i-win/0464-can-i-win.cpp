class Solution {
public:
    vector<int> dp;

    bool solve(int mask, int remaining, int maxChoosableInteger) {

        if (dp[mask] != -1)
            return dp[mask];

        for (int i = 1; i <= maxChoosableInteger; i++) {

            int bit = 1 << i;

            if (mask & bit)
                continue;

            if (i >= remaining) {
                return dp[mask] = true;
            }

            if (!solve(mask | bit, remaining - i, maxChoosableInteger)) {
                return dp[mask] = true;
            }
        }

        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        if (desiredTotal <= 0)
            return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        if (sum < desiredTotal)
            return false;

        dp.assign(1 << (maxChoosableInteger + 1), -1);

        return solve(0, desiredTotal, maxChoosableInteger);
    }
};