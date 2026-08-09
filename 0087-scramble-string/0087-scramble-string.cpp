class Solution {
public:

    unordered_map<string, bool> memo;

    bool solve(string &s1, string &s2,
               int i, int j, int len) {

        // Same substring
        if (s1.substr(i, len) == s2.substr(j, len)) {
            return true;
        }

        // Key for memoization
        string key = to_string(i) + "," +
                     to_string(j) + "," +
                     to_string(len);

        if (memo.count(key)) {
            return memo[key];
        }

        // Check character frequency
        vector<int> count(26, 0);

        for (int k = 0; k < len; k++) {
            count[s1[i + k] - 'a']++;
            count[s2[j + k] - 'a']--;
        }

        // Different characters → impossible
        for (int x : count) {
            if (x != 0) {
                return memo[key] = false;
            }
        }

        // Try every possible split
        for (int k = 1; k < len; k++) {

            // Case 1: No swap
            bool noSwap =
                solve(s1, s2, i, j, k) &&
                solve(s1, s2, i + k, j + k, len - k);

            // Case 2: Swap
            bool swap =
                solve(s1, s2, i, j + len - k, k) &&
                solve(s1, s2, i + k, j, len - k);

            if (noSwap || swap) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {

        if (s1.length() != s2.length()) {
            return false;
        }

        return solve(s1, s2, 0, 0, s1.length());
    }
};