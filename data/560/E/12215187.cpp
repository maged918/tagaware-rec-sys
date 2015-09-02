//Language: GNU C++


#pragma comment(linker, "/STACK:102400000,102400000")
#include <map>
#include <string>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define sqr(x) ((x)*(x))
#define PII pair<int, int>
#define mod 1000000007
#define pi acos(-1.0)
#define prime 1999
#define inf 1000000000
#define LL long long
#define eps 1e-8
//#define G 9.80665 //重力加速度






#define N 200005
struct point{
    LL x, y;
};
point p[2100];
bool cmp(point a, point b)
{
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
LL dp[N];
LL fac[N], inv[N];
LL pow_mod(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
void init()
{
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = (fac[i - 1] * i) % mod;
    inv[N - 1] = pow_mod(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
}
LL C(LL n, LL m)
{
    LL res = 1;
    while (n && m)
    {
        LL a = n % mod, b = m % mod;
        if (a < b) return 0;
        res = (res * (fac[a] * ((inv[b] * inv[a - b]) % mod)) % mod) % mod;
        n /= mod;
        m /= mod;
    }
    return res;
}
int main()
{
    init();
    LL h, w, n;
    scanf("%I64d%I64d%I64d", &h, &w, &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d%I64d", &p[i].x, &p[i].y);
    p[n].x = h; p[n].y = w; n++;
    sort(p, p + n, cmp);
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < n; i++)
    {
        dp[i] = C(p[i].x + p[i].y - 2, p[i].x - 1);
        LL sum = 0;
        for (int j = 0; j < i; j++)
        {
            if (p[j].y <= p[i].y)
            {
                LL k = C(p[i].x - p[j].x + p[i].y - p[j].y, p[i].x - p[j].x);
                sum = (sum + dp[j] * k) % mod;
            }
        }
        dp[i] = ((dp[i] - sum) % mod + mod) % mod;
    }
    printf("%I64d\n", dp[n - 1]);
    return 0;
}
