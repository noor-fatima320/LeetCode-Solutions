class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Dono empty hain
        if (p == nullptr && q == nullptr)
            return true;

        // Sirf ek empty hai
        if (p == nullptr || q == nullptr)
            return false;

        // Values different hain
        if (p->val != q->val)
            return false;

        // Left aur right dono same hone chahiye
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};