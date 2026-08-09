class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int index, vector<int>& current) {

        // Current subset ko result mein add karo
        result.push_back(current);

        // Har possible next element try karo
        for (int i = index; i < nums.size(); i++) {

            // Element include karo
            current.push_back(nums[i]);

            // Next elements ke liye recursion
            backtrack(nums, i + 1, current);

            // Backtrack: element remove karo
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> current;

        backtrack(nums, 0, current);

        return result;
    }
};