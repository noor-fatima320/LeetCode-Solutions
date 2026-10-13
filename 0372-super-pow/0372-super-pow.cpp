
class Solution {
public:
    int modPow(int a, int k) {
        int result = 1;
        a %= 1337;

        while (k > 0) {
            result = (result * a) % 1337;
            k--;
        }

        return result;
    }

    int superPow(int a, vector<int>& b) {
        int result = 1;

        for (int digit : b) {
            result = (modPow(result, 10) * modPow(a, digit)) % 1337;
        }

        return result;
    }
};
