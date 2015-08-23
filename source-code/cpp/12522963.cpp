//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

#define ws ___ws

const int MAXN = 100100;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> edge;

const int MOD1 = 23;
const int MOD2 = 1000000007;
const int MOD3 = 1000000009;

struct hashed_int {
    ll h1, h2, h3;
    
    hashed_int() {}
    
    hashed_int(int x) {
        h1 = (x + MOD1) % MOD1;
        h2 = (x + MOD2) % MOD2;
        h3 = (x + MOD3) % MOD3;
    }
    
    hashed_int(ll a, ll b, ll c) :h1(a), h2(b), h3(c) {}
    
    bool operator ==(const hashed_int & o) const {
        return h1 == o.h1 && h2 == o.h2 && h3 == o.h3;
    }
    
    hashed_int operator +(const hashed_int & o) {
        return hashed_int((h1 + o.h1) % MOD1, (h2 + o.h2) % MOD2, (h3 + o.h3) % MOD3);
    }
    
    hashed_int operator *(const hashed_int & o) {
        return hashed_int((h1 * o.h1) % MOD1, (h2 * o.h2) % MOD2, (h3 * o.h3) % MOD3);
    }
};

#define COST first
#define NODE second
#define NODE1 second.first
#define NODE2 second.second

const ll oo = 1LL << 40;

ll n, m, s, t, xi, yi, ci, ds[MAXN], dt[MAXN];
hashed_int ws[MAXN], wt[MAXN];
vector<pii> g0[MAXN], gt[MAXN];
vector<edge> edges;

void dijkstra(int start, vector<pii> g[], ll dist[], hashed_int ways[]) {
    for (int i = 1; i <= n; i++)
        dist[i] = oo;
    priority_queue<edge, vector<edge>, greater<edge> > q;
    
    // be careful, this code assumes 0 is a sentinel node
    // i.e nodes go from 1 to n
    q.push(edge(0, pii(0, start)));
    ways[0] = hashed_int(1);
    while (!q.empty()) {
        edge e = q.top();
        q.pop();
        ll x = e.NODE1;
        ll y = e.NODE2;
        ll c = e.COST;
        
        if (dist[y] != oo) {
            if (dist[y] == c)
                ways[y] = ways[y] + ways[x];
            continue;
        }
            
        dist[y] = c;
        ways[y] = ways[x];
        
        for (int i = 0; i < (int)g[y].size(); i++) {
            ll z = g[y][i].NODE;
            ll cost = g[y][i].COST;
            q.push(edge(dist[y]+cost, pii(y, z)));
        }
    }
}


int main() {
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        cin >> xi >> yi >> ci;
        g0[xi].push_back(pii(ci, yi));
        gt[yi].push_back(pii(ci, xi));
        edges.push_back(edge(ci, pii(xi, yi)));
    }
    
    dijkstra(s, g0, ds, ws);
    dijkstra(t, gt, dt, wt);
    //for (int i = 1; i <= n; i++)
        //cout << i << " " << ds[i] << "(" << ws[i] <<  ")" << " " << dt[i] << "(" << wt[i] << ")" << endl;
    
    for (int i = 0; i < (int)edges.size(); i++) {
        //cout << edges[i].COST << " " << edges[i].NODE1 << " " << edges[i].NODE2 << endl;
        ll v = edges[i].NODE1;
        ll w = edges[i].NODE2;
        ll cost = edges[i].COST;
        if (ds[v] + cost + dt[w] == ds[t]) {
            if (ws[v] * wt[w] == ws[t])
                cout << "YES" << endl;
            else if (cost > 1)
                cout << "CAN " << 1 << endl;
            else
                cout << "NO" << endl;
        }
        else if(ds[v] + 1 + dt[w] < ds[t])
            cout << "CAN " << ds[v] + cost + dt[w] - ds[t] + 1 << endl;
        else
            cout << "NO" << endl;
    }
}
