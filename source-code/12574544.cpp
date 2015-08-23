//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#define LL long long
#define oo 0x3f3f3f3f
#define OO 0x3f3f3f3f3f3f3f3f
#define EPS 1e-8
//using namespace std;
typedef std::pair<int,int> pii;
const int MaxN = 2e5 + 5;

LL d1[MaxN], d2[MaxN];
struct ssw{
    LL len;
    int u;
    ssw(int u, LL l): len(l), u(u){}
    bool operator < (const ssw & s2)const{
        return len > s2.len;
    }
};

struct Edge{
    int v, c, next, id;
}e1[MaxN], e2[MaxN], e3[MaxN];
int head1[MaxN], head2[MaxN], head3[MaxN];
int ecnt1, ecnt2, ecnt3;
int f[MaxN];
int n, m, s, t;
std::vector<pii> edge;

void add_edge(int u, int v, int c, int *head, Edge *e, int &ecnt, int id){
    e[ecnt].v = v; e[ecnt].c = c; e[ecnt].id = id; e[ecnt].next = head[u]; head[u] = ecnt++;
}

void dijkstra(int s, LL *d, int *head, Edge *e){
    std::priority_queue<ssw> que;
    memset(d, OO, sizeof(d) * MaxN); d[s] = 0;
    que.push(ssw(s, 0));
    while(!que.empty()){
        ssw t = que.top(); que.pop();
        if(t.len > d[t.u]) continue;
        for(int i = head[t.u]; ~i; i = e[i].next){
            int v = e[i].v, c = e[i].c;
            if(d[v] > d[t.u] + c){
                d[v] = d[t.u] + c;
                que.push(ssw(v, d[v]));
            }
        }
    }
}

void build(){
    for(int u = 1; u <= n; ++u){
        for(int i = head1[u]; ~i; i = e1[i].next){
            int v = e1[i].v, c = e1[i].c;
            if(d1[u] + d2[v] + c == d1[t]){
                add_edge(u, v, 1, head3, e3, ecnt3, i);
                add_edge(v, u, 1, head3, e3, ecnt3, i);
            }else if(d1[u] + d2[v] + 1 >= d1[t]){
                f[i] = -1;
            }
        }
    }
}

void init(){
    memset(head1, -1, sizeof(head1)); ecnt1 = 1;
    memset(head2, -1, sizeof(head2)); ecnt2 = 1;
    memset(head3, -1, sizeof(head3)); ecnt3 = 0;
    edge.resize(1);
}

int dfn[MaxN], low[MaxN], ti;
void tarjan(int u, int eid){
    dfn[u] = low[u] = ++ti;
    for(int i = head3[u]; ~i; i = e3[i].next){
        if(i == (eid ^ 1)) continue;
        int v = e3[i].v;
        if(!dfn[v]){
            tarjan(v, i);
            low[u] = std::min(low[u], low[v]);
            if(low[v] > dfn[u]){
                f[e3[i].id] = 1;
            }
        }else low[u] = std::min(low[u], dfn[v]);
    }
}

int main(){
    init();
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 1, x, y, z; i <= m; ++i){
        scanf("%d%d%d", &x, &y, &z);
        add_edge(x, y, z, head1, e1, ecnt1, i);
        add_edge(y, x, z, head2, e2, ecnt2, i);
        edge.push_back(pii(x,y));
    }
    dijkstra(s, d1, head1, e1);
    dijkstra(t, d2, head2, e2);
    build();
    tarjan(s, -1);
    for(int i = 1; i <= m; ++i){
        int u = edge[i].first, v = edge[i].second;
        if(f[i] == 1){
            printf("YES\n");
        }else if(f[i] == -1){
            printf("NO\n");
        }else{
            LL tot = d1[u] + d2[v] + e1[i].c + 1 - d1[t];
            if(e1[i].c - tot > 0) printf("CAN %d\n", tot);
            else printf("NO\n");
        }
    }
    return 0;
}
