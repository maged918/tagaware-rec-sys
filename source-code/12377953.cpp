//Language: GNU C++11


//  .cpp
//
//  Created by shikhar thakur
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <iomanip>
#include <cmath>
#define ll long long
#define pb push_back
#define mp make_pair
#define gcd(a,b) __gcd(a,b)
#define fillm(v,val) memset(v,val,sizeof(v))
#define _iosync ios_base::sync_with_stdio(false);cin.tie(0);
const ll mod= 1000000007ll;
#define pi acos(-1.0)

using namespace std;

multiset<ll>indexofseg;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    _iosync
    ll n,k,a,m,possible;
    cin>>n>>k>>a;
    cin>>m;
    ll ar[m];
    for(ll i=0;i<m;i++)
    {
        cin>>ar[i];
    }
    possible=(n+1)/(a+1);
    indexofseg.insert(0);
    indexofseg.insert(n+1);
    ll tmp;
    for(ll i=0;i<m;i++)
    {
        ll q=ar[i];
        auto l=indexofseg.upper_bound(q);
        auto r=l;
        l--;        
        
        indexofseg.insert(q);
        
        tmp=((q-(*l))/(a+1) + ((*r)-q)/(a+1));
        possible+=(tmp);
        possible-=((*r)-(*l))/(a+1) ;
        
        if(possible<k)
        {
            cout<<i+1<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}