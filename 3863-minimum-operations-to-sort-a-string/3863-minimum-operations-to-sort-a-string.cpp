
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        if (n == 2) {
            return -1;
        }

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }

        char maxAfterFirst =
            *max_element(s.begin() + 1, s.end());

        char minBeforeLast =
            *min_element(s.begin(), s.end() - 1);

        if (s[0] > maxAfterFirst &&
            s[n - 1] < minBeforeLast) {
            return 3;
        }

        return 2;
    }
};
