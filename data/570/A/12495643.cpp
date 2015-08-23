//Language: GNU C++


#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define MOD 1000000007
ll mpow(ll a, ll n,ll mod)
{ll ret=1;ll b=a;while(n) {if(n&1)
    ret=(ret*b)%mod;b=(b*b)%mod;n>>=1;}
return (ll)ret;
}
using namespace std;
#define irr acos(-1.0)
#define mem(x,a) memset(x,a,sizeof(x))
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define N 100000+5
int a[101];
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        int max1=-1,ind;
        for(j=0;j<n;j++)
        {
            int x;
            cin>>x;
            if(max1<x)
            {
                ind=j+1;
                max1=x;
            }
        }
        a[ind]++;
    }
    int max1=-1,ind;
    for(j=0;j<=n;j++)
    {
        if(max1<a[j])
        {
            max1=a[j];
            ind=j;
        }
    }
    cout<<ind;



    return 0;
}
