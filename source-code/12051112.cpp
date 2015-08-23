//Language: GNU C++


// monera
#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f(i,a,b) for(int i =a; i <=b ; i++)
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define db(var) cout<<var<<" ";
#define el cout<<endl;
#define p(A,a,b)  f(i,a,b) cout<<A[i]<<" ";
#define sj  cout<<"OK"<<endl;
#define ll long long int 


//functions
#define count_1(n)    __builtin_popcountll(n)
#define gcd(a,b) __gcd(a,b)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )

#define MOD 1000000007
#define PI acos(-1.0)
#define e exp(1.0)
#define EPS 1e-9
#define INF    2047483647
#define INFLL  9023372036854775807LL

using namespace std;



int main() 
{
    ios :: sync_with_stdio(0);
     
     ll n;
     cin>>n;
     
     vector<ll> pos,neg;
     vector<pair<ll,ll> > v;
     f(i,0,n-1)
     {
        ll x,a;
        cin>>x>>a;
        v.pb(mp(x,a));
        
     }
     sort(all(v));
     
     for(int i=0;i<v.size();i++)
     {
        if(v[i].ff<0)
        neg.pb(v[i].ss);
        else
        pos.pb(v[i].ss);
        
     }
    
    reverse(neg.begin(),neg.end());
    
    
    
     
     ll ans=0;
     
     if(neg.size()==pos.size())
     {
        for(int i=0;i<neg.size();i++)
        ans+=neg[i];
        
        for(int i=0;i<pos.size();i++)
        ans+=pos[i];
        
        cout<<ans;
        return 0;
     }
     else if(neg.size()<pos.size())
     {
        
        
        int mini=neg.size()+1;
        
        
        for(int i=0;i<mini;i++)
        ans+=pos[i];
        
        for(int i=0;i<neg.size();i++)
        ans+=neg[i];
        
        
        
        cout<<ans;
        return 0;
        
     }
     else
     {
        int mini=pos.size()+1;
        
        for(int i=0;i<mini;i++)
        ans+=neg[i];
        
        for(int i=0;i<pos.size();i++)
        ans+=pos[i];
        
        
        
        cout<<ans;
        return 0;
     }
     
    
  return 0;
}