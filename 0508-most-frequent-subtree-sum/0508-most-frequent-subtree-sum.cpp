class Solution {
public:
    unordered_map<int, int> freq;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        int sum = root->val + leftSum + rightSum;

        freq[sum]++;

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        freq.clear();
        dfs(root);

        int maxFreq = 0;
        vector<int> result;

        for (auto &it : freq) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
            }
        }

        for (auto &it : freq) {
            if (it.second == maxFreq) {
                result.push_back(it.first);
            }
        }

        return result;
    }
};