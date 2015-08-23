//Language: GNU C++


#include <bits/stdc++.h>
#define ll long long int
#define  si(x)     scanf("%d",&x)
#define  slli(x)   scanf("%lld",&x)
#define fil(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define fastscan ios_base::sync_with_stdio(0); cin.tie(NULL);
#define foreach(v, c) for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define pii pair<int,int>
#define MAX 200005
#define mod 10000007
using namespace std;
ll a[MAX];
int main()
{
    ll n,k,i;
    slli(n);
    slli(k);
    map<ll,ll> mymap1,mymap2,mymap3;


        ll ans=0,tt=0;
        for(i=0;i<n;i++)
        {
            slli(a[i]);
            mymap1[a[i]]++;
        }
        for(i=0;i<n;i++)
        {
            mymap1[a[i]]--;
            if(a[i]%k==0)
            ans+=(ll)mymap2[a[i]/k]*(ll)mymap1[a[i]*k];
            mymap2[a[i]]++;        }
        printf("%lld\n",ans);


}
