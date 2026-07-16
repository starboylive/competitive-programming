#include <iostream>
using namespace std;
 
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
 
        ll r = n % 12;
 
        if (r <= 9) {
            cout << r << " " << n - r << '
';
        }
        else if (r == 11) {
            cout << 11 << " " << n - 11 << '
';
        }
        else { // r == 10
            if (n == 10)
                cout << -1 << '
';
            else
                cout << 22 << " " << n - 22 << '
';
        }
    }
 
    return 0;
}