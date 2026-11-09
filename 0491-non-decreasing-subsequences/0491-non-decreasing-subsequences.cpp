
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(vector<int>& nums, int start) {
        if (path.size() >= 2) {
            ans.push_back(path);
        }

        unordered_set<int> used;

        for (int i = start; i < nums.size(); i++) {
            if (used.count(nums[i])) {
                continue;
            }

            if (!path.empty() && nums[i] < path.back()) {
                continue;
            }

            used.insert(nums[i]);

            path.push_back(nums[i]);

            backtrack(nums, i + 1);

            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        path.clear();

        backtrack(nums, 0);

        return ans;
    }
};
