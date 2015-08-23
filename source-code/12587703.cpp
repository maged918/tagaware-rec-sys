//Language: GNU C++11


/*************************************************************************
    > File Name: code/cf/#313/EE.cpp
    > Author: 111qqz
    > Email: rkz2013@126.com 
    > Created Time: 2015年08月18日 星期二 18时43分18秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int N=2E3+7;
const int mod = 1E9 + 7;
const int M = 1E5+7;
int h,w,n;
typedef long long ll;
ll fac[2*M];
ll dp[N];
pair<int,int> p[N];
LL quickpow(LL a,LL b)
{
    LL res=1;
    while(b)
    {
        if(b&1) res=res*a%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
LL C(LL a,LL b)
{
    if(b>a) return 0;
    return fac[a]*quickpow(fac[b]*fac[a-b]%mod,mod-2)%mod;
}
LL lucas(LL a,LL b)
{
    if(b==0) return 1;
    return (C(a%mod,b%mod)*lucas(a/mod,b/mod))%mod;
}
void init()
{
    fac[0]=1,fac[1]=1;
    for(int i=1;i<2*M;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
}
int main()
{
    init();
    cin>>h>>w>>n;
    for(int i=1;i<=n;i++){
//      int x,y;  cin>>x>>y;
//      p[i].first=x; p[i].second=y;
        cin>>p[i].first;
        cin>>p[i].second;
    }
    p[n+1].first=h,p[n+1].second=w;
    sort(p+1,p+n+2);
    
    for(int i=1;i<=n+1;i++)
    {
        dp[i]=lucas(p[i].first+p[i].second-2,p[i].first-1);
        for(int j=1;j<i;j++)
        {
            if(p[j].second<=p[i].second) 
            {
                dp[i]-=dp[j]*lucas(p[i].first-p[j].first+p[i].second-p[j].second,p[i].first-p[j].first)%mod;
                dp[i] = (dp[i]+ mod ) % mod;
            }
        }
    }
    cout<<dp[n+1]<<endl;

    return 0;
}
