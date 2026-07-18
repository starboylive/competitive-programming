#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        vector<int> v(3);
        cin >> v[0] >> v[1] >> v[2];

        sort(v.begin(), v.end());

        if (v[1] != v[2]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << v[0] << " " << v[0] << " " << v[2] << "\n";
        }
    }

    return 0;
}