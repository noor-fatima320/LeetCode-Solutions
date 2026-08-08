class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // prefix[i] = number of characters from word2
        // that can be matched using word1[0..i]
        vector<int> prefix(n, 0);

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (j < m && word1[i] == word2[j]) {
                j++;
            }

            prefix[i] = j;
        }

        // If word2 itself is not almost a subsequence,
        // we may still be able to use one modification.
        //
        // suffix[i] = number of characters from word2
        // that can be matched using word1[i..n-1]
        vector<int> suffix(n, 0);

        j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            suffix[i] = m - 1 - j;
        }

        vector<int> answer;

        int pos = 0;
        bool changed = false;

        for (int k = 0; k < m; k++) {

            // Try to find the earliest possible index.
            while (pos < n) {

                // Case 1:
                // Current character matches normally.
                if (word1[pos] == word2[k]) {

                    // Make sure enough characters remain afterward.
                    if (n - pos >= m - k) {
                        answer.push_back(pos);
                        pos++;
                        break;
                    }
                }

                // Case 2:
                // We can modify this character.
                if (!changed) {

                    // We need k characters before this one
                    // and m-k-1 characters after it.
                    bool prefixOK = (pos == 0 || prefix[pos - 1] >= k);

                    bool suffixOK =
                        (pos + 1 == n || suffix[pos + 1] >= m - k - 1);

                    if (prefixOK && suffixOK) {
                        answer.push_back(pos);
                        pos++;
                        changed = true;
                        break;
                    }
                }

                pos++;
            }

            // Couldn't find a valid index.
            if (answer.size() != k + 1) {
                return {};
            }
        }

        return answer;
    }
};