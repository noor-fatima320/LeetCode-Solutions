class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if (numerator == 0)
            return "0";

        string result;

        // Negative sign
        if ((numerator < 0) ^ (denominator < 0))
            result += "-";

        long long num = llabs((long long)numerator);
        long long den = llabs((long long)denominator);

        // Integer part
        result += to_string(num / den);

        long long remainder = num % den;

        // No decimal part
        if (remainder == 0)
            return result;

        result += ".";

        // remainder -> position in result
        unordered_map<long long, int> mp;

        while (remainder != 0) {

            // Same remainder means repetition starts here
            if (mp.count(remainder)) {
                result.insert(mp[remainder], "(");
                result += ")";
                break;
            }

            mp[remainder] = result.length();

            remainder *= 10;

            result += to_string(remainder / den);

            remainder %= den;
        }

        return result;
    }
};