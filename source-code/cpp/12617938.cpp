//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2010, MOD = 1000000007, maxh = 2e5 + 10;
pair<int,int> a[maxn];
int h, w, n;
int f[maxn], r[maxh], inv[maxh], invr[maxh];

int get(int i, int j)
{
    return (ll)r[i+j] * invr[i] % MOD * invr[j] % MOD;
}

int main()
{
    invr[0] = inv[1] = invr[1] = r[0] = 1;
    for(int i = 1; i < maxh; i++) {
        r[i] = (ll)r[i-1] * i % MOD;
    }
    for(int i = 2; i < maxh; i++) {
        inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
        invr[i] = (ll)invr[i-1] * inv[i] % MOD;
    }

    scanf("%d%d%d", &h, &w, &n);

    for(int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].first, &a[i].second);

    sort(a+1, a+1+n);
    if(a[n] == make_pair(h,w)) {
        printf("0\n");
        return 0;
    }
    a[++n] = {h,w};

    f[0] = 1;

    for(int i = 1; i <= n; i++) {
        f[i] = get(a[i].first-1, a[i].second-1);
        //printf("%d\n", f[i]);
        for(int j = 1; j < i; j++)
            if(a[i].second >= a[j].second && a[i].first >= a[j].first)
                f[i] = (f[i] - (ll)f[j]*get(a[i].first-a[j].first, a[i].second-a[j].second)) % MOD;
    }

    printf("%d\n", (f[n] + MOD) % MOD);

    return 0;
}
