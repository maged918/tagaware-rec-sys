//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+10;
typedef pair <long long, int>pli;
typedef long long LL;
const LL inf = 1LL << 40;
const int MOD = 258280327;
struct Edge{
    int to, cost;
    Edge (){}
    Edge (int to, int cost): to(to), cost(cost){}
};
LL d1[MAXN], d2[MAXN];
LL cnt1[MAXN], cnt2[MAXN];
void Dijkstra(int s, LL dis[], vector<Edge>G[], LL cnt[]){
    for (int i = 0; i < MAXN; i++){
        dis[i] = inf;
    }
    priority_queue<pli, vector<pli>, greater<pli> >Q;
    dis[s] = 0;
    Q.push(make_pair(dis[s], s));
    cnt[s] = 1;
    while (!Q.empty()){
        pli tmp = Q.top();
        Q.pop();
        int u = tmp.second;
        if (dis[u] < tmp.first){
            continue;
        }
        for (Edge e: G[u]){
            int v = e.to;
            int c = e.cost;
            if (dis[v] > dis[u] + c){
                cnt[v] = cnt[u];
                dis[v] = dis[u] + c;
                Q.push(make_pair(dis[v], v));
            }else if (dis[v] == dis[u] + c){
                cnt[v] += cnt[u];
                if (cnt[v] >= MOD){
                    cnt[v] -= MOD;
                }
            }
        }
    }
}
vector<Edge>G[MAXN];
vector<Edge>rG[MAXN];
void init (){
    for (int i = 0; i < MAXN; i++){
        G[i].clear();
        rG[i].clear();
    }
    memset(cnt1, 0, sizeof cnt1);
    memset(cnt2, 0, sizeof cnt2);
}
int U[MAXN], V[MAXN], C[MAXN];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    int n, m, s, t;
    while (~ scanf ("%d%d%d%d", &n, &m, &s, &t)){
        init();
        for (int i = 0; i < m; i++){
            int u, v, c;
            scanf ("%d%d%d", &u, &v, &c);
            U[i] = u, V[i] = v, C[i] = c;
            G[u].push_back(Edge(v, c));
            rG[v].push_back(Edge(u, c));
        }
        Dijkstra(s, d1, G, cnt1);
        Dijkstra(t, d2, rG, cnt2);
        for (int i = 0; i < m; i++){
            int u = U[i], v = V[i], c = C[i];
            if (d1[u] + d2[v] + c == d1[t] && (cnt1[u] * cnt2[v])%MOD == cnt1[t]%MOD){
                printf("YES\n");
            }else if ((d1[u]+d2[v]+c)-d1[t]+1>0 && (d1[u]+d2[v]+c)-d1[t]+1< c){
                printf("CAN %d\n", (d1[u] + d2[v] + c) - d1[t] +1);
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
