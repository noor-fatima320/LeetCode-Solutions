class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;

        for (int num : nums) {
            x ^= num;
        }

        long long bit = x & -x;

        int a = 0, b = 0;

        for (int num : nums) {
            if ((num & bit) != 0)
                a ^= num;
            else
                b ^= num;
        }

        return {a, b};
    }
};