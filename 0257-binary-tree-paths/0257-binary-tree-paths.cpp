class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        if (root == nullptr)
            return result;

        string path = to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(path);
            return result;
        }

        if (root->left != nullptr) {
            vector<string> leftPaths = binaryTreePaths(root->left);

            for (string p : leftPaths) {
                result.push_back(path + "->" + p);
            }
        }

        if (root->right != nullptr) {
            vector<string> rightPaths = binaryTreePaths(root->right);

            for (string p : rightPaths) {
                result.push_back(path + "->" + p);
            }
        }

        return result;
    }
};