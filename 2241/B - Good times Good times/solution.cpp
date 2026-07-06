#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
 
    while (T--) {
        long long w;
        cin >> w;
 
        int d = to_string(w).size();
        long long s = 1;
        for (int i = 0; i < d; i++) s *= 10;
 
        cout << s + 1 << "
";
    }
 
    return 0;
}