class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {

        // Check if k nodes exist
        ListNode* temp = head;

        for(int i = 0; i < k; i++) {
            if(temp == nullptr)
                return head;

            temp = temp->next;
        }


        // Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for(int i = 0; i < k; i++) {

            ListNode* nextNode = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nextNode;
        }


        // head becomes tail after reverse
        head->next = reverseKGroup(curr, k);


        // prev is new head
        return prev;
    }
};