//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll num=-1,ans=-1,a,i;
set< ll >s;
ll pa[200005]={0},pacount[200005]={0},n,cnt[200005]={0},dp[200005];


void mul(ll x)
{
    ll u = x,vv = x,val = cnt[x],c=0;
    while(u)
    {
        ll p = u,jj  = 0;
        while(p <= num)
        {
            if(dp[p] != vv)
            {
        
                pa[p] = pa[p] + (c + jj)*val;
                pacount[p]+=val;
                dp[p] = vv;
            }
            p *= 2;
            jj++;
        }
        u /= 2;
        c++;
    }

}



int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        num = max(num,a);
        cnt[a]++;
        s.insert(a);
    }
    
    set< ll >::iterator it;
    for(it=s.begin();it!=s.end();++it)
    {
        
        mul(*it);
        
        
    }
    ans=100000000ll;
    //cout<<pacount[4]<<" ";
    for(i=0;i<=num;i++)
    {
        if(pacount[i]==n){
            //cout<<pa[i]<<","<<i<<" ";
            ans = min(ans,pa[i]);
        }
    }
    cout<<ans;
    return 0;
}