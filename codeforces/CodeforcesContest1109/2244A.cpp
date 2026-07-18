#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n);
        char s[15]; scanf("%s", s);
        int ans=0, cur=0;
        for(int i=0;i<n;i++){
            if(s[i]=='#') cur++;
            else { ans=max(ans,(cur+1)/2); cur=0; }
        }
        ans=max(ans,(cur+1)/2);
        printf("%d\n", ans);
    }
}