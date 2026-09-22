class Solution {
public:
    vector<string> ans;
    string num;

    void backtrack(int index, long long value, long long prev,
                   long long target, string expression) {

        if (index == num.size()) {
            if (value == target) {
                ans.push_back(expression);
            }
            return;
        }

        long long current = 0;

        for (int i = index; i < num.size(); i++) {

            // Leading zero is not allowed
            if (i > index && num[index] == '0')
                break;

            current = current * 10 + (num[i] - '0');

            string currentStr = num.substr(index, i - index + 1);

            // First number
            if (index == 0) {
                backtrack(i + 1, current, current,
                          target, currentStr);
            }
            else {
                // Addition
                backtrack(i + 1,
                          value + current,
                          current,
                          target,
                          expression + "+" + currentStr);

                // Subtraction
                backtrack(i + 1,
                          value - current,
                          -current,
                          target,
                          expression + "-" + currentStr);

                // Multiplication
                backtrack(i + 1,
                          value - prev + prev * current,
                          prev * current,
                          target,
                          expression + "*" + currentStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        this->num = num;
        ans.clear();

        backtrack(0, 0, 0, target, "");

        return ans;
    }
};