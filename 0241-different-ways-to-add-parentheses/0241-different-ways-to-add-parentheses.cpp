class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];

            if (op == '+' || op == '-' || op == '*') {
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                vector<int> leftResults = diffWaysToCompute(left);
                vector<int> rightResults = diffWaysToCompute(right);

                for (int a : leftResults) {
                    for (int b : rightResults) {
                        if (op == '+')
                            result.push_back(a + b);
                        else if (op == '-')
                            result.push_back(a - b);
                        else
                            result.push_back(a * b);
                    }
                }
            }
        }

        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result;
    }
};