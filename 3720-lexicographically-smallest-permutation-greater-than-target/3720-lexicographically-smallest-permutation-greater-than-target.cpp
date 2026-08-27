class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        int n = s.size();

        // Try to make prefix equal to target
        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (cnt[x] > 0) {
                cnt[x]--;
                continue;
            }

            // Current character is not available.
            // Backtrack and make some previous position bigger.
            for (int j = i; j >= 0; j--) {

                if (j < i) {
                    cnt[target[j] - 'a']++;
                }

                int cur = target[j] - 'a';

                // Find smallest available character > target[j]
                for (int c = cur + 1; c < 26; c++) {
                    if (cnt[c] > 0) {

                        string ans = target.substr(0, j);

                        ans += char('a' + c);
                        cnt[c]--;

                        // Put remaining characters in sorted order
                        for (int k = 0; k < 26; k++) {
                            while (cnt[k] > 0) {
                                ans += char('a' + k);
                                cnt[k]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // s can form exactly target.
        // We still need a STRICTLY greater permutation.
        for (int j = n - 1; j >= 0; j--) {

            cnt[target[j] - 'a']++;

            int cur = target[j] - 'a';

            for (int c = cur + 1; c < 26; c++) {
                if (cnt[c] > 0) {

                    string ans = target.substr(0, j);

                    ans += char('a' + c);
                    cnt[c]--;

                    for (int k = 0; k < 26; k++) {
                        while (cnt[k] > 0) {
                            ans += char('a' + k);
                            cnt[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};