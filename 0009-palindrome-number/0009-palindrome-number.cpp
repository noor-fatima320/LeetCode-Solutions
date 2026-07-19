class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers are not palindrome
        if (x < 0)
            return false;

        int original = x;
        int reversed = 0;

        while (x != 0) {

            int digit = x % 10;

            // Overflow check
            if (reversed > (INT_MAX - digit) / 10)
                return false;

            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};