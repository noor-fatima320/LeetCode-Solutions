
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        for (int num : nums) {
            left = max(left, num);
            right += num;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            int parts = 1;
            int sum = 0;

            for (int num : nums) {
                if (sum + num > mid) {
                    parts++;
                    sum = num;
                } else {
                    sum += num;
                }
            }

            if (parts <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
