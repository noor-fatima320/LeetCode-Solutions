
class Solution {
public:
    string smallestGoodBase(string n) {
        long long num = stoll(n);

        for (int m = 60; m >= 2; m--) {
            long long left = 2;
            long long right = pow(num, 1.0 / (m - 1)) + 1;

            while (left <= right) {
                long long mid = left + (right - left) / 2;

                __int128 sum = 1;
                __int128 power = 1;

                for (int i = 1; i < m; i++) {
                    power *= mid;
                    sum += power;

                    if (sum > num) break;
                }

                if (sum == num) {
                    return to_string(mid);
                }

                if (sum < num) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return to_string(num - 1);
    }
};
