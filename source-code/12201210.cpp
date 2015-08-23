//Language: GNU C++


/* 
* @Author: robertking
* @Date:   2015-07-22 21:55:42
* @Last Modified by:   robertking
* @Last Modified time: 2015-07-23 21:36:26
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#define MOD 1000000007LL
#define MAXX 200008
#define MAXP 2008
using namespace std;

struct black_t {
    int r,c;
    bool operator< (const black_t & a) const
    { return (c < a.c || (c==a.c && r < a.r)); }
} black[MAXP];
long long fac[MAXX];
long long inv[MAXX];
long long f[MAXP];

inline long long pow(long long a, long long b)
{
    long long ret=1LL;
    for(; b>0; b>>=1, (a*=a)%=MOD) {
        if(b&1)
            (ret*=a)%=MOD;
    }
    return ret;
}

inline long long C(long long n, long long r)
{
    if(r==n || r==0)
        return 1LL;
    else
        return fac[n]*inv[r]%MOD*inv[n-r]%MOD;
}

int main(int argc, char const *argv[])
{
    fac[0]=fac[1]=1LL;
    for(int i=2; i<=200000; ++i)
        fac[i]=fac[i-1]*i%MOD;
    inv[200000]=pow(fac[200000], MOD-2);
    inv[0]=1;
    for(int i=200000-1; i>=1; --i)
        inv[i]=inv[i+1]*(i+1)%MOD;
    int h,w,n;
    cin>>h>>w>>n;
    for(int i=0; i<n; ++i) {
        cin>>black[i].r>>black[i].c;
    }
    black[n++]=(black_t){h,w};
    sort(black, black+n);
    for(int i=0; i<n; ++i) {
        f[i]=C(black[i].r+black[i].c-2, black[i].c-1);
        for(int j=0; j<i; ++j)
            if(black[j].r <= black[i].r)
                (f[i] -= f[j] * C(black[i].r-black[j].r + black[i].c-black[j].c, black[i].c-black[j].c)) %= MOD;
    }
    cout<<(f[n-1]+MOD) % MOD<<'\n';
    return 0;
}
