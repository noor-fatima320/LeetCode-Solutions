class Solution {
public:
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> trees;

        // Empty subtree
        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        // Har value ko root bana kar try karo
        for (int root = start; root <= end; root++) {

            vector<TreeNode*> leftTrees = generate(start, root - 1);
            vector<TreeNode*> rightTrees = generate(root + 1, end);

            // Har left tree ko har right tree ke saath combine karo
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {

                    TreeNode* node = new TreeNode(root);

                    node->left = left;
                    node->right = right;

                    trees.push_back(node);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
