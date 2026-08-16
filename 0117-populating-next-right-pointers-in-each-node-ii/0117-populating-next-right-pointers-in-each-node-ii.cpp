class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        Node* current = root;

        while (current != NULL) {
            Node dummy(0);
            Node* tail = &dummy;

            while (current != NULL) {
                if (current->left != NULL) {
                    tail->next = current->left;
                    tail = tail->next;
                }

                if (current->right != NULL) {
                    tail->next = current->right;
                    tail = tail->next;
                }

                current = current->next;
            }

            current = dummy.next;
        }

        return root;
    }
};