class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n) {
            return ans;
        }

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);

        for (int i = 0; i < m; i++) {
            pCount[p[i] - 'a']++;
            sCount[s[i] - 'a']++;
        }

        if (pCount == sCount) {
            ans.push_back(0);
        }

        for (int i = m; i < n; i++) {
            sCount[s[i] - 'a']++;
            sCount[s[i - m] - 'a']--;

            if (sCount == pCount) {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};