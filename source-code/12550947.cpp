//Language: GNU C++


#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

int n, m, f[2][520][520];
char a[520][520];

void in()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
}

void Solve_()
{
    int c = 0;
    for(int i = (m + n)/2; i >= 0; i--)
    {
        c = 1 - c;
        for(int j = 1; j <= m; j++)
            for(int t = j; t <= m; t++)
            {
                int xj = i - j + 1;
                int xt = n + m - i - t + 1;
                if(xj < 1 || xt < 1 || xt > n || xj > n || xt < xj) continue;
                if(a[xj][j] == a[xt][t])
                {
                    if((xj == xt && t == j + 1) || (xj == xt && j == t) || (j == t && xj + 1 == xt)) f[c][j][t] = 1;
                    else
                        f[c][j][t] = (((f[1-c][j+1][t] + f[1-c][j][t-1])%mod + f[1-c][j+1][t-1])%mod + f[1-c][j][t])%mod;
                }
                    else f[c][j][t] = 0;
            }
    }
    cout << f[1-c][1][m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("E.INP","r",stdin);
    //freopen("E.OUT","w",stdout);
    in();
    Solve_();
    return 0;
}
