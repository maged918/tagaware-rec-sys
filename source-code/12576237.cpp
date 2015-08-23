//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int nmax = 1e5 + 5;
using int64 = long long int;
using pii = pair<int64, int>;
const int64 inf = 1e13;
const int mod = 500000003;

int n, m, s, t;
vector<vector<pii>> graph, grapht;
vector<pii> edges;
vector<int64> costs;
priority_queue<pii, vector<pii>, greater<pii>> q;
int64 dist1[nmax], dist2[nmax];
int paths1[nmax], paths2[nmax];

void dijkstra(int ss, vector<vector<pii>> &graph, int64 dist[], int paths[]) {
    bool done[nmax];
    for (int i = 1; i <= n; ++i) {
        done[i] = false;
        dist[i] = inf;
    }
    dist[ss] = 0;
    paths[ss] = 1;
    q.push({0, ss});

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (done[u])
            continue;
        done[u] = 1;

        for (auto it : graph[u]) {
            int v = it.first;
            int64 c = it.second;
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                paths[v] = paths[u];
                q.push({dist[v], v});
            } else if (dist[u] + c == dist[v])
                paths[v] = (paths[v] + paths[u]) % mod;
        }
    }
}

int main() {
    cin >> n >> m >> s >> t;

    graph.resize(n + 1);
    grapht.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v});
        costs.push_back(c);
        graph[u].push_back({v, c});
        grapht[v].push_back({u, c});
    }

    dijkstra(s, graph, dist1, paths1);
    dijkstra(t, grapht, dist2, paths2);

    int64 dmin = dist1[t];
    int tpaths = paths1[t];
    for (int i = 0; i < m; ++i) {
        int64 u = edges[i].first;
        int64 v = edges[i].second;
        int64 c = costs[i];
        int64 temp = dist1[u] + dist2[v] + c;

        if (dmin == temp && (1ll * paths1[u] * paths2[v]) % mod == tpaths)
            cout << "YES\n";
        else if (temp - dmin + 1 < c)
            cout << "CAN " << temp - dmin + 1 << '\n';
        else
            cout << "NO\n";
    }

    return 0;
}
