//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> rt,lf;
ll a[200001];
main()
{
    ll n,k,k1,k2,ans=0;
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        rt[a[i]]++;
    }
    for(int i=0;i<n;++i)
    {
        k1=0;k2=0;
        if(a[i]%k==0)
        k1=lf[a[i]/k];
        rt[a[i]]--;
        k2=rt[a[i]*k];
        ans+=k1*k2;
        lf[a[i]]++;
    }
    cout<<ans;
}