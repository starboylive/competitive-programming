class Solution {
public:
    static const int MOD = 1000000007;

    struct Node {
        long long val;
        int len;
        int sum;
    };

    vector<Node> seg;
    vector<long long> pw;
    string s;

    Node merge(Node a, Node b) {
        return {
            (a.val * pw[b.len] + b.val) % MOD,
            a.len + b.len,
            a.sum + b.sum
        };
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            int d = s[l] - '0';
            if (d == 0)
                seg[idx] = {0, 0, 0};
            else
                seg[idx] = {d, 1, d};
            return;
        }

        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[idx];

        int mid = (l + r) / 2;

        if (qr <= mid)
            return query(idx * 2, l, mid, ql, qr);

        if (ql > mid)
            return query(idx * 2 + 1, mid + 1, r, ql, qr);

        return merge(
            query(idx * 2, l, mid, ql, qr),
            query(idx * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    vector<int> sumAndMultiply(string str, vector<vector<int>>& queries) {
        s = str;
        int n = s.size();

        pw.assign(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pw[i] = (pw[i - 1] * 10) % MOD;

        seg.assign(4 * n + 5, {0, 0, 0});
        build(1, 0, n - 1);

        vector<int> ans;
        for (auto &q : queries) {
            Node cur = query(1, 0, n - 1, q[0], q[1]);
            ans.push_back((cur.val * 1LL * cur.sum) % MOD);
        }

        return ans;
    }
};