#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int N;
        scanf("%d", &N);
        vector<int> A(N + 1), B(N + 1);
        for (int i = 1; i <= N; i++)
            scanf("%d", &A[i]);
        for (int i = 1; i <= N; i++)
            scanf("%d", &B[i]);
        vector<pair<int, int>> reds, blues;
        for (int i = 1; i <= N; i++)
        {
            if (B[i] == 0)
                reds.push_back({A[i], i});
            else
                blues.push_back({A[i], i});
        }
        int p = reds.size(), q = blues.size();
        vector<int> minK_A(p + 1, q + 1);
        vector<int> maxK_B(p + 1, 0);
        vector<int> minM_B2(q + 1, p + 1);
        vector<int> maxI_A2(q + 1, 0);
        for (int i = 1; i <= p; i++)
        {
            int rv = reds[i - 1].first, rp = reds[i - 1].second;
            for (int k = 1; k <= q; k++)
            {
                int bv = blues[k - 1].first, bp = blues[k - 1].second;
                if (rv < bv)
                {
                    if (rp < bp)
                    {
                        if (k < minK_A[i])
                            minK_A[i] = k;
                        if (i > maxI_A2[k])
                            maxI_A2[k] = i;
                    }
                    else
                    {
                        if (k > maxK_B[i])
                            maxK_B[i] = k;
                        if (i < minM_B2[k])
                            minM_B2[k] = i;
                    }
                }
            }
        }
        vector<int> Lred(p + 1), Rred(p + 1);
        for (int i = 1; i <= p; i++)
        {
            Lred[i] = maxK_B[i];
            Rred[i] = (minK_A[i] <= q) ? minK_A[i] - 1 : q;
        }
        vector<int> Lblue(q + 1), Rblue(q + 1);
        for (int k = 1; k <= q; k++)
        {
            Lblue[k] = maxI_A2[k];
            Rblue[k] = (minM_B2[k] <= p) ? minM_B2[k] - 1 : p;
        }
        vector<vector<ll>> dp(p + 1, vector<ll>(q + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i <= p; i++)
        {
            for (int j = 0; j <= q; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                ll val = 0;
                if (i > 0 && Lred[i] <= j && j <= Rred[i])
                    val += dp[i - 1][j];
                if (j > 0 && Lblue[j] <= i && i <= Rblue[j])
                    val += dp[i][j - 1];
                dp[i][j] = val % MOD;
            }
        }
        printf("%lld\n", dp[p][q] % MOD);
    }
}