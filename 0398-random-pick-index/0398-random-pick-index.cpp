
class Solution {
private:
    vector<int> nums;

public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int index = -1;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                count++;

                if (rand() % count == 0) {
                    index = i;
                }
            }
        }

        return index;
    }
};
