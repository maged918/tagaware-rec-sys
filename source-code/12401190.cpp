//Language: GNU C++11


# include <cstdio>
# include <cmath>
# include <cstring>
# include <string>
# include <vector>
# include <queue>
# include <map>
# include <algorithm>
# include <iostream>

using namespace std;

const int MAX_N = 204;
const int MAX_K = 37;
const int INF = 100000;

int n, k;
long long dp[MAX_N][MAX_N];
int a[MAX_N];
int ch[MAX_N][MAX_N];

bool ok (int x)
{
    int i;
    for (i = 1; i <= 2 * n; i ++)
    {
        if (ch[x][i] == 1 && !(a[x] == a[i]))
            return false;
        if (ch[x][i] == 2 && !(a[x] < a[i]))
            return false;   
        if (ch[x][i] == 3 && !(a[x] > a[i]))
            return false;   
        if (ch[x][i] == 4 && !(a[x] <= a[i]))
            return false;   
        if (ch[x][i] == 5 && !(a[x] >= a[i]))
            return false;   
    }
    return true;                    
}

long long go (int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    int curr = (l + ((2 * n) - r + 1)) >> 1;

    if (r - l + 1 == 2)
    {
        a[l] = a[r] = curr;
        if (ok (l) && ok (r))
            dp[l][r] = 1;
        else
            dp[l][r] = 0;
        a[l] = a[r] = INF;
        return dp[l][r];
    }
    
    dp[l][r] = 0;
    
    a[l] = a[l + 1] = curr;
    if (ok (l) && ok (l + 1))
        dp[l][r] += go (l + 2, r);
    a[l] = a[l + 1] = INF;
    
    
    a[r - 1] = a[r] = curr;
    if (ok (r - 1) && ok (r))
        dp[l][r] += go (l, r - 2);
    a[r - 1] = a[r] = INF;
    
    
    a[l] = a[r] = curr;
    if (ok (l) && ok (r))
        dp[l][r] += go (l + 1, r - 1);
    a[l] = a[r] = INF;
    
    return dp[l][r];
}

int main ()
{
    int i, p, q;
    char type[204];
    memset (dp, -1, sizeof (dp));
    scanf ("%d%d", &n, &k);
    for (i = 1; i <= 2 * n; i ++)
        a[i] = INF;
    for (i = 1; i <= k; i ++)
    {
        scanf ("%d%s%d", &p, type, &q);
        if (strlen (type) == 1)
        {
            if (type[0] == '=')
                ch[p][q] = ch[q][p] = 1;
            if (type[0] == '<')
                ch[p][q] = 2, ch[q][p] = 3;
            if (type[0] == '>')
                ch[p][q] = 3, ch[q][p] = 2;
        }
        else
        {
            if (type[0] == '<')
                ch[p][q] = 4, ch[q][p] = 5;
            if (type[0] == '>')
                ch[p][q] = 5, ch[q][p] = 4;
        }
    }
    
    printf ("%I64d\n", go (1, 2 * n));
    return 0;
}
