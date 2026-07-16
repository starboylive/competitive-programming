#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n, k;
        scanf("%lld %lld", &n, &k);
 
        long long remaining = n, total = 0, cost = 1; // cost = 2^level
        while (remaining > 0) {
            long long full = k * cost;       // cost to give every number 1 more bit
            if (full <= remaining) {
                total += k;
                remaining -= full;
                cost *= 2;
            } else {
                long long cnt = remaining / cost; // how many numbers we can upgrade
                total += cnt;
                break;
            }
        }
        printf("%lld
", total);
    }
}