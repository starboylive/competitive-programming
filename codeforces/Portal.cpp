// D. Portal 

#include <iostream>
#include <vector> 
#include <algorithm> 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> p(n);
        for (int &v : p) cin >> v;

        if (x == 0 || y == n) {
            sort(p.begin(), p.end());
        } else {
            vector<int> bag;

            for (int i = 0; i < x; i++) bag.push_back(p[i]);
            for (int i = y; i < n; i++) bag.push_back(p[i]);

            sort(bag.begin(), bag.end());

            int k = 0;

            for (int i = 0; i < x; i++) p[i] = bag[k++];
            for (int i = y; i < n; i++) p[i] = bag[k++];
        }

        for (int v : p) cout << v << " ";
        cout << "\n";
    }
}