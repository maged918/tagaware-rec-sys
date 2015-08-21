//Language: GNU C++11


#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=200010;
const int maxm=1010;
const int MOD=1e9+7;
const LL INF=1e18;
int N,M,S,T;
int ans[maxn];
struct Edge
{
    int from,to,id;
    LL dist;
    Edge(int f=0,int t=0,LL d=0,int _id=0):from(f),to(t),dist(d),id(_id){}
};
Edge edge[maxn];
struct HeapNode//优先队列节点
{
    int u;
    LL d;
    HeapNode(LL _d=0,int _u=0):d(_d),u(_u){}
    bool operator<(const HeapNode &rhs)const
    {
        return d>rhs.d;
    }
};
struct Dijkstra
{
    int n,m;               //点数和边数
    vector<Edge> edges;    //边列表
    vector<int> G[maxn];   //每个节点出发的边编号(编号从0开始)
    bool done[maxn];       //是否已永久标号
    LL d[maxn];           //s到各个点的距离
    vector<int> p[maxn];           //最短路中的上一条边
    void init(int n)
    {
        this->n=n;
        for(int i=0;i<=n;i++)G[i].clear(),p[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int dist,int id)
    {
        edges.push_back(Edge(from,to,dist,id));
        m=edges.size();
        G[from].push_back(m-1);
    }
    void dijkstra(int s)
    {
        priority_queue<HeapNode> Q;
        for(int i=0;i<=n;i++)d[i]=INF;
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push(HeapNode(0,s));
        while(!Q.empty())
        {
            HeapNode x=Q.top();Q.pop();
            int u=x.u;
            if(done[u])continue;
            done[u]=true;
            for(int i=0;i<G[u].size();i++)
            {
                Edge &e=edges[G[u][i]];
                if(d[e.to]>d[u]+e.dist)
                {
                    d[e.to]=d[u]+e.dist;
                    p[e.to].clear();
                    p[e.to].push_back(G[u][i]);
                    Q.push(HeapNode(d[e.to],e.to));
                }
                else if(d[e.to]==d[u]+e.dist)
                {
                    p[e.to].push_back(G[u][i]);
                    Q.push(HeapNode(d[e.to],e.to));
                }
            }
        }
    }

}dij1,dij2;
int dfs_clock,cnt;
int dfn[maxn],low[maxn];
vector<Edge> g[maxn];
bool vis[maxn];
int tarjan(int u,int fa)
{
    int lowu=dfn[u]=++dfs_clock;
    int child=0;
    int len=g[u].size();
    for(int i=0;i<len;i++)
    {
        Edge e=g[u][i];
        int v=e.to;
        if(!dfn[v])
        {
            child++;
            int lowv=tarjan(v,e.id);
            lowu=min(lowv,lowu);
            if(lowv>dfn[u])
            {
                ans[e.id]=true;
                //cout<<e.from<<" "<<e.to<<endl;
            }
        }
        else if(dfn[v]<dfn[u]&&e.id!=fa)
            lowu=min(lowu,dfn[v]);
    }
    low[u]=lowu;
    return lowu;
}
void dfs(int u,int fa)
{
    if(u==S)return ;
    int len=dij1.p[u].size();
    for(int i=0;i<len;i++)
    {
        Edge e=dij1.edges[dij1.p[u][i]];
        if(dij1.d[e.from]+e.dist==dij1.d[u]&&!vis[e.id])
        {
            g[e.from].push_back(Edge(e.from,u,e.dist,e.id));
            g[e.to].push_back(Edge(e.to,e.from,e.dist,e.id));
            //cout<<e.from<<" "<<e.to<<" "<<u<<endl;
            vis[e.id]=1;
            dfs(e.from,u);
        }
    }
}
void build()
{
    for(int i=0;i<M;i++)
    {
        int u=dij1.edges[i].from;
        int v=dij1.edges[i].to;
        int w=dij1.edges[i].dist;
        if(dij1.d[u]+w==dij1.d[v]&&dij2.d[v]+w==dij2.d[u])
        {
            g[u].push_back(Edge(u,v,w,dij1.edges[i].id));
            g[v].push_back(Edge(v,u,w,dij1.edges[i].id));
        }
    }
}
int main()
{
    scanf("%d%d%d%d",&N,&M,&S,&T);
    int u,v,len;
    dij1.init(N);
    dij2.init(N);
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&u,&v,&len);
        dij1.AddEdge(u,v,len,i);
        dij2.AddEdge(v,u,len,i);
    }
    dij1.dijkstra(S);
    dij2.dijkstra(T);
    if(dij1.d[T]==INF)
    {
        for(int i=0;i<M;i++)
            printf("NO\n");
        return 0;
    }
    memset(ans,0,sizeof(ans));
    dfs_clock=cnt=0;
    memset(dfn,0,sizeof(dfn));
    //dfs(T,-1);
    build();
    tarjan(S,-1);

    for(int i=0;i<M;i++)
    {
        if(ans[i])
        {
            printf("YES\n");
            continue;
        }
        Edge e=dij1.edges[i];
        int u=e.from,v=e.to;
        LL tmp=dij1.d[u]+dij2.d[v]+e.dist-dij1.d[T]+1;
        if(tmp>=e.dist)printf("NO\n");
        else printf("CAN %I64d\n",tmp);
    }
    return 0;
}
