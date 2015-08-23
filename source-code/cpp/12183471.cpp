//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int mod = 1000000007;

typedef long long ll;
ll fac[2000001];
ll PowMod(ll a, ll b, ll mod)
{
    ll ret = 1LL;
    while(b)
    {
        if(b&1) ret = (ret*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ret;
}
void cfac()
{
    fac[0] = 1;
    for(ll i = 1; i <= 200000; i++) fac[i] = i * fac[i-1] % mod;
}
ll Lucas(ll n,ll m,ll p = mod){
    ll ret=1;
    if(n==0)return 1;
    while(n&&m){
        ll a=n%p,b=m%p;
        if(a<b) return 0;
        ret=(ret*fac[a]*PowMod(fac[b]*fac[a-b]%p,p-2,p))%p;
        n/=p;
        m/=p;
    }
    return ret;
}

ll pre[2002][2002];
ll dp[2002];
struct data
{
    ll x, y;
    bool operator<(const data& b) const
    {
        return y == b.y ? x < b.x : y < b.y;
    }
} Q[2002];

int main()
{
    ios::sync_with_stdio(0);
    cfac();
    int h, w, n, l;
    cin>>h>>w>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>Q[i].x>>Q[i].y;
    }
    sort(Q, Q+n);
    ll ans = 0LL;
    for(int i = 0; i < n; i++)
    {
        dp[i] += Lucas(Q[i].x - 1 + Q[i].y - 1, Q[i].x-1);
        dp[i] %= mod;
        if(dp[i] < 0) dp[i] += mod;
        for(int j = i + 1; j < n; j++)
        {
            if(Q[j].x < Q[i].x) continue;
            ll temp =  Lucas(Q[j].x + Q[j].y - Q[i].y - Q[i].x,
                              Q[j].x -  Q[i].x);
            pre[i][j] = temp;
            dp[j] -= temp * dp[i];
            dp[j] %= mod;
            if(dp[j] < 0) dp[j] += mod;
        }
        //cout<<dp[i]<<endl;
    }
    ll temp = Lucas(h+w-2,h-1);
    for(int i = n-1; i >= 0; i--)
    {
        temp -= dp[i] *Lucas(h + w - Q[i].x - Q[i].y, h - Q[i].x) ;
        temp %= mod;
        if(temp < 0) temp += mod;
        
        temp %= mod;
        if(temp < 0) temp += mod;
    }
    cout<<temp<<endl;
    return 0;
}