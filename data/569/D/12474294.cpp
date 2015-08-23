//Language: GNU C++11


#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int maxn = 4000 + 5;

ll c[maxn][maxn], d[maxn][maxn], sum[maxn];

int main()
{
    c[0][0] = d[0][0] = sum[0] = 1;
    for(int i = 1; i < maxn; ++i)
    {
        c[i][0] = c[i][i] = d[i][i] = sum[i] = 1;
        for(int j = 1; j < i; ++j)
        {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
            d[i][j] = (d[i - 1][j - 1] + j * d[i - 1][j] % mod) % mod;
            sum[i] = (sum[i] + d[i][j]) % mod;
        }
    }
    int n;
    while(cin >> n)
    {
        ll ans = 0;
        for(int i = 0; i < n; ++i)
        {
            ans = (ans + c[n][i] * sum[i]) % mod;
        }
        cout << ans << endl;
    }
}
