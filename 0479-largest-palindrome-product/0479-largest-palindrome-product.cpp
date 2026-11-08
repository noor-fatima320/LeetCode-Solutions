
class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        long long upper = 1;
        for (int i = 0; i < n; i++) {
            upper *= 10;
        }
        upper--;

        long long lower = upper / 10 + 1;

        for (long long i = upper; i >= lower; i--) {
            string s = to_string(i);
            string rev = s;
            reverse(rev.begin(), rev.end());

            long long palindrome = stoll(s + rev);

            for (long long j = upper; j * j >= palindrome; j--) {
                if (palindrome % j == 0) {
                    long long other = palindrome / j;

                    if (other >= lower && other <= upper) {
                        return palindrome % 1337;
                    }
                }
            }
        }

        return 0;
    }
};
