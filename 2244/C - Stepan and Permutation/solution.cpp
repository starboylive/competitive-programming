#include <bits/stdc++.h>
using namespace std;
 
int par[200005], rnk_[200005];
int find(int x)
{
    while (par[x] != x)
    {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}
 
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (rnk_[a] < rnk_[b])
        swap(a, b);
    par[b] = a;
    if (rnk_[a] == rnk_[b])
        rnk_[a]++;
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        long long x, y;
        scanf("%d %lld %lld", &n, &x, &y);
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            scanf("%d", &p[i]);
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
            rnk_[i] = 0;
        }
        for (int i = 1; i + x <= n; i++)
            unite(i, i + x);
        for (int i = 1; i + y <= n; i++)
            unite(i, i + y);
        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            if (find(i) != find(p[i]))
            {
                ok = false;
                break;
            }
        }
        puts(ok ? "YES" : "NO");
    }
}