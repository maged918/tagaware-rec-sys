//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

inline int read()
{
    int x = 0, f = 1, t = getchar();
    while(t < 48 || t > 57) t == 45 ? f = -1 : 0, t = getchar();
    while(t > 47 && t < 58) x = (x << 1) + (x << 3) + t - 48, t = getchar();
    return x * f;
}

const int maxn = 2005;
const int maxl = 200000;
const int MOD = 1e9 + 7;

struct Black
{
    int x, y;
    bool operator < (const Black &r) const {
        return x < r.x || (x == r.x && y < r.y);
    }
};
int h, w, n;
Black data[maxn];
LL fac[maxl + 5], inv[maxl + 5];
LL f[maxn];

LL power_mod(LL x, int y)
{
    LL res = 1;
    for(; y; y >>= 1, x = x * x % MOD)
        if(y & 1) res = res * x % MOD;
    return res;
}
void init_fact()
{
    fac[0] = 1; for(int i = 1; i <= maxl; ++i) fac[i] = fac[i - 1] * i % MOD;
    inv[maxl] = power_mod(fac[maxl], MOD - 2); for(int i = maxl; i >= 1; --i) inv[i - 1] = inv[i] * i % MOD;
}
LL C(int x, int y)
{
    if(x < y) return 0;
    return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}
LL calc(int x, int y)
{
    if(x < 1 || y < 1) return 0;
    return C(x + y - 2, x - 1);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    init_fact();
    
    h = read(), w = read(), n = read();
    for(int i = 0; i < n; ++i) data[i] = (Black){read(), read()};
    data[n] = (Black){h, w};
    sort(data, data + n + 1);
    
    for(int i = 0; i <= n; ++i)
    {
        LL res = 0;
        for(int j = 0; j < i; ++j)
            res = (res + f[j] * calc(data[i].x - data[j].x + 1, data[i].y - data[j].y + 1)) % MOD;
        f[i] = (calc(data[i].x, data[i].y) - res + MOD) % MOD;
    }
    int ans = f[n];
    printf("%d\n", ans);
    
    #ifndef ONLINE_JUDGE
    fclose(stdin), fclose(stdout);
    #endif
    return 0;
}
