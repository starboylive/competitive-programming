#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
 
    while (T--) {
        int n, c;
        cin >> n >> c;
 
        vector<int> a(n), b(n);
        long long sumA = 0, sumB = 0;
 
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sumA += a[i];
        }
 
        bool directPossible = true;
        long long directCost = 0;
 
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sumB += b[i];
            if (a[i] < b[i])
                directPossible = false;
            else
                directCost += (a[i] - b[i]);
        }
 
        long long ans = -1;
 
        if (directPossible)
            ans = directCost;
 
        vector<int> sa = a, sb = b;
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
 
        bool reorderPossible = true;
        for (int i = 0; i < n; i++) {
            if (sa[i] < sb[i]) {
                reorderPossible = false;
                break;
            }
        }
 
        if (reorderPossible) {
            long long reorderCost = (sumA - sumB) + c;
            if (ans == -1 || reorderCost < ans)
                ans = reorderCost;
        }
 
        cout << ans << "
";
    }
 
    return 0;
}