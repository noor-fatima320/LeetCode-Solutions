class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);

        // prev[r] = number of subarrays ending at previous index
        // whose product % k == r
        vector<long long> prev(k, 0);

        for (int num : nums) {
            vector<long long> cur(k, 0);

            int x = num % k;

            // Start a new subarray with only nums[i]
            cur[x]++;

            // Extend all previous subarrays by nums[i]
            for (int r = 0; r < k; r++) {
                if (prev[r] == 0) continue;

                int newRemainder = (r * x) % k;
                cur[newRemainder] += prev[r];
            }

            // Every subarray ending here represents one valid operation
            for (int r = 0; r < k; r++) {
                ans[r] += cur[r];
            }

            prev = cur;
        }

        return ans;
    }
};