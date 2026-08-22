class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {
                // Minimum left side mein ya mid par hai
                right = mid;
            }
            else if (nums[mid] > nums[right]) {
                // Minimum right side mein hai
                left = mid + 1;
            }
            else {
                // nums[mid] == nums[right]
                // Duplicate ki wajah se decide nahi kar sakte
                right--;
            }
        }

        return nums[left];
    }
};