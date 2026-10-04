class Solution {
public:
    string addStrings(string a, string b) {
        string result;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result += char('0' + (sum % 10));
            carry = sum / 10;
        }

        reverse(result.begin(), result.end());
        return result;
    }

    bool check(string& num, string a, string b, int start) {
        int n = num.size();

        while (start < n) {
            string sum = addStrings(a, b);

            if (start + sum.size() > n) {
                return false;
            }

            if (num.substr(start, sum.size()) != sum) {
                return false;
            }

            start += sum.size();

            a = b;
            b = sum;
        }

        return true;
    }

    bool isAdditiveNumber(string num) {
        int n = num.size();

        for (int i = 1; i <= n - 2; i++) {

            // First number cannot have leading zero
            if (num[0] == '0' && i > 1) {
                break;
            }

            string a = num.substr(0, i);

            for (int j = i + 1; j <= n - 1; j++) {

                // Second number cannot have leading zero
                if (num[i] == '0' && j - i > 1) {
                    break;
                }

                string b = num.substr(i, j - i);

                if (check(num, a, b, j)) {
                    return true;
                }
            }
        }

        return false;
    }
};