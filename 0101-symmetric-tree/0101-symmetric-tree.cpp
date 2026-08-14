class Solution {
public:

    bool isMirror(TreeNode* left, TreeNode* right) {

        // Case 1: Dono nodes NULL hain
        if (left == nullptr && right == nullptr) {
            return true;
        }

        // Case 2: Sirf ek node NULL hai
        if (left == nullptr || right == nullptr) {
            return false;
        }

        // Case 3: Dono ki values different hain
        if (left->val != right->val) {
            return false;
        }

        // Case 4: Mirror children check karo
        return isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        // Root ke left aur right subtree ko compare karo
        return isMirror(root->left, root->right);
    }
};