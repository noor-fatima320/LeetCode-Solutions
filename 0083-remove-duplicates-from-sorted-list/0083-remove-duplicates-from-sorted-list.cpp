class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* current = head;

        while (current != nullptr &&
               current->next != nullptr) {

            if (current->val == current->next->val) {

                // Duplicate node remove
                current->next = current->next->next;
            }
            else {

                // Next node par jao
                current = current->next;
            }
        }

        return head;
    }
};