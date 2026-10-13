
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < min(n, k); i++) {
            pq.push({(long long)nums1[i] + nums2[0], i, 0});
        }

        while (k > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < m) {
                pq.push({(long long)nums1[i] + nums2[j + 1], i, j + 1});
            }

            k--;
        }

        return ans;
    }
};
