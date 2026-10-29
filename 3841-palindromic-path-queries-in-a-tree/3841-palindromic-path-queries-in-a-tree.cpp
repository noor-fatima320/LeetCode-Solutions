
class Solution {
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, subtree;
    vector<int> seg;
    int timer;

    int dfs1(int u, int p) {
        parent[u] = p;
        subtree[u] = 1;
        int maxSub = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int sz = dfs1(v, u);
            subtree[u] += sz;

            if (sz > maxSub) {
                maxSub = sz;
                heavy[u] = v;
            }
        }
        return subtree[u];
    }

    void dfs2(int u, int h, const string& s,
              vector<int>& base) {
        head[u] = h;
        pos[u] = timer++;
        base[pos[u]] = 1 << (s[u] - 'a');

        if (heavy[u] != -1)
            dfs2(heavy[u], h, s, base);

        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u])
                dfs2(v, v, s, base);
        }
    }

    void build(int node, int l, int r,
               const vector<int>& a) {
        if (l == r) {
            seg[node] = a[l];
            return;
        }

        int m = (l + r) / 2;
        build(node * 2, l, m, a);
        build(node * 2 + 1, m + 1, r, a);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(node * 2, l, m, idx, val);
        else
            update(node * 2 + 1, m + 1, r, idx, val);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[node];

        int m = (l + r) / 2;
        int ans = 0;

        if (ql <= m)
            ans ^= query(node * 2, l, m, ql, qr);

        if (qr > m)
            ans ^= query(node * 2 + 1, m + 1, r, ql, qr);

        return ans;
    }

    int pathXor(int u, int v) {
        int ans = 0;
        int n = (int)pos.size();

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            ans ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        ans ^= query(1, 0, n - 1, pos[u], pos[v]);
        return ans;
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        adj.assign(n, {});

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        subtree.resize(n);
        timer = 0;

        dfs1(0, -1);

        vector<int> base(n);
        dfs2(0, 0, s, base);

        seg.assign(4 * n, 0);
        build(1, 0, n - 1, base);

        vector<bool> ans;

        for (const string& q : queries) {
            string type;
            stringstream ss(q);
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                s[u] = c;
                update(1, 0, n - 1, pos[u],
                       1 << (c - 'a'));
            } else {
                int u, v;
                ss >> u >> v;

                int mask = pathXor(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};
