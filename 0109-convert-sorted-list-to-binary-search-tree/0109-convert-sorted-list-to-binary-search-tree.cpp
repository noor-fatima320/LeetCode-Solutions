class Solution {
public:

    TreeNode* sortedListToBST(ListNode* head) {

        // Agar list empty hai
        if (head == nullptr) {
            return nullptr;
        }

        // Agar sirf ek node hai
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }

        // Slow aur fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        // Middle node find karo
        while (fast != nullptr && fast->next != nullptr) {

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Middle ko left list se separate karo
        prev->next = nullptr;

        // Middle node BST ka root hoga
        TreeNode* root = new TreeNode(slow->val);

        // Left subtree
        root->left = sortedListToBST(head);

        // Right subtree
        root->right = sortedListToBST(slow->next);

        return root;
    }
};