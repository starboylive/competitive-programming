#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
 
    while (T--) {
        int n;
        cin >> n;
 
        vector<long long> a(n);
        for (auto &x : a) cin >> x;
 
        sort(a.begin(), a.end(), greater<long long>());
 
        bool ok = true;
        for (int i = 2; i < n; i++) {
            if (a[i - 2] % a[i - 1] != a[i]) {
                ok = false;
                break;
            }
        }
 
        if (ok)
            cout << a[0] << " " << a[1] << '
';
        else
            cout << -1 << '
';
    }
 
    return 0;
}