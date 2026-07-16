#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        char buf[105];
        scanf("%s", buf);
        string s(buf);
        
        if(n < 2*k){
            printf("-1\n");
            continue;
        }
        
        int flips = 0;
        // positions 1..k (0-indexed 0..k-1) must be 'R'
        for(int i = 0; i < k; i++){
            if(s[i] != 'R') flips++;
        }
        // positions n-k+1..n (0-indexed n-k..n-1) must be 'L'
        for(int i = n-k; i < n; i++){
            if(s[i] != 'L') flips++;
        }
        
        printf("%d\n", flips);
    }
    return 0;
}