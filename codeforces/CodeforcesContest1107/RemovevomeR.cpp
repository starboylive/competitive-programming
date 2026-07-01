#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        int tr = 0;
        for (int i = 1; i < n; i++)
            tr += (s[i] != s[i - 1]);

        if (tr == 1)
            cout << 2 << "\n";
        else
            cout << 1 << "\n";
    }

    return 0;
}