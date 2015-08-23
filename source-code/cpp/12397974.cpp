//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define FOR(i,a,b) for(int i = (a), _b = (b); i <= _b; ++i)
#define REP(i,a) for(int i = 0, _a = (a); i < _a; ++i)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const ll MOD = 1e9 + 37;

struct Hash {
    ll x, y;
    Hash(ll x = 0, ll y = 0) : x(x), y(y) {}

    Hash operator + (const Hash& a) const {
        return Hash(x + a.x, (y + a.y) % MOD);
    }
    Hash operator * (const Hash& a) const {
        return Hash(x * a.x, y * a.y % MOD);
    }
};

bool operator == (const Hash& a, const Hash& b) {
    return a.x == b.x && a.y == b.y;
}

int n, m, s, t, eu[N], ev[N], ec[N];
vector<pii> ke[2][N];
ll d[2][N];
Hash f[2][N];

void dijkstra(int start, int idx) {
    set<pair<ll, int> > q;
    FOR(i,1,n) d[idx][i] = 1E18;
    d[idx][start] = 0;
    f[idx][start] = Hash(1, 1);
    q.insert(make_pair(0, start));

    while (!q.empty()) {
        ll du = q.begin()->first; int u = q.begin()->second;
        q.erase(q.begin());
        if (du != d[idx][u]) continue;

        REP(i,ke[idx][u].size() ) {
            int v = ke[idx][u][i].first, c = ke[idx][u][i].second;
            if (d[idx][v] >= d[idx][u] + c) {
                if (d[idx][v] > d[idx][u] + c) {
                    d[idx][v] = d[idx][u] + c;
                    f[idx][v] = f[idx][u];
                    q.insert(make_pair(d[idx][v], v) );
                } else f[idx][v] = f[idx][v] + f[idx][u];
            }
        }

    }
}

int main() {
    ios_base :: sync_with_stdio(0);
    //freopen("test.inp", "r", stdin);
    cin >> n >> m >> s >> t;
    FOR(i,1,m) {
        int u, v, c;
        cin >> u >> v >> c;
        ke[0][u].push_back(pii(v, c));
        ke[1][v].push_back(pii(u, c));
        eu[i] = u; ev[i] = v; ec[i] = c;
    }

    dijkstra(s, 0);
    dijkstra(t, 1);

    FOR(i,1,m) {
        int u = eu[i], v = ev[i], c = ec[i];
        if (d[0][u] + c + d[1][v] == d[0][t]) {
            if (f[0][u] * f[1][v] == f[0][t]) cout << "YES\n";
            else if (c>1) cout << "CAN 1\n";
            else cout << "NO\n";
        } else {
            ll need = d[0][u] + c + d[1][v] - d[0][t] + 1;
            if (c > need) cout << "CAN " << need << "\n";
            else cout << "NO\n";
        }
    }
}
