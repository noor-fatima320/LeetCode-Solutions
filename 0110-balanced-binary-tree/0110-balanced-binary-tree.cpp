class Solution {
public:

    int height(TreeNode* root) {

        // Empty tree ki height 0
        if (root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Agar kisi subtree mein imbalance hai
        if (leftHeight == -1 || rightHeight == -1) {
            return -1;
        }

        // Height difference 1 se zyada hai
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Current node ki height
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};