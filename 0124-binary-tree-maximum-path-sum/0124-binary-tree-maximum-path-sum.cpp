class Solution {
public:
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftGain = max(0, dfs(root->left));
        int rightGain = max(0, dfs(root->right));

        int currentPath = root->val + leftGain + rightGain;

        ans = max(ans, currentPath);

        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};