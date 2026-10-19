
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        long long F = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += 1LL * i * nums[i];
        }

        long long ans = F;

        for (int i = 1; i < n; i++) {
            F = F + sum - 1LL * n * nums[n - i];
            ans = max(ans, F);
        }

        return static_cast<int>(ans);
    }
};
