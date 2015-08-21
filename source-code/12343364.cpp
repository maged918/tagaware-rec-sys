//Language: GNU C++11


#include <bits/stdc++.h>
#define pb push_back
#define se second
#define fs first
#define sq(x) (x) * (x)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int maxv = 2045;
const ll mod = 1e9 + 7;
const int maxn = 1e6 + 40;
ll fac[maxn], inv[maxn];
ll qpow(ll a, ll p){
    ll ans = 1;
    ll xx = a;
    while(p > 0){
        if(p & 1) ans = (xx * ans) % mod;
        xx = (xx * xx) % mod;
        p >>= 1;
    }
    return ans;
}
void init(){
    fac[0] = 1;
    inv[0] = 1;
    for(ll i = 1; i < maxn; ++i){
        fac[i] = (fac[i - 1] * i) % mod;
        inv[i] = inv[i - 1] * qpow(i, mod - 2) % mod;
    }
}
int h, w, n;
P a[maxv];
ll dp[maxv];
ll culC(ll a,ll b){
    return fac[a] * inv[a - b] % mod * inv[b] % mod;
}
ll path(ll sx,ll sy,ll tx,ll ty){
    return culC(ty - sy + tx - sx, tx - sx);
}
void solve(){
    for(int i = 0; i <= n; ++i){
        ll ans = 0;
        for(int j = 0; j < i; ++j){
            if(a[j].se <= a[i].se)
                ans += path(a[j].fs, a[j].se, a[i].fs, a[i].se) * dp[j] % mod, ans %= mod;
        }
        dp[i] = (path(1, 1, a[i].fs, a[i].se) - ans) % mod + mod, dp[i] %= mod;
    }
}
int main(){
    ios::sync_with_stdio(false);
    init();
    cin >> h >> w >> n;
    for(int i = 0; i < n; ++i){
        int c, r;
        cin >> r >> c;
        a[i].fs = r;
        a[i].se = c;
    }
    sort(a, a + n);
    a[n] = P(h, w);
    solve();
    cout<< dp[n] << endl;
    return 0;
}