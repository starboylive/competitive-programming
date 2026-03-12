// 3600. Maximize Spanning Tree Stability with Upgrades
#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n){
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return false;

        if(rankv[a] < rankv[b]) swap(a,b);

        parent[b]=a;

        if(rankv[a]==rankv[b])
            rankv[a]++;

        return true;
    }
};

class Solution {
public:

    bool can(int n, vector<vector<int>>& edges, int k, long long X){

        DSU dsu(n);

        int used = 0;
        int upgrades = 0;

        vector<vector<int>> strong;
        vector<vector<int>> weak;

        for(auto &e: edges){

            int u=e[0], v=e[1];
            long long s=e[2];
            int must=e[3];

            if(must){

                if(s < X)
                    return false;

                if(!dsu.unite(u,v))
                    return false;

                used++;
            }
            else{

                if(s >= X)
                    strong.push_back(e);

                else if(s*2 >= X)
                    weak.push_back(e);
            }
        }

        // use strong edges first
        for(auto &e: strong){

            if(dsu.unite(e[0], e[1])){
                used++;

                if(used == n-1)
                    return true;
            }
        }

        for(auto &e: weak){

            if(dsu.unite(e[0], e[1])){

                upgrades++;
                used++;

                if(upgrades > k)
                    return false;

                if(used == n-1)
                    return true;
            }
        }

        return used == n-1;
    }


    int maxStability(int n, vector<vector<int>>& edges, int k) {

        // if must edges exceed tree capacity
        int mustCount = 0;

        for(auto &e: edges)
            if(e[3] == 1)
                mustCount++;

        if(mustCount > n-1)
            return -1;

        long long lo = 0, hi = 1e9;
        int ans = -1;

        while(lo <= hi){

            long long mid = (lo + hi) / 2;

            if(can(n, edges, k, mid)){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        return ans;
    }
};