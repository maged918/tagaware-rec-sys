//Language: GNU C++


#define problem "314E"
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
const int maxN = 1e5 + 10, maxM = 1e5 + 10;
const long long oo = 1e12;
typedef long long ll;
typedef ll l_N[maxN];
typedef int i_N[maxN];
typedef int i_M[maxM];
typedef pair<ll, int> li;
int N, M, U, V;
namespace graph{
    struct EDGE{
        int u, v, W, id, type_edge;
        EDGE(){}
        EDGE(int _u, int _v, int _W, int _id, int _type_edge) : u(_u), v(_v), W(_W), id(_id), type_edge(_type_edge){}
    } edge[maxM];

    int Cnum;
    l_N Lu, Lv, P, low, num, visit, pre_edge, bridge;
    i_M mark, on_dijkstra;
    vector<EDGE> adj[maxN];
    priority_queue<li, vector<li>, greater<li> > heap;
    deque<int> DFS_node;
    void link(int u, const EDGE &E){
        adj[u].push_back(E);
    }

    int get_adj_node(int u, const EDGE &E){
        return (u != E.u)? E.u : E.v;
    }
}

void dijkstra(int U, int type, ll *L){
    using namespace graph;
    for(int i = 1; i <= N; i++) L[i] = -1;
    L[U] = 0;
    heap.push(li(0, U));
    while(!heap.empty()){
        li top_node = heap.top(); heap.pop();
        int u = top_node.second;
        ll leng = top_node.first;
        if(leng != L[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            const EDGE E = adj[u][i];
            if(E.type_edge != type) continue;
            int v = get_adj_node(u, E);
            if(L[v] == -1 || L[v] > leng + E.W){
                L[v] = leng + E.W;
                heap.push(li(L[v], v));
            }
        }
    }
}

void DFS(int u){
    using namespace graph;
    memset(P, 0, sizeof(P));
    P[u] = -1;
    DFS_node.push_back(u);
    while(!DFS_node.empty()){
        int u = DFS_node.back();
        if(!visit[u]) low[u] = num[u] = ++Cnum;
        if(visit[u] < adj[u].size()){
            const EDGE E = adj[u][visit[u]++];
            int v = get_adj_node(u, E);
            if(mark[E.id]++ || !on_dijkstra[E.id]) continue;
            if(!P[v]){
                pre_edge[v] = E.id;
                P[v] = u;
                DFS_node.push_back(v);
            }else low[u] = min(low[u], num[v]);
        }else{
            DFS_node.pop_back();
            int parent = P[u];
            if(parent != -1){
                low[parent] = min(low[parent], low[u]);
                if(low[u] == num[u]) bridge[pre_edge[u]] = 1;
            }
        }
    }
}

int main(){
    
    scanf("%d %d %d %d\n", &N, &M, &U, &V);
    for(int i = 0; i < M; i++){
        int u, v, W;
        scanf("%d %d %d\n", &u, &v, &W);
        graph::edge[i] = graph::EDGE(u, v, W, i, 1);
        graph::link(u, graph::EDGE(u, v, W, i, 1));
        graph::link(v, graph::EDGE(u, v, W, i, 2));
    }
    dijkstra(U, 1, graph::Lu);
    dijkstra(V, 2, graph::Lv);
    for(int i = 0; i < M; i++){
        using namespace graph;
        int u = edge[i].u, v = edge[i].v, W = edge[i].W;
        if(Lu[u] + Lv[v] + W == Lu[V])
            on_dijkstra[edge[i].id] = 1;
    }
    DFS(U);
    {
        using namespace graph;
        for(int i = 0; i < M; i++){
                int u = edge[i].u, v = edge[i].v, W = edge[i].W;
                if(Lu[u] == -1 || Lv[v] == -1){
                    puts("NO");
                    continue;
                }
                if(bridge[i]){
                    puts("YES");
                    continue;
                }
                ll ans = Lu[u] + Lv[v] + W - Lu[V] + 1;
                if(ans < edge[i].W) printf("CAN %I64d\n", ans); else puts("NO");
            }
    }
}
