class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        // Tree empty hai
        if (root == nullptr) {
            return false;
        }

        // Leaf node par pohanch gaye
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        // Remaining target sum
        int remaining = targetSum - root->val;

        // Left ya right mein path check karo
        return hasPathSum(root->left, remaining) ||
               hasPathSum(root->right, remaining);
    }
};