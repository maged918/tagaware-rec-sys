//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 100005;

#define MM(a,b,c) memset(a,b,sizeof(a[0]) * (c + 2))

struct Edge{
    int to,next;
    int c;
};
struct Node{/*{{{*/
    int id;
    LL c;
    Node(){}
    Node(int id,LL c):id(id),c(c){}
    bool operator < (const Node &a)const{
        return c > a.c;
    }
};/*}}}*/
struct Graph{/*{{{*/
    Edge e[M];
    int head[N],sz,n;
    int cnt[N];
    bool done[N];
    LL dis[N];
    priority_queue<Node> Q;
    void init(int _n){
        n = _n;
        MM(dis,0x3f,n);
        MM(done,0,n);
        MM(head,-1,n);
        sz = 0;
    }
    void addedge(int u,int v,int c){
        e[sz].to = v;
        e[sz].next = head[u];
        e[sz].c = c;
        head[u] = sz ++;
    }
    void dijkstra(int s){
        dis[s] = 0;
        Q.push(Node(s,0));
        while(!Q.empty()){
            Node t = Q.top();Q.pop();
            int u = t.id;
            if(done[u]) continue;
            done[u] = 1;dis[u] = t.c;
            for(int i = head[u]; i != -1 ; i = e[i].next){
                int v = e[i].to;
                LL tdis = dis[u] + e[i].c;
                if(tdis < dis[v]){
                    dis[v] = tdis;
                    Q.push(Node(v,tdis));
                }
            }
        }
    }
};/*}}}*/
int n,m,s,t;
Graph G1,G2;
Edge e[M];
int head[N],sz;
bool isb[M];
int low[N],DFN[N];
int Clock;
int S[N],top;
void init(){
    G1.init(n);
    G2.init(n);
    MM(DFN,0,n);
    MM(head,-1,n);
    MM(isb,0,m);
    Clock = top = 0;
}
void _addedge(int u,int v,int c){
    e[sz].to = v;
    e[sz].next = head[u];
    e[sz].c = c;
    head[u] = sz ++;
}
void addedge(int x,int y,int c){
    G1.addedge(x,y,c);
    G2.addedge(y,x,c);
}
void dijkstra(){
    G1.dijkstra(s);
    G2.dijkstra(t);
}
void tarjan(int u,int f,int pre){
    DFN[u] = low[u] = ++ Clock;
    S[++ top] = u;
    int flag = 1;
    for(int i = head[u] ; i != -1 ;i = e[i].next){
        int v = e[i].to;
        if(v == f && flag){
            flag = 0;
            continue;
        }
        if(DFN[v] == 0){
            tarjan(v,u,e[i].c);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],DFN[v]);
    }
    if(low[u] == DFN[u]){
        isb[pre] = 1;
        while(u != S[top]) top --;
    }
}
int U[N],V[N],C[N];
void solve(){
    init();
    scanf("%d%d",&s,&t);
    int x,y,c;
    for(int i = 0 ; i < m ; i ++){
        scanf("%d%d%d",&x,&y,&c);
        addedge(x,y,c);
        U[i] = x;V[i] = y;C[i] = c;
    }
    dijkstra();
    LL sdis = G1.dis[t];
    for(int i = 0 ; i < m ; i ++){
        if(G1.dis[ U[i] ] + G2.dis[ V[i] ] + C[i] == sdis){
            _addedge(U[i],V[i],i);
            _addedge(V[i],U[i],i);
        }
    }
    tarjan(s,0,m + 1);
    for(int i = 0 ; i < m ; i ++){
        if(isb[i]) printf("YES\n");
        else{
            LL tt = sdis - 1 - G1.dis[ U[i] ] - G2.dis[ V[i] ];
            if(tt > 0) printf("CAN %I64d\n",C[i] - tt);
            else printf("NO\n");
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)) solve();
    return 0;
}