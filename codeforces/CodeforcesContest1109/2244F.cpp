#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> p(n+1,0);
        for(int i=2;i<=n;i++) scanf("%d",&p[i]);
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);

        vector<vector<int>> children(n+1);
        for(int i=2;i<=n;i++) children[p[i]].push_back(i);

        // BFS order from root to get a valid topological order
        vector<int> order;
        order.reserve(n);
        {
            vector<int> stackv;
            stackv.push_back(1);
            size_t idx=0;
            while(idx < stackv.size()){
                int u = stackv[idx++];
                order.push_back(u);
                for(int c: children[u]) stackv.push_back(c);
            }
        }

        vector<char> valid(n+1,1);
        vector<int> L(n+1,0), R(n+1,0);

        // process in reverse BFS order -> children before parents
        for(int idx=(int)order.size()-1; idx>=0; idx--){
            int i = order[idx];
            if(a[i] > 0){
                L[i]=R[i]=a[i];
                valid[i]=1;
                continue;
            }
            auto &ch = children[i];
            int m = (int)ch.size();
            bool ok = true;

            for(int c: ch){
                if(!valid[c]){ ok=false; break; }
            }

            if(ok && m>0){
                vector<pair<int,int>> arr(m);
                for(int k=0;k<m;k++) arr[k] = {L[ch[k]], R[ch[k]]};

                vector<pair<int,int>> sorted_arr = arr;
                sort(sorted_arr.begin(), sorted_arr.end());

                for(int k=0;k+1<m;k++){
                    if(sorted_arr[k].second + 1 != sorted_arr[k+1].first){
                        ok=false; break;
                    }
                }

                if(ok){
                    int minl = sorted_arr[0].first;
                    int j=-1;
                    for(int k=0;k<m;k++){
                        if(arr[k].first == minl){ j=k; break; }
                    }
                    for(int tt=0; tt<m; tt++){
                        if(arr[(j+tt)%m] != sorted_arr[tt]){
                            ok=false; break;
                        }
                    }
                }

                if(ok){
                    L[i]=sorted_arr[0].first;
                    R[i]=sorted_arr[m-1].second;
                }
            }

            valid[i] = ok ? 1 : 0;
        }

        puts(valid[1] ? "YES" : "NO");
    }
    return 0;
}