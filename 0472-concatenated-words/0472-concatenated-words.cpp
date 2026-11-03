class Solution {
public:
    bool canForm(string word, unordered_set<string>& st) {
        int n = word.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && st.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());

        vector<string> ans;

        for (string word : words) {
            st.erase(word);

            if (canForm(word, st)) {
                ans.push_back(word);
            }

            st.insert(word);
        }

        return ans;
    }
};