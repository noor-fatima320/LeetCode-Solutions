class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;

        // Store numbers and calculate (n-1)!
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        k--; // Convert to 0-based indexing

        string ans = "";

        while (true) {
            ans += to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + (k / fact));

            if (numbers.empty())
                break;

            k %= fact;
            fact /= numbers.size();
        }

        return ans;
    }
};