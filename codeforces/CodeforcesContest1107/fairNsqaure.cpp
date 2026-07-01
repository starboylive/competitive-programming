#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

bool sq(ll x) {
    ll r = sqrtl(x);
    while ((r + 1) * (r + 1) <= x) r++;
    while (r * r > x) r--;
    return r * r == x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<vector<int>> g(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<int> par(n + 1), ord;
        ord.reserve(n);
        stack<int> st;
        st.push(1);
        par[1] = -1;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            ord.push_back(u);
            for (int v : g[u]) {
                if (v == par[u]) continue;
                par[v] = u;
                st.push(v);
            }
        }

        vector<int> sub(n + 1, 1);
        for (int i = n - 1; i >= 0; i--) {
            int u = ord[i];
            for (int v : g[u]) {
                if (v == par[u]) continue;
                sub[u] += sub[v];
            }
        }

        ll ans = 0;

        for (int u = 1; u <= n; u++) {
            if (!sq(a[u])) continue;

            ll one = 0, two = 0, three = 0;

            auto add = [&](ll s) {
                three += two * s;
                two += one * s;
                one += s;
            };

            add(1);

            for (int v : g[u]) {
                ll s = (v == par[u] ? n - sub[u] : sub[v]);
                add(s);
            }

            ans += three;
        }

        cout << ans << "\n";
    }

    return 0;
}