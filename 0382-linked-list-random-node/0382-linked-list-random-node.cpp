
class Solution {
private:
    vector<int> nums;
    mt19937 rng;

public:
    Solution(ListNode* head) : rng(random_device{}()) {
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        uniform_int_distribution<int> dist(0, nums.size() - 1);
        return nums[dist(rng)];
    }
};
