class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        string calendrix = s;

        vector<int> left(26, 0);

        for (char c : s) {
            left[c - 'a']++;
        }

        string midCh = "";

        for (int i = 0; i < 26; i++) {
            if (left[i] % 2 == 1) {
                if (!midCh.empty()) {
                    return "";
                }

                midCh = string(1, char('a' + i));
                left[i]--;
            }
        }

        int n = s.size();

        // Match target's left half.
        for (int i = 0; i < n / 2; i++) {
            left[target[i] - 'a'] -= 2;
        }

        int negative = 0;
        int largest = -1;

        for (int i = 0; i < 26; i++) {
            if (left[i] < 0) {
                negative++;
            } else if (left[i] > 0) {
                largest = max(largest, i);
            }
        }

        // The left half can be exactly the same as target's left half.
        // Then compare the forced right half.
        if (negative == 0) {
            string leftPart = target.substr(0, n / 2);

            string reversedLeft = leftPart;
            reverse(reversedLeft.begin(), reversedLeft.end());

            string rightPart = midCh + reversedLeft;

            if (rightPart > target.substr(n / 2)) {
                return leftPart + rightPart;
            }
        }

        // Find the rightmost position where we can make
        // the left half larger than target's left half.
        for (int i = n / 2 - 1; i >= 0; i--) {
            int b = target[i] - 'a';

            // Put target[i] back because we are moving
            // the change point to this position.
            left[b] += 2;

            if (left[b] == 0) {
                negative--;
            }

            if (left[b] == 2) {
                largest = max(largest, b);
            }

            // We cannot match the prefix, or there is
            // no available character greater than target[i].
            if (negative > 0 || largest <= b) {
                continue;
            }

            // Find the smallest available character > b.
            int j = b + 1;

            while (j < 26 && left[j] == 0) {
                j++;
            }

            if (j == 26) {
                continue;
            }

            left[j] -= 2;

            string ans = target.substr(0, i + 1);

            ans[i] = char('a' + j);

            // Fill the rest of the left half with the
            // smallest available characters.
            for (int k = 0; k < 26; k++) {
                while (left[k] >= 2) {
                    ans += char('a' + k);
                    left[k] -= 2;
                }
            }

            string right = ans;
            reverse(right.begin(), right.end());

            ans += midCh;
            ans += right;

            return ans;
        }

        return "";
    }
};
