//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define M 100009
#define mod 119999819
#define INF 1e18
typedef long long ll;
typedef struct
{
    ll to,cost;
    ll from;
}edge;
vector <edge> g[2][M];
ll dis[2][M];
ll num[2][M];
edge mp[M];
ll s,t;
ll n,m;
typedef pair<ll,ll> P;
void dijkstra(int st,int a)
{
    priority_queue<P , vector<P> , greater<P> > q;
    dis[a][st] = 0;
    num[a][st] = 1;
    q.push(P(0,st));
    while(!q.empty())
    {
        P p = q.top();
        q.pop();
        int v = p.second;
        if(dis[a][v] < p.first) continue;
        for(int i = 0 ;i < g[a][v].size();i++)
        {
            edge e = g[a][v][i];
            if(dis[a][e.to] > dis[a][v] + e.cost)
            {
                dis[a][e.to] = dis[a][v] + e.cost;
                q.push(P(dis[a][e.to],e.to));
                num[a][e.to] = num[a][v]%mod;
            }
            else if(dis[a][e.to] == dis[a][v] + e.cost)
            {
                num[a][e.to] += num[a][v]%mod;
                num[a][e.to] %= mod;
            }
        }
    }
}
int main()
{
    while(scanf("%I64d %I64d %I64d %I64d",&n,&m,&s,&t)==4)
    {
        for(int i = 0;i < 2;i++)
        {
            fill(dis[i],dis[i]+n+1,INF);
            fill(num[i],num[i]+n+1,0);
            for(int j = 0;j <= n;j++)
                g[i][j].clear();
        }
        for(int i = 0;i < m;i++)
        {
            ll a,b,c;
            scanf("%I64d %I64d %I64d",&a,&b,&c);
            mp[i].from = a;
            mp[i].to = b;
            mp[i].cost = c;
            edge e = {b,c};
            g[0][a].push_back(e);
            e = {a,c};
            g[1][b].push_back(e);
        }
        dijkstra(s,0);
        dijkstra(t,1);
        for(int i = 0;i < m;i++)
        {
            edge e = mp[i];
            /*if(dis[0][e.from] + dis[1][e.to] + e.cost == dis[0][t])
            {
                if(num[0][e.from]*num[1][e.to] == num[0][t])
                    printf("YES\n");
                else if(e.cost > 1)
                {
                    printf("CAN 1\n");
                }
                else
                    printf("NO\n");
            }
            else
            {
                ll a = dis[0][t] - (dis[0][e.from] + dis[1][e.to]);
                if(a - 1 > 0)
                printf("CAN %I64d\n",e.cost-a+1);
                else printf("NO\n");
            }*/
            if(dis[0][e.from] + dis[1][e.to] + e.cost == dis[0][t] && (num[0][e.from]%mod)*(num[1][e.to]%mod)%mod == num[0][t]%mod)
                printf("YES\n");
            else
            {
                ll a = dis[0][t] - (dis[0][e.from] + dis[1][e.to]);
                if(a - 1 > 0)
                printf("CAN %I64d\n",e.cost-a+1);
                else printf("NO\n");
            }
        }
    }
    return 0;
}
