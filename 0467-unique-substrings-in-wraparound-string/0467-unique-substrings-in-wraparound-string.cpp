class Solution {
public:
    int findSubstringInWraproundString(string s) {

        vector<int> dp(26, 0);

        int len = 0;

        for (int i = 0; i < s.size(); i++) {

            if (i > 0 && 
                (s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25)) {
                len++;
            }
            else {
                len = 1;
            }

            int index = s[i] - 'a';

            dp[index] = max(dp[index], len);
        }

        int ans = 0;

        for (int x : dp) {
            ans += x;
        }

        return ans;
    }
};