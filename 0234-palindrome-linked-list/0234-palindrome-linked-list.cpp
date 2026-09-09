class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;

        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = values.size() - 1;

        while (left < right) {
            if (values[left] != values[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};