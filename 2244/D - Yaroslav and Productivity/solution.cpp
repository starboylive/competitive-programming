#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n,m; scanf("%d %d", &n, &m);
        vector<long long> a(n+1);
        for(int i=1;i<=n;i++) scanf("%lld", &a[i]);
        vector<char> isBp(n+1,0);
        for(int i=0;i<m;i++){ int b; scanf("%d", &b); isBp[b]=1; }
        long long bestPos=0, bestNeg=LLONG_MIN/2;
        for(int i=n;i>=1;i--){
            if(isBp[i]){
                long long prevmax = max(bestPos, bestNeg);
                bestPos = prevmax + a[i];
                bestNeg = prevmax - a[i];
            } else {
                bestPos = bestPos + a[i];
                bestNeg = bestNeg - a[i];
            }
        }
        printf("%lld
", max(bestPos,bestNeg));
    }
}