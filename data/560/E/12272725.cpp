//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long fact[200003];
long long invfact[200003];
long long mod=1000000007;
pair<int,int> arr[200004];
long long ways[2500];
long long power(int x,int a)
{
    long long temp=x;
    long long ans=1;
    while(a)
    {
        if(a%2==1)
        {
            ans=ans*temp;
            if(ans>mod)
                ans%=mod;
        }
        temp=temp*temp;
        if(temp>mod)
            temp%=mod;
        a/=2;
    }
    return ans;
}
void factorial()
{
    invfact[0]=1;
    fact[0]=1;
    fact[1]=1;
    for(long long i=2;i<=200000;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    long long i;
    invfact[200000]=power(fact[200000],mod-2);
    for(i=199999;i>=1;i--)
    {
        invfact[i]=(invfact[i+1]*(i+1))%mod;
    }
}
long long comp(int n, int r)
{
    if(n<=0)
        return 0;
    if(r==0||n-r==0)
        return 1;
    long long ans=1;
    ans= (ans * fact[n])%mod;
    ans = (ans* invfact[r])%mod;
    ans = (ans * invfact[n-r])%mod;
    return ans;
    //cout<<n<<" "<<r<<" "<<ans<<endl;
}
int main()
{
    long long i,j,k,l,m,n,h,w;
    cin>>h>>w>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    factorial();
    //cout<<"rishabh"<<endl;
    sort(arr,arr+n);
    for(i=0;i<n;i++)
    {
        ways[i]= comp(arr[i].first+arr[i].second-2,arr[i].first-1);
    }
    //for(i=0;i<n;i++)
      //  cout<<ways[i]<<endl;
    long long ans = comp(h+w-2,h-1);
    for(i=0;i<n;i++)
    {
        ans-= (ways[i]*comp(h+w-arr[i].first-arr[i].second,h-arr[i].first))%mod;
        if(ans<0)
            ans+=mod;
        for(j=i+1;j<n;j++)
        {
            ways[j]-= (ways[i]*comp(arr[j].first+arr[j].second-arr[i].first-arr[i].second,arr[j].first-arr[i].first))%mod;
            if(ways[j]<0)
                ways[j]+=mod;
        }
    }
    cout<<ans<<endl;
}
