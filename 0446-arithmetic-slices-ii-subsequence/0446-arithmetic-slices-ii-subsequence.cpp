
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long long, long long>> dp(n);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)nums[i] - nums[j];

                long long count = 0;

                if (dp[j].count(diff)) {
                    count = dp[j][diff];
                }

                ans += count;
                dp[i][diff] += count + 1;
            }
        }

        return (int)ans;
    }
};
