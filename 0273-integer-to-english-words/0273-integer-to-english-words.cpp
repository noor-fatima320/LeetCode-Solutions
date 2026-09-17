class Solution {
public:
    vector<string> below20 = {
        "", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };

    vector<string> tens = {
        "", "", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };

    string helper(int num) {
        string result;

        if (num >= 100) {
            result += below20[num / 100] + " Hundred";
            num %= 100;

            if (num != 0)
                result += " ";
        }

        if (num >= 20) {
            result += tens[num / 10];
            num %= 10;

            if (num != 0)
                result += " ";
        }

        if (num > 0) {
            result += below20[num];
        }

        return result;
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        string result;

        if (num >= 1000000000) {
            result += helper(num / 1000000000) + " Billion";
            num %= 1000000000;

            if (num != 0)
                result += " ";
        }

        if (num >= 1000000) {
            result += helper(num / 1000000) + " Million";
            num %= 1000000;

            if (num != 0)
                result += " ";
        }

        if (num >= 1000) {
            result += helper(num / 1000) + " Thousand";
            num %= 1000;

            if (num != 0)
                result += " ";
        }

        if (num > 0) {
            result += helper(num);
        }

        return result;
    }
};