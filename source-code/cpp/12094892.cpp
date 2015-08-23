//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
ll s[100004],cnt[100005],vis[100005];
int main()
{
    ll n,x,y;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        queue<pair<int,int> > q;
        q.push(mp(x,0));
        while(!q.empty())
        {
            x=q.front().first,y=q.front().second;
            q.pop();
            if(x>100000)continue;
            if(vis[x]==i)continue;
            vis[x]=i;
            s[x]+=y;
            cnt[x]++;
            q.push(mp(2*x,y+1));q.push(mp(x/2,y+1));
        }
    }
    ll ans=INT_MAX;
    for(int i=0;i<=100000;i++)
    if(cnt[i]==n && ans>s[i])
    ans=s[i];
    cout<<ans<<"\n";
    return 0;
}