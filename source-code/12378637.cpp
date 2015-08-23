//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

const long long INF = numeric_limits<long long>::max() / 4;

const long long MOD = 1000000000 + 7;
const long long MOD2 = 1000000000 + 9;
const long long MOD3 = 1000000 + 7;

tuple<vector<long long>, vector<long long>,
    vector<long long>, vector<long long>>
dijkstra(const vector<vector<pair<int, int>>>& g, int src) {
    vector<long long> dists(g.size(), INF);
    set<pair<long long, int> > q;
    q.insert(make_pair(0LL, src));
    dists[src] = 0;

    while (!q.empty()) {
        auto next = *q.begin();
        q.erase(q.begin());
        long long d = next.first, v = next.second;
        for (auto& e : g[v]) {
            long long du = d + e.second;
            if (du < dists[e.first]) {
                dists[e.first] = du;
                q.insert(make_pair(du, e.first));
            }
        }
    }

    vector<pair<long long, int>> vs(g.size());
    vector<long long> ways(g.size());
    vector<long long> ways2(g.size());
    vector<long long> ways3(g.size());

    for (int i = 0; i < g.size(); i++)
        vs[i] = make_pair(dists[i], i);

    sort(vs.begin(), vs.end());

    ways[src] = 1;
    ways2[src] = 1;
    ways3[src] = 1;

    for (int i = 0; i < vs.size(); i++) {
        for (int j = 0; j < g[vs[i].second].size(); j++) {
            if (dists[g[vs[i].second][j].first] == vs[i].first + g[vs[i].second][j].second) {
                ways[g[vs[i].second][j].first] += ways[vs[i].second];
                ways[g[vs[i].second][j].first] %= MOD;

                ways2[g[vs[i].second][j].first] += ways2[vs[i].second];
                ways2[g[vs[i].second][j].first] %= MOD2;

                ways3[g[vs[i].second][j].first] += ways3[vs[i].second];
                ways3[g[vs[i].second][j].first] %= MOD3;
            }
        }
    }

    return make_tuple(dists, ways, ways2, ways3);
}

int main() {
    ios::sync_with_stdio(false);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s;
    --t;

    vector<vector<pair<int, int>>> g(n), gt(n);
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a-1].push_back(make_pair(b-1, w));
        gt[b-1].push_back(make_pair(a-1, w));
        edges.push_back(make_tuple(a-1, b-1, w));
    }

    auto dists_ways = dijkstra(g, s);
    auto dists_ways_t = dijkstra(gt, t);

    auto dists = get<0>(dists_ways);
    auto dists_t = get<0>(dists_ways_t);
    auto ways = get<1>(dists_ways);
    auto ways2 = get<2>(dists_ways);
    auto ways3 = get<3>(dists_ways);

    auto ways_t = get<1>(dists_ways_t);
    auto ways_t2 = get<2>(dists_ways_t);
    auto ways_t3 = get<3>(dists_ways_t);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        tie(a, b, w) = edges[i];

        if (dists[a] + dists_t[b] + w == dists[t] &&
                ways[a] * ways_t[b] % MOD == ways[t] &&
                ways2[a] * ways_t2[b] % MOD2 == ways2[t] &&
                ways3[a] * ways_t3[b] % MOD3 == ways3[t]) {
            cout << "YES\n";
        } else {
            long long reduc = (dists[a] + dists_t[b] + w) - (dists[t] - 1);

            if (reduc < w) {
                cout << "CAN " << reduc << '\n';
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
