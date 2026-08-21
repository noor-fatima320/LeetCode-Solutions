class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long countAmounts(long long x, vector<int>& coins) {

        int n = coins.size();

        long long total = 0;

        // Try every non-empty subset
        for (int mask = 1; mask < (1 << n); mask++) {

            long long currentLCM = 1;

            int bits = 0;

            bool valid = true;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    currentLCM =
                        lcm(currentLCM, coins[i]);

                    // LCM is already bigger than x
                    if (currentLCM > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if (!valid) {
                continue;
            }

            long long count = x / currentLCM;

            // Odd subset -> add
            if (bits % 2 == 1) {
                total += count;
            }

            // Even subset -> subtract
            else {
                total -= count;
            }
        }

        return total;
    }

    long long findKthSmallest(
        vector<int>& coins,
        long long k
    ) {

        long long left = 1;

        long long right =
            1LL * (*min_element(coins.begin(), coins.end())) * k;

        while (left < right) {

            long long mid =
                left + (right - left) / 2;

            if (countAmounts(mid, coins) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};