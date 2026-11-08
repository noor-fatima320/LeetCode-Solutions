
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < 32; i++) {
            int ones = 0;

            for (int num : nums) {
                if (num & (1 << i)) {
                    ones++;
                }
            }

            int zeros = n - ones;

            ans += ones * zeros;
        }

        return ans;
    }
};
