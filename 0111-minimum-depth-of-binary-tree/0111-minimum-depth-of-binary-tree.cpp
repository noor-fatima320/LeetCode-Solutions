class Solution {
public:
    int minDepth(TreeNode* root) {

        // Tree empty hai
        if (root == nullptr) {
            return 0;
        }

        // Leaf node hai
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }

        // Sirf right child hai
        if (root->left == nullptr) {
            return 1 + minDepth(root->right);
        }

        // Sirf left child hai
        if (root->right == nullptr) {
            return 1 + minDepth(root->left);
        }

        // Dono children hain
        return 1 + min(minDepth(root->left),
                       minDepth(root->right));
    }
};