
class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }

        string result = "";
        string hex = "0123456789abcdef";

        unsigned int n = num;

        while (n > 0) {
            int remainder = n & 15;
            result += hex[remainder];
            n >>= 4;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
