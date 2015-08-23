//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int mod = 1000000000 + 7;
#define MAX 510


int n,m;
char mat[MAX][MAX];
int dp[2][MAX][MAX];

int main(void)
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s",mat[i]);
    }

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            for (int k = 0; k < n; ++k)
            {
                dp[i%2][j][k] = 0;
                int l = n + m - (i + j + k) - 2;
                if (l < 0 || l >= m)
                    continue;
                if (i > k || j > l)
                    continue;
                
                if (mat[i][j] != mat[k][l])
                {
                    continue;
                }
                if (abs(i - k) + abs(j - l) <= 1)
                {
                    dp[i%2][j][k] = 1;
                    continue;
                }
                
                if (i + 1 < n && k - 1 >= 0)
                {
                    dp[i%2][j][k] += dp[(i + 1)%2][j][k - 1];
                    dp[i%2][j][k] %= mod;
                }
                if (i + 1 < n)
                {
                    dp[i%2][j][k] += dp[(i + 1)%2][j][k];
                    dp[i%2][j][k] %= mod;
                }
                if (j + 1 < m && k - 1 >= 0)
                {
                    dp[i%2][j][k] += dp[i%2][j + 1][k - 1];
                    dp[i%2][j][k] %= mod;
                }
                if (j + 1 < m)
                {
                    dp[i%2][j][k] += dp[i%2][j + 1][k];
                    dp[i%2][j][k] %= mod;
                }
                dp[i%2][j][k] %= mod;
            }
        }
    }

    printf("%d\n",dp[0][0][n-1]);
    return 0;
}