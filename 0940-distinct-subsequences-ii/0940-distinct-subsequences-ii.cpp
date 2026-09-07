class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        long long dp = 1;  // empty subsequence

        long long last[26] = {};

        for (char c : s) {
            int x = c - 'a';

            long long newDp = (2 * dp - last[x] + MOD) % MOD;

            last[x] = dp;
            dp = newDp;
        }

        // Remove the empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};