class Solution {
public:

    int getLeftHeight(TreeNode* root) {
        int height = 0;

        while (root != nullptr) {
            height++;
            root = root->left;
        }

        return height;
    }

    int getRightHeight(TreeNode* root) {
        int height = 0;

        while (root != nullptr) {
            height++;
            root = root->right;
        }

        return height;
    }

    int countNodes(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int leftHeight = getLeftHeight(root);
        int rightHeight = getRightHeight(root);

        // Perfect binary tree
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

        // Not perfect
        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};