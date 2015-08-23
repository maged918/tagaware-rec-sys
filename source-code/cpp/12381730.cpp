//Language: GNU C++


#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <utility>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <deque>
#include <queue>
using namespace std;

typedef long long ll;
//ifstream in("input.txt");
//ofstream out("output.txt");
const ll MAX_N = 100005;
vector<pair<ll, ll> > g[MAX_N], temp[2][MAX_N];
bool used[MAX_N], cut[MAX_N];
ll x[MAX_N], y[MAX_N], w[MAX_N], h[MAX_N], high[MAX_N], dist[2][MAX_N];
set<pair<ll, ll> > s;

void deik(ll v, ll t, ll n)
{
    for (ll i = 0; i < n; i++) {
        dist[t][i] = 1000000000000;
        dist[t][v] = 0;
        s.insert(make_pair(dist[t][i], i));
    }
    while (!s.empty()) {
        ll x = s.begin()->second;
        s.erase(s.begin());
        for (size_t i = 0; i < temp[t][x].size(); i++) {
            pair<ll, ll> y = temp[t][x][i];
            if (dist[t][x] + y.second < dist[t][y.first]) {
                s.erase(make_pair(dist[t][y.first], y.first));
                dist[t][y.first] = dist[t][x] + y.second;
                s.insert(make_pair(dist[t][y.first], y.first));
            }
        }
    }
}

void dfs(ll v, ll p = -1)
{
    used[v] = 1;
    high[v] = h[v];
    for (size_t i = 0; i < g[v].size(); i++) {
        pair<ll, ll> x = g[v][i];
        if (!used[x.first]) {
            h[x.first] = h[v] + 1;
            dfs(x.first, x.second);
            if (high[x.first] == h[x.first])
                cut[x.second] = true;
            high[v] = min(high[v], high[x.first]);
        }
        else
            if (x.second != p)
                high[v] = min(high[v], h[x.first]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ll s, t, n, m;
    cin >> n >> m >>  s >> t;
    s--, t--;
    for (ll i = 0; i < m; i++) {
        ll q, e, r;
        cin >> q >> e >> r;
        q--, e--;
        temp[0][q].push_back(make_pair(e, r));
        temp[1][e].push_back(make_pair(q, r));
        x[i] = q, y[i] = e, w[i] = r;
    }
    deik(s, 0, n);
    deik(t, 1, n);
    for (ll i = 0; i < m; i++) {
        if (dist[0][x[i]] + dist[1][y[i]] + w[i] == dist[0][t]) {
            g[x[i]].push_back(make_pair(y[i], i)), g[y[i]].push_back(make_pair(x[i], i));
        }
    }
    dfs(s);
    for (ll i = 0; i < m; i++) {
        if (cut[i])
            cout << "YES\n";
        else {
            if (dist[0][x[i]] + dist[1][y[i]] + 1 >= dist[0][t]) {
                cout << "NO\n";
            }
            else
                cout << "CAN " << w[i] - (dist[0][t] - (dist[0][x[i]] + dist[1][y[i]])) + 1 << '\n';
        }
    }
    return 0;
}