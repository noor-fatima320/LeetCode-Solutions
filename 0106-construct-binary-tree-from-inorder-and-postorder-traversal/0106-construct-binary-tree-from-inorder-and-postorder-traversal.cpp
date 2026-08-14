class Solution {
public:

    unordered_map<int, int> inorderIndex;
    int postorderIndex;

    TreeNode* buildTreeHelper(vector<int>& postorder,
                              int left,
                              int right) {

        // Agar range empty hai
        if (left > right) {
            return nullptr;
        }

        // Postorder ka last/current element root hoga
        int rootValue = postorder[postorderIndex--];

        TreeNode* root = new TreeNode(rootValue);

        // Pehle RIGHT subtree build karo
        root->right = buildTreeHelper(
            postorder,
            inorderIndex[rootValue] + 1,
            right
        );

        // Phir LEFT subtree build karo
        root->left = buildTreeHelper(
            postorder,
            left,
            inorderIndex[rootValue] - 1
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder,
                        vector<int>& postorder) {

        // Inorder ke indexes store karo
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        // Postorder ke last element se start karenge
        postorderIndex = postorder.size() - 1;

        return buildTreeHelper(
            postorder,
            0,
            inorder.size() - 1
        );
    }
};