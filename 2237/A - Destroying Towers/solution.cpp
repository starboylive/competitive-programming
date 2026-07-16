#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        int mn = 1000000000;
        long long ans = 0;
 
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < mn) mn = x;
            ans += mn;
        }
 
        cout << ans << '
';
    }
 
    return 0;
}