class Solution {
public:

    void findPaths(TreeNode* root, int targetSum,
                   vector<int>& path,
                   vector<vector<int>>& result) {

        // Agar node null hai
        if (root == nullptr) {
            return;
        }

        // Current node ko path mein add karo
        path.push_back(root->val);

        // Check karo kya ye leaf node hai
        // aur path ka sum targetSum ke equal hai
        if (root->left == nullptr &&
            root->right == nullptr &&
            root->val == targetSum) {

            result.push_back(path);
        }

        // Left subtree
        findPaths(root->left,
                  targetSum - root->val,
                  path,
                  result);

        // Right subtree
        findPaths(root->right,
                  targetSum - root->val,
                  path,
                  result);

        // Backtracking
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> result;
        vector<int> path;

        findPaths(root, targetSum, path, result);

        return result;
    }
};