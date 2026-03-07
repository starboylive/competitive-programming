// Cpp 

#include <iostream>
#include <algorithm>
using namespace std;

bool can_form_square(int l1, int b1, int l2, int b2, int l3, int b3) {
  
    if (l1 < b1) swap(l1, b1);
    if (l2 < b2) swap(l2, b2);
    if (l3 < b3) swap(l3, b3);

    
    int L[3] = {l1, l2, l3};
    int B[3] = {b1, b2, b3};

    int p[3] = {0, 1, 2};
    do {
        int a = p[0], b = p[1], c = p[2];

    
        if (B[a] == B[b] && B[b] == B[c]) {
            if (L[a] + L[b] + L[c] == B[a]) return true;
        }

        int square_len = max({B[a], B[b] + B[c]});
        if (L[a] == square_len &&
            L[b] + L[c] == square_len &&
            B[b] == B[c] &&
            B[a] + B[b] == square_len)
            return true;

    } while (next_permutation(p, p + 3));

    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

        if (can_form_square(l1, b1, l2, b2, l3, b3))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
