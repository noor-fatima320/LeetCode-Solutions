class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n);
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int node) {
            int c = s[node] - 'a';
            int prev = last[c];

            if (prev != -1)
                newParent[node] = prev;
            else
                newParent[node] = parent[node];

            last[c] = node;

            for (int child : adj[node]) {
                dfs(child);
            }

            last[c] = prev;
        };

        dfs(0);

        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        function<int(int)> dfsSize = [&](int node) {
            int size = 1;

            for (int child : newAdj[node]) {
                size += dfsSize(child);
            }

            ans[node] = size;
            return size;
        };

        dfsSize(0);

        return ans;
    }
};