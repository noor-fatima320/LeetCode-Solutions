class Solution {
public:

    unordered_map<int, int> inorderIndex;
    int preorderIndex = 0;

    TreeNode* buildTreeHelper(vector<int>& preorder,
                              int left,
                              int right) {

        // Agar range empty hai
        if (left > right) {
            return nullptr;
        }

        // Preorder ka current element root hoga
        int rootValue = preorder[preorderIndex++];

        TreeNode* root = new TreeNode(rootValue);

        // Root ke left subtree ko build karo
        root->left = buildTreeHelper(
            preorder,
            left,
            inorderIndex[rootValue] - 1
        );

        // Root ke right subtree ko build karo
        root->right = buildTreeHelper(
            preorder,
            inorderIndex[rootValue] + 1,
            right
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Inorder mein har value ka index store karo
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        // Pura tree construct karo
        return buildTreeHelper(
            preorder,
            0,
            inorder.size() - 1
        );
    }
};