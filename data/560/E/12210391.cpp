//Language: GNU C++


#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;
int mod=1000000007;
long long fact[200005],eurev[200005];
long long pp(int d1,int d2)
{
  return (fact[d1+d2]*((eurev[d1]*eurev[d2])%mod))%mod;
}
long long fpow(long long x,int n)
{
    if(n==0)
        return 1;
    long long ret=fpow(x,n>>1);
    ret=(ret*ret)%mod;
    if(n&1)
        ret=(ret*x)%mod;
    return ret;
}
int main()
{

    int h,w,n;
    pair<int,int> b[2005];
    long long dp[2005];
    fact[0]=1;
    eurev[0]=1;
    for(int i=1;i<200001;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        eurev[i]=fpow(fact[i],mod-2);
    }
    cin>>h>>w>>n;
    b[0].first=1;
    b[0].second=1;
    for(int i=1;i<=n;i++)
        {
            cin>>b[i].first>>b[i].second;
        }
    b[n+1].first=h;
    b[n+1].second=w;
    sort(b,b+n+2);
    for(int i=1;i<n+2;i++)
    {
        dp[i]=pp(b[i].first-1,b[i].second-1);
        //cout<<b[i].first<<" "<<b[i].second<<'\n';
        //cout<<dp[i]<<"ippo\n";
        for(int j=i-1;j>0;j--)
        {
            if(b[i].first>=b[j].first&&b[i].second>=b[j].second)
             {
         //     cout<<"enna da pp"<<pp(b[i].first-b[j].first,b[i].second-b[j].second)<<" "<<b[i].first-b[j].first<<" "<<b[i].second-b[j].second<<'\n';
              dp[i]=(dp[i]+mod-dp[j]*pp(b[i].first-b[j].first,b[i].second-b[j].second))%mod;
              dp[i]%=mod;
             }
        }
       // cout<<dp[i]<<"aprom\n";
    }
    cout<<(dp[n+1]+mod)%mod;
    return 0;
}
