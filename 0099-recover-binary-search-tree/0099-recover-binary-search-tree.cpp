class Solution {
public:

    vector<TreeNode*> nodes;

    void inorder(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        inorder(root->left);

        nodes.push_back(root);

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        inorder(root);

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        // Find first violation
        for (int i = 1; i < nodes.size(); i++) {

            if (nodes[i - 1]->val > nodes[i]->val) {

                if (first == nullptr) {
                    first = nodes[i - 1];
                }

                second = nodes[i];
            }
        }

        // Swap the values
        swap(first->val, second->val);
    }
};