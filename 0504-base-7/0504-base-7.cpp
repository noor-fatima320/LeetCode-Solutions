
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";

        bool negative = num < 0;
        num = abs(num);

        string ans = "";

        while (num > 0) {
            int remainder = num % 7;
            ans += to_string(remainder);
            num /= 7;
        }

        reverse(ans.begin(), ans.end());

        if (negative) {
            ans = "-" + ans;
        }

        return ans;
    }
};
