//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MOD = 201221187;
const int maxn = 100000 + 5;
const LL inf = (LL)1e16;

std::vector<std::pair<int,int> > edges[maxn],redges[maxn];
int ways[maxn],rways[maxn];
LL dis[maxn],rdis[maxn];
int W[maxn];
int n,m,s,t;


void dijkstra(LL *dis,int *ways,std::vector< std::pair<int,int> >*edges,int s,int t)
{
    std::priority_queue< std::pair<LL,int>,std::vector<std::pair<LL,int> >,
        std::greater<std::pair<LL,int> > > que;
    std::fill(dis,dis+n+1,inf);
    dis[s] = 0;
    ways[s] = 1;
    que.push( {dis[s],s} );
    while(!que.empty()){
        int u = que.top().second;
        LL tmp = que.top().first;
        que.pop();
        if(tmp != dis[u]) continue;
        for(auto t : edges[u]) {
            int v = t.first;
            int w = W[t.second];
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                ways[v] = ways[u];
                que.push({dis[v],v});
            } else if( dis[u] + w == dis[v] ){
                ways[v] += ways[u];
                if( ways[v] >= MOD ) {
                    ways[v] -= MOD;
                }
            }
        }
    }
}

LL answer[maxn];

void work()
{
    dijkstra(dis,ways,edges,s,t);
    dijkstra(rdis,rways,redges,t,s);
    for(int u = 1;u <= n; ++ u) {
        for(auto tt : edges[u]) {
            int v = tt.first;
            int w = W[ tt.second ];
            int id = tt.second;
            if( dis[u] + w + rdis[v] == dis[t]
               && ways[u] * 1ll * rways[v] % MOD == ways[t] ) {
                answer[ id ] = 0;
            } else if( dis[t] - dis[u] - rdis[v] - 1 > 0 ){
                LL tmp = dis[t] - dis[u] - rdis[v] - 1;
                answer[id] = w - tmp;
            } else {
                answer[id] = -1;
            }
        }
    }
    for(int i = 1; i <= m; i ++ ) {
        if(answer[i] == 0) {
            puts("YES");
        } else if( answer[i] == -1 ) {
            puts("NO");
        } else {
            printf("CAN %I64d\n",answer[i]);
        }
    }
}
int main()
{
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        W[i] = c;
        edges[a].push_back(make_pair(b,i));
        redges[b].push_back(make_pair(a,i));
    }
    work();
}
