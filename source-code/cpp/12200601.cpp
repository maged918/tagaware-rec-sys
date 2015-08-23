//Language: GNU C++


//***组合数取模***
//***考虑在坏点的情况
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define maxn 1000000
typedef long long ll;
struct point
{
    long long x,y;
}points[5000];

int cmp(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    else
        return a.x<b.x;
}
ll fac[maxn];
ll f[maxn];
int n,m,k;

ll qpow(ll a,ll b)
{
    ll ans=1;
    a%=MOD;
    for(ll i=b;i;i>>=1,a=a*a%MOD)
    {
        if(i&1)
            ans=ans*a%MOD;
    }
    return ans;
}
ll C(ll n,ll m)
{
    if(m>n||m<0) return 0;
    ll s1=fac[n],s2=fac[n-m]*fac[m]%MOD;
    return s1*qpow(s2,MOD-2)%MOD;
}

int main()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*i%MOD;
    scanf ("%d %d %d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf ("%I64d %I64d",&points[i].x,&points[i].y);
        points[i].x-=1;
        points[i].y-=1;
    }
    points[++k].x=n-1;
    points[k].y=m-1;
    sort(points+1,points+1+k,cmp);
    for(int i=1;i<=k;i++)
    {
        f[i]=C(points[i].x+points[i].y,points[i].x);
        for(int j=1;j<i;j++)
        {
            if(points[j].y<=points[i].y)
            {
                f[i]+=(MOD-f[j]*C(points[i].x-points[j].x+points[i].y-points[j].y,points[i].x-points[j].x)%MOD);
                f[i]%=MOD;
            }
        }
    }
    printf("%I64d\n",f[k]%MOD);
    return 0;
}
