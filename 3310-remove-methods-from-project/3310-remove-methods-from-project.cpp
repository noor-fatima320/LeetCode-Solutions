class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[node] = true;
        for (int nei : graph[node]) {
            if (!vis[nei]) {
                dfs(nei, graph, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for (auto &e : invocations) {
            graph[e[0]].push_back(e[1]);
        }

        // Mark suspicious methods
        vector<bool> suspicious(n, false);
        dfs(k, graph, suspicious);

        // Check if any non-suspicious method invokes a suspicious one
        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!suspicious[u] && suspicious[v]) {
                vector<int> all;
                for (int i = 0; i < n; i++)
                    all.push_back(i);
                return all;
            }
        }

        // Return remaining methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i])
                ans.push_back(i);
        }

        return ans;
    }
};