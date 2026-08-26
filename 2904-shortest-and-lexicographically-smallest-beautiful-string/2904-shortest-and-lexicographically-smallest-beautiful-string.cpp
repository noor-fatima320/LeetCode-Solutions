class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int left = 0;
        int ones = 0;
        int minLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1') {
                ones++;
            }

            // Window has exactly k ones
            while (ones == k) {

                int len = right - left + 1;

                // Better length
                if (len < minLen) {
                    minLen = len;
                    ans = s.substr(left, len);
                }
                // Same length -> lexicographically smaller
                else if (len == minLen) {
                    string candidate = s.substr(left, len);

                    if (candidate < ans) {
                        ans = candidate;
                    }
                }

                // Shrink window
                if (s[left] == '1') {
                    ones--;
                }

                left++;
            }
        }

        return ans;
    }
};