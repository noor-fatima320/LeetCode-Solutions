
class Solution {
public:
    int findNthDigit(int n) {
        long long length = 1;
        long long count = 9;
        long long start = 1;

        while (n > length * count) {
            n -= length * count;
            length++;
            count *= 10;
            start *= 10;
        }

        long long number = start + (n - 1) / length;

        string s = to_string(number);

        return s[(n - 1) % length] - '0';
    }
};
