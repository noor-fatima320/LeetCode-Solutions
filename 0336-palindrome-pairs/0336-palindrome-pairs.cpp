
class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;

        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
        }

        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++) {
            string w = words[i];
            int n = w.size();

            for (int j = 0; j <= n; j++) {
                string left = w.substr(0, j);
                string right = w.substr(j);

                if (isPalindrome(w, 0, j - 1)) {
                    string rev = right;
                    reverse(rev.begin(), rev.end());

                    auto it = mp.find(rev);

                    if (it != mp.end() && it->second != i) {
                        ans.push_back({it->second, i});
                    }
                }

                if (j < n && isPalindrome(w, j, n - 1)) {
                    string rev = left;
                    reverse(rev.begin(), rev.end());

                    auto it = mp.find(rev);

                    if (it != mp.end() && it->second != i) {
                        ans.push_back({i, it->second});
                    }
                }
            }
        }

        return ans;
    }
};