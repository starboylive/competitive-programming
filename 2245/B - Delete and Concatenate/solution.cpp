#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        ll c;
        scanf("%d %lld", &n, &c);
        vector<ll> a(n);
        ll sumA = 0;
        vector<ll> smalls;
        smalls.reserve(n);
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
            sumA += a[i];
            if(a[i] < c) smalls.push_back(a[i]);
        }
        sort(smalls.begin(), smalls.end());
        int m = (int)smalls.size();
        int k = min(m, n/2);
        ll prefixSum = 0;
        for(int i = 0; i < k; i++) prefixSum += smalls[i];
        ll gain = (ll)k * c - prefixSum;
        ll ans = sumA - c*(ll)n + gain;
        printf("%lld
", ans);
    }
    return 0;
}