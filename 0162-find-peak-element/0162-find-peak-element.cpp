class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // Peak mid par ho sakta hai
                right = mid;
            } else {
                // Peak right side par hoga
                left = mid + 1;
            }
        }

        return left;
    }
};