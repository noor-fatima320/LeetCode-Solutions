class Solution {
public:
    void flatten(TreeNode* root) {

        TreeNode* current = root;

        while (current != nullptr) {

            // Agar left subtree exist karta hai
            if (current->left != nullptr) {

                // Left subtree ka rightmost node find karo
                TreeNode* predecessor = current->left;

                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }

                // Current ka right subtree
                // left subtree ke end mein attach karo
                predecessor->right = current->right;

                // Left subtree ko right side par le aao
                current->right = current->left;

                // Left pointer null hona chahiye
                current->left = nullptr;
            }

            // Next node
            current = current->right;
        }
    }
};