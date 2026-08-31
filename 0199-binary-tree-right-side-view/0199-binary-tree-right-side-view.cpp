class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {

                TreeNode* current = q.front();
                q.pop();

                // Last node of this level
                if (i == levelSize - 1) {
                    result.push_back(current->val);
                }

                if (current->left != nullptr) {
                    q.push(current->left);
                }

                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }
        }

        return result;
    }
};