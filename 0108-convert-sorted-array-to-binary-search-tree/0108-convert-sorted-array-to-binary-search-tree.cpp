class Solution {
public:

    TreeNode* buildTree(vector<int>& nums, int left, int right) {

        // Agar range empty hai
        if (left > right) {
            return nullptr;
        }

        // Middle element ko root banayenge
        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        // Left half se left subtree
        root->left = buildTree(nums, left, mid - 1);

        // Right half se right subtree
        root->right = buildTree(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};