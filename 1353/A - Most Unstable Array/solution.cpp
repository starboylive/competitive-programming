#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        long long n, m;
        cin >> n >> m;
 
        cout << 1LL * min(2LL, n - 1) * m << '
';
    }
 
    return 0;
}