#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n,q; scanf("%d %d", &n, &q);
        char buf[200005];
        scanf("%s", buf+1);
        vector<int> prefEq(n+1,0);
        for(int i=2;i<=n;i++){
            prefEq[i] = prefEq[i-1] + (buf[i]==buf[i-1] ? 1 : 0);
        }
        while(q--){
            int l,r,k;
            scanf("%d %d %d", &l, &r, &k);
            int T = prefEq[r]-prefEq[l];
            int minOps = (T+1)/2;
            puts(minOps<=k ? "YES":"NO");
        }
    }
}