class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        map<int, int> startMap;

        for (int i = 0; i < n; i++) {
            startMap[intervals[i][0]] = i;
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            auto it = startMap.lower_bound(intervals[i][1]);

            if (it != startMap.end()) {
                ans[i] = it->second;
            }
        }

        return ans;
    }
};