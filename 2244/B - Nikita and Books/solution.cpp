#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        vector<long long> a(n);
        for(auto &x: a) scanf("%lld", &x);
        long long origPrefix=0, cum=0, prev=0;
        bool ok=true;
        for(int i=0;i<n;i++){
            origPrefix += a[i];
            if(i<n-1){
                long long cand = prev+1;
                cum += cand;
                if(cum > origPrefix) ok=false;
                prev = cand;
            } else {
                long long x = origPrefix - cum;
                if(x <= prev) ok=false;
            }
            if(!ok) break;
        }
        puts(ok? "YES":"NO");
    }
}