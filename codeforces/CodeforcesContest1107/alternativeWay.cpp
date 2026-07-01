#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (auto &x : a) cin >> x;
        for (auto &x : b) cin >> x;

        ll pos = 0, neg = 0, prev = 0;
        bool ok = true;

        for (int i = 1; i <= n; i++) {
            ll cur = (i & 1) ? (b[i - 1] - a[i - 1])
                             : (a[i - 1] - b[i - 1]);

            if (cur > prev) {
                ll d = cur - prev;
                if (i & 1) {
                    pos += d;
                } else {
                    if (neg < d) {
                        ok = false;
                        break;
                    }
                    neg -= d;
                }
            } else if (cur < prev) {
                ll d = prev - cur;
                if (i % 2 == 0) {
                    neg += d;
                } else {
                    if (pos < d) {
                        ok = false;
                        break;
                    }
                    pos -= d;
                }
            }

            prev = cur;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}