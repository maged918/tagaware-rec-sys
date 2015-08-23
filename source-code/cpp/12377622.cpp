//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
map<ll,int> m;//number,count
map<ll,int> :: iterator it;
int main()
{
    int n;
    ll k;
    cin>>n>>k;
    int i,j,a[n];
    for(i=0;i<n;i++)cin>>a[i];
    ll dp[n];
    for(i=n-1;i>=0;i--)
    {
        it=m.find(a[i]*k);
        if(it==m.end())
            dp[i]=0;
        else
            dp[i]=it->second;
        //upd count of a[i]
        it=m.find(a[i]);
        if(it!=m.end())
            it->second++;
        else
            m.insert(make_pair(a[i],1));
    }
    //for(i=0;i<n;i++)cout<<dp[i]<<",";
    m.clear();
    for(i=0;i<n;i++)
    {
        if(a[i]%k!=0)
        {
            dp[i]=0;
            goto here;
        }
        it=m.find(a[i]/k);
        if(it==m.end())
            dp[i]=0;
        else
            dp[i]*=it->second;
        //upd count of a[i]
        here:
        it=m.find(a[i]);
        if(it!=m.end())
            it->second++;
        else
            m.insert(make_pair(a[i],1));
    }
    ll ans=0;
    //for(i=0;i<n;i++)cout<<dp[i]<<",";
    for(i=0;i<n;i++)ans+=dp[i];
    cout<<ans;
    return 0;
}