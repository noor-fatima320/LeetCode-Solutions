class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Value + original index
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        // Values ko sort kar do
        sort(arr.begin(), arr.end());

        vector<int> ans(n);

        int start = 0;

        while (start < n) {
            int end = start;

            // Ek group banao jahan consecutive values
            // ka difference <= limit ho
            while (end + 1 < n &&
                   arr[end + 1].first - arr[end].first <= limit) {
                end++;
            }

            // Is group ke original indexes collect karo
            vector<int> indices;

            for (int i = start; i <= end; i++) {
                indices.push_back(arr[i].second);
            }

            // Original indexes sort karo
            sort(indices.begin(), indices.end());

            // Sorted values ko sorted original indexes par place karo
            for (int i = start; i <= end; i++) {
                ans[indices[i - start]] = arr[i].first;
            }

            start = end + 1;
        }

        return ans;
    }
};