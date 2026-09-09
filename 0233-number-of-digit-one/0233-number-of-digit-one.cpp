class Solution {
public:
    int countDigitOne(int n) {
        long long count = 0;

        for (long long place = 1; place <= n; place *= 10) {
            long long high = n / (place * 10);
            long long current = (n / place) % 10;
            long long low = n % place;

            if (current == 0) {
                count += high * place;
            }
            else if (current == 1) {
                count += high * place + low + 1;
            }
            else {
                count += (high + 1) * place;
            }
        }

        return count;
    }
};