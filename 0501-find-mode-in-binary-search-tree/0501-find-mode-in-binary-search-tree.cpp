class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        vector<int> ans;

        int maxFreq = 0;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if (!node) return;

            freq[node->val]++;
            maxFreq = max(maxFreq, freq[node->val]);

            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);

        for (auto it : freq) {
            if (it.second == maxFreq) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};