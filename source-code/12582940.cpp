//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define MP make_pair
using namespace std;

typedef long long LL;

const int maxn = 80;

int n, k;

vector<int> G[maxn], req[maxn];

LL d[maxn][maxn];

bool check(int L, int R, int l, int r)
{
    for(int i = 0; i < G[l].size(); i++)
    {
        int v = G[l][i], t = req[l][i];
        if(t == -2)
        {
            if(v < L || v > R || v == r) return false;
        }
        else if(t == -1)
        {
            if(v < L || v > R) return false;
        }
        else if(!t)
        {
            if(v != r) return false;
        }
        else if(t == 1)
        {
            if(v >= L && v <= R && v != r) return false;
        }
        else
        {
            if(v >= L && v <= R) return false;
        }
    }

    for(int i = 0; i < G[r].size(); i++)
    {
        int v = G[r][i], t = req[r][i];
        if(t == -2)
        {
            if(v < L || v > R || v == l) return false;
        }
        else if(t == -1)
        {
            if(v < L || v > R) return false;
        }
        else if(!t)
        {
            if(v != l) return false;
        }
        else if(t == 1)
        {
            if(v >= L && v <= R && v != l) return false;
        }
        else
        {
            if(v >= L && v <= R) return false;
        }
    }

    return true;
}

LL dp(int L, int R)
{
    LL& ans = d[L][R];
    if(ans >= 0) return d[L][R];
    if(L + 1 == R)
    {
        if(check(L, R, L, R)) return 1LL;
        return 0;
    }

    ans = 0;

    if(check(L, R, L, L + 1))
        ans += dp(L + 2, R);
    if(check(L, R, L, R))
        ans += dp(L + 1, R - 1);
    if(check(L, R, R - 1, R))
        ans += dp(L, R - 2);

    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    scanf("%d%d", &n, &k);
    char eq[10];
    while(k--)
    {
        int u, v;
        scanf("%d", &u);
        scanf("%s", eq);
        scanf("%d", &v);

        int t;
        if(strcmp(eq, "<") == 0) t = -2;
        else if(strcmp(eq, "<=") == 0) t = -1;
        else if(strcmp(eq, "=") == 0) t = 0;
        else if(strcmp(eq, ">=") == 0) t = 1;
        else if(strcmp(eq, ">") == 0) t = 2;
        else exit(1234);

        if(u == v)
        {
            if(abs(t) <= 1) continue;
            else { puts("0"); exit(0); }
        }

        req[u].push_back(t); req[v].push_back(-t);
        G[u].push_back(v); G[v].push_back(u);
    }

    memset(d, -1, sizeof(d));

    printf("%I64d\n", dp(1, n * 2));

    return 0;
}
