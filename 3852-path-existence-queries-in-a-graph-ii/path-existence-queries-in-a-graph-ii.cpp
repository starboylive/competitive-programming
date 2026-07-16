class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> ord;
        for(int i = 0; i < n; i++)
            ord.push_back({nums[i], i});

        sort(ord.begin(), ord.end());

        vector<int> pos(n);
        for(int i = 0; i < n; i++)
            pos[ord[i].second] = i;

        // nxt[i] = farthest sorted index reachable in one edge
        vector<int> nxt(n);
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j + 1 < n && ord[j + 1].first - ord[i].first <= maxDiff)
                j++;
            nxt[i] = j;
        }

        // components
        vector<int> comp(n);
        int cid = 0;
        comp[0] = 0;
        for(int i = 1; i < n; i++) {
            if(ord[i].first - ord[i - 1].first > maxDiff)
                cid++;
            comp[i] = cid;
        }

        const int LOG = 20;
        vector<vector<int>> up(LOG, vector<int>(n));

        for(int i = 0; i < n; i++)
            up[0][i] = nxt[i];

        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for(auto &q : queries) {
            int u = pos[q[0]];
            int v = pos[q[1]];

            if(u > v) swap(u, v);

            if(comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }

            if(u == v) {
                ans.push_back(0);
                continue;
            }

            int cur = u;
            int res = 0;

            for(int k = LOG - 1; k >= 0; k--) {
                if(up[k][cur] < v) {
                    cur = up[k][cur];
                    res += (1 << k);
                }
            }

            ans.push_back(res + 1);
        }

        return ans;
    }
};