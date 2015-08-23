//Language: GNU C++11


#include <cstdio>
#include <cstring>
using namespace std;
#pragma warning (disable : 4996)

#define mod 1000000007
char a[501][501];
int f[2][501][501];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", a[i] + 1);
    f[0][1][1] = a[1][1] == a[n][m];
    for (int i = 3; i <= ((n + m) >> 1) + 1; i++)
    {
        bool o = i & 1;
        memset(f[o], 0, sizeof f[o]);
        for (int j = 1; j < i&&j <= n; j++)
            if (i - j <= m)
                for (int k = 1; k < i&&k <= n; k++)
                    if (i - k <= m)
                    {
                        int x1 = j, y1 = i - j, x2 = n + 1 - k, y2 = m + 1 - i + k;
                        if (a[x1][y1] == a[x2][y2])
                        {
                            if (x1 > 1)
                            {
                                if (x2 < n) f[o][j][k] = (f[o][j][k] + f[!o][x1 - 1][n - x2]) % mod;
                                if (y2 < m) f[o][j][k] = (f[o][j][k] + f[!o][x1 - 1][n - x2 + 1]) % mod;
                            }
                            if (y1 > 1)
                            {
                                if (x2 < n) f[o][j][k] = (f[o][j][k] + f[!o][x1][n - x2]) % mod;
                                if (y2 < m) f[o][j][k] = (f[o][j][k] + f[!o][x1][n - x2 + 1]) % mod;
                            }
                        }
                    }
    }
    int ans = 0;
    if ((n + m) & 1)
    {
        int i = ((n + m) >> 1) + 1;
        bool o = i & 1;
        for (int j = 1; j < i&&j <= n; j++)
            if (i - j <= m)
            {
                int x1 = j, y1 = i - j;
                if (x1 < n)
                    ans = (ans + f[o][j][n - x1]) % mod;
                if (y1 < m)
                    ans = (ans + f[o][j][n - x1 + 1]) % mod;
            }
    }
    else
    {
        int i = ((n + m) >> 1) + 1;
        bool o = i & 1;
        for (int j = 1; j < i&&j <= n; j++)
            if (i - j <= m)
                ans = (ans + f[o][j][n + 1 - j]) % mod;
    }
    printf("%d", ans);
    return 0;
}