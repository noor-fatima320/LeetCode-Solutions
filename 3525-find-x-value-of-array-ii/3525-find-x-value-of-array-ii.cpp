class Solution {
public:
    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++) cnt[i] = 0;
        }
    };

    int K;
    vector<Node> seg;

    Node mergeNode(const Node& L, const Node& R) {
        Node res;

        // Product of the whole segment
        res.prod = (L.prod * R.prod) % K;

        // Prefixes completely inside L
        for (int r = 0; r < K; r++) {
            res.cnt[r] += L.cnt[r];
        }

        // Prefixes that take all of L and then some prefix of R
        for (int r = 0; r < K; r++) {
            int nr = (L.prod * r) % K;
            res.cnt[nr] += R.cnt[r];
        }

        return res;
    }

    void build(int idx, int l, int r, vector<int>& nums) {
        if (l == r) {
            int v = nums[l] % K;
            seg[idx].prod = v;
            seg[idx].cnt[v] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid, nums);
        build(idx * 2 + 1, mid + 1, r, nums);

        seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, int value) {
        if (l == r) {
            for (int i = 0; i < K; i++)
                seg[idx].cnt[i] = 0;

            int v = value % K;
            seg[idx].prod = v;
            seg[idx].cnt[v] = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, value);
        else
            update(idx * 2 + 1, mid + 1, r, pos, value);

        seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(idx * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(idx * 2 + 1, mid + 1, r, ql, qr);

        Node L = query(idx * 2, l, mid, ql, qr);
        Node R = query(idx * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(L, R);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        K = k;

        int n = nums.size();
        seg.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            /*
             * After removing nums[0 .. start-1],
             * we are working with nums[start .. n-1].
             *
             * We can remove any suffix, so every possible
             * non-empty remaining prefix of this range is one
             * possible operation.
             *
             * The empty suffix means keeping the complete range.
             */
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};