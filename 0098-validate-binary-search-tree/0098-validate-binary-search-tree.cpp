class Solution {
public:

    bool check(TreeNode* node, long long lower, long long upper) {

        // Empty tree/subtree is valid
        if (node == nullptr) {
            return true;
        }

        // Current value must be strictly
        // between lower and upper
        if (node->val <= lower || node->val >= upper) {
            return false;
        }

        // Check left subtree
        if (!check(node->left, lower, node->val)) {
            return false;
        }

        // Check right subtree
        if (!check(node->right, node->val, upper)) {
            return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {

        return check(root, LLONG_MIN, LLONG_MAX);
    }
};