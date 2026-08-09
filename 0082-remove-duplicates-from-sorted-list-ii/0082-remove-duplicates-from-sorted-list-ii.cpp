class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Dummy node banaya
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {

            // Check karo current duplicate hai ya nahi
            if (curr->next != nullptr &&
                curr->val == curr->next->val) {

                int duplicateValue = curr->val;

                // Saare duplicate nodes skip karo
                while (curr != nullptr &&
                       curr->val == duplicateValue) {
                    curr = curr->next;
                }

                // Duplicate sequence ko remove
                prev->next = curr;
            }

            else {
                // Current unique hai
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};