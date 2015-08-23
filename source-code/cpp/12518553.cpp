//Language: GNU C++11


/**
 * @brief    : GNU C++11 application
 * @details  : Works stably on GNU C++11 (g++ 4.9.2, flag -std=c++11)
 *
 * @author   : SergeiEgorov
 * @date     : July 10, 2015
 */

#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_cxx;

#define file "file"

constexpr char el = '\n';
constexpr long long inf = (long long) 1e9 + 7;
constexpr long long mod = (1ll << 62);
constexpr int maxn = (int) 1e5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(nullptr));

    #ifdef HOME
        freopen(file".in", "r", stdin);
        freopen(file".out", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    vector< vector<char> > c(n + 1, vector<char>(m + 1, ' '));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> c[i][j];

    if (c[1][1] != c[n][m])
        return cout << 0, 0;

    vector< vector< vector<int> > > dp;
    dp.assign(2, vector< vector<int> >(max(n, m) + 1, vector<int>(max(n, m) + 1, 0)));
    dp[1][1][n] = 1;

    int path = (n + m) / 2, ans = 0;

    for (int i = 2; i <= path; ++i)
        for (int j = max(1, i - m + 1); j <= min(i, n); ++j)
            for (int k = max(1, n - i - 1); k <= n; ++k)
            {
                dp[i & 1][j][k] = 0;

                if (n + m - (i + k) + 1 <= 0)
                    break;

                if (c[j][i - j + 1] == c[k][n + m - (i + k) + 1])
                {
                    int t = i & 1;
                    dp[t][j][k] = dp[t ^ 1][j][k];

                    if (j > 1)
                        dp[t][j][k] = (dp[t][j][k] + dp[t ^ 1][j - 1][k]) % inf;

                    if (k < n)
                        dp[t][j][k] = (dp[t][j][k] + dp[t ^ 1][j][k + 1]) % inf;

                    if (j > 1 && k < n)
                        dp[t][j][k] = (dp[t][j][k] + dp[t ^ 1][j - 1][k + 1]) % inf;
                }
            }

    if ((n + m - 1) & 1)
    {
        for (int i = 1; i <= n; ++i)
            ans = (ans + dp[path & 1][i][i]) % inf;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            ans = (ans + dp[path & 1][i][i]) % inf;
            ans = (ans + (i < n ? dp[path & 1][i][i + 1] : 0)) % inf;
        }
    }

    cout << ans;

    return 0;
}