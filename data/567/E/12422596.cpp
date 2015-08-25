//Language: GNU C++


#include <bits/stdc++.h>
#define inf 1000000000000000LL
#define pb push_back
#define mp make_pair
#define ll long long
#define pll pair<ll,ll>
#define pllll pair< pll,pll >
#define vpll vector< pll >
#define rep(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
priority_queue<pll,vector<pll>,greater<pll> > Q;
ll d1[100005],d2[100005],ok[100005];
ll dp[100005],h[100005],mark[100005],spt[100005];
vpll g[100005],gr[100005],gs[100005];
vector< pllll > edge;
vector< pair<pll,ll> > edge1;
ll n;
void isbridge(ll u,ll id=-1)
{
    static ll time = 0;
    mark[u] = 1;
    h[u] = dp[u] = ++time;
    rep(i,0,gs[u].size())
    {
        ll v = gs[u][i].first,ind=gs[u][i].second;
        if (!mark[v])
        {
            isbridge(v,ind);
            dp[u]  = min(dp[u], dp[v]);
            if (dp[v] > h[u])ok[ind]=1;
        }
        else if (ind!=id)
            dp[u]  = min(dp[u], h[v]);
    }
}
void dijkstra1(ll src)
{
    memset(spt,false,sizeof(spt));
    Q.push(pll(0,src));
    d1[src]=0;
    //spt[src]=true;
	while(!Q.empty())
	{
		pll tp=Q.top();
		ll v=tp.second, t=tp.first;
		Q.pop();
		//cout<<v<<endl;
		spt[v]=1;
        for(ll i=0;i<g[v].size();i++)
        {
            ll v2=g[v][i].first, cost=g[v][i].second;
            if(!spt[v2]&&d1[v2]>d1[v]+cost)
            {
                d1[v2]=d1[v]+cost;
                Q.push(pll(d1[v2],v2));
            }
        }
    }
}
void dijkstra2(ll src)
{
    memset(spt,false,sizeof(spt));
    Q.push(pll(0,src));
    d2[src]=0;
    //spt[src]=true;
	while(!Q.empty())
	{
		pll tp=Q.top();
		ll v=tp.second, t=tp.first;
		Q.pop();
		//cout<<v<<endl;
		spt[v]=1;
        for(ll i=0;i<gr[v].size();i++)
        {
            ll v2=gr[v][i].first, cost=gr[v][i].second;
            if(!spt[v2]&&d2[v2]>d2[v]+cost)
            {
                d2[v2]=d2[v]+cost;
                Q.push(pll(d2[v2],v2));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll m,s,t;
    cin>>n>>m>>s>>t;
    rep(i,0,m)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edge1.pb(mp(mp(a,b),c));
        g[a].pb(mp(b,c));
        gr[b].pb(mp(a,c));
    }
    //memset(d1,63,sizeof(d1));
    //memset(d2,63,sizeof(d2));
    rep(i,0,100005){d1[i]=inf;d2[i]=inf;}
    dijkstra1(s);
    while(!Q.empty())Q.pop();
    dijkstra2(t);
    //rep(i,1,n+1)cout<<d1[i]<<' '<<d2[i]<<endl;
    rep(i,0,edge1.size())
    {
            ll v1 = edge1[i].first.first,v2=edge1[i].first.second,cost=edge1[i].second;
            if(d1[v1]+cost+d2[v2]==d1[t])
            {
                gs[v1].pb(mp(v2,i));
                gs[v2].pb(mp(v1,i));
            }
    }
    isbridge(s);
    rep(i,0,m)
    {
	  int v=edge1[i].first.first, u = edge1[i].first.second, w = edge1[i].second;
	  if(ok[i]) { cout << "YES\n"; continue; }

	  if(d1[t] <= d1[v] + 1 + d2[u]) { cout << "NO\n"; continue; }

	  cout << "CAN " << w - ((d1[t]-1) - (d1[v] + d2[u])) << endl;
    }

    return 0;
}
