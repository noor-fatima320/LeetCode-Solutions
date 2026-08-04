class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ans;

        for (int num = minVal; num <= maxVal; num++) {
            if (!st.count(num)) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};