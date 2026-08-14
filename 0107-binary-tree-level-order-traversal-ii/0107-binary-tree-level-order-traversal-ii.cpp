class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> result;

        // Agar tree empty hai
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int levelSize = q.size();

            vector<int> currentLevel;

            // Current level ke saare nodes process karo
            for (int i = 0; i < levelSize; i++) {

                TreeNode* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                // Left child
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // Right child
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // Current level result mein add karo
            result.push_back(currentLevel);
        }

        // Result ko bottom-up kar do
        reverse(result.begin(), result.end());

        return result;
    }
};