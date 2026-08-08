class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        vector<int> freq(128, 0);

        // t ke required characters count karo
        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int required = t.size();

        int minLength = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            // Current character window mein add
            if (freq[s[right]] > 0) {
                required--;
            }

            freq[s[right]]--;

            // Window valid hai
            while (required == 0) {

                // Minimum window update karo
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                // Left character remove karo
                freq[s[left]]++;

                if (freq[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, minLength);
    }
};