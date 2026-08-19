class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length();

        unordered_set<string> words(wordDict.begin(), wordDict.end());

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j < i; j++) {

                string word = s.substr(j, i - j);

                if (dp[j] && words.count(word)) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};