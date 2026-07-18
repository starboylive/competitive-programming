#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<ll> a(n+1);
        a[0]=0;
        for(int i=1;i<=n;i++){
            ll x; scanf("%lld",&x); a[i]=x;
        }

        vector<ll> dp(n+1,0);
        vector<vector<int>> bucket(max(n,1)); // bucket[v], v=0..n-1

        for(int j=0;j<=n;j++){
            ll b = (ll)j + a[j];
            if(n>0 && b <= n-1) bucket[(int)b].push_back(j);
        }

        int sz = n+2;
        vector<ll> fen(sz+2, 0);

        auto update = [&](int pos, ll val){
            pos++; // shift to 1-indexed
            for(; pos<=sz+1; pos += pos & (-pos))
                fen[pos] = max(fen[pos], val);
        };
        auto query = [&](ll posL)->ll{
            if(posL < 0) return 0;
            int pos = (int)posL + 1;
            ll res = 0;
            for(; pos>0; pos -= pos&(-pos))
                res = max(res, fen[pos]);
            return res;
        };

        ll ans = 0;
        for(int i=1;i<=n;i++){
            if(i-1 < (int)bucket.size()){
                for(int j: bucket[i-1]) update(j, dp[j]);
            }
            ll L = (ll)i - a[i] - 1;
            ll best = query(L);
            dp[i] = a[i] + best;
            ans = max(ans, dp[i]);
        }

        printf("%lld\n", ans);
    }
    return 0;
}