class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(int index, vector<int>& candidates, int target) {

        if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (index == candidates.size() || target < 0)
            return;

        // Include current element
        path.push_back(candidates[index]);
        solve(index, candidates, target - candidates[index]);
        path.pop_back();

        // Exclude current element
        solve(index + 1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, candidates, target);
        return ans;
    }
};