class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Agar tree empty hai
        if (root == nullptr) {
            return 0;
        }

        // Left aur right subtree ki depth
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Dono mein se maximum depth + current node
        return 1 + max(leftDepth, rightDepth);
    }
};