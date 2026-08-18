class Solution {
public:

    int dfs(TreeNode* root, int currentNumber) {

        if (root == nullptr) {
            return 0;
        }

        // Add current digit
        currentNumber = currentNumber * 10 + root->val;

        // If leaf node, return the number
        if (root->left == nullptr && root->right == nullptr) {
            return currentNumber;
        }

        // Recursively calculate left and right
        return dfs(root->left, currentNumber)
             + dfs(root->right, currentNumber);
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};