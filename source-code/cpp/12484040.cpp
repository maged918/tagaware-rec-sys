//Language: GNU C++


#include <bits/stdc++.h>
#define mp  make_pair
#define pb  push_back
#define eps 1e-9
#define iseq(a,b) (fabs(a-b)<eps)
#define readfiles freopen("in.in","r",stdin), freopen("out.out","w",stdout);
#define readfile freopen("in.in","r",stdin);
#define fastio ios::sync_with_stdio(false);
#define sc(x) scanf("%d",x)

#define valid(i, t) (0 <= (i) && (i) < (t))
#define OO 0x7fffffff7fffffff
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector< int> vi;
typedef vector< vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi > vpi;
typedef vector< vpi> vvpi;


#define MOD 1000000007
#define MAX 100009
#define OF 
#define UNVISITED -1

vpi vec[MAX];
vpi rev[MAX];
vpi spg[MAX];


ll d1[MAX];
ll d2[MAX];

set<pair<int, ll> > edges[MAX];

bool ch_edges = 1;
map<pair<pi, int >, int> cn;

void dij(int s, int t, vpi g[], ll d[]) {
    priority_queue<pair<ll, int> > pq;
    pq.push(mp(0, s));

    d[s] = 0;
    int v, nv;
    ll curd, nd;
    while (!pq.empty()) {
        curd = -pq.top().first;
        v = pq.top().second;
        pq.pop();
        if (curd > d[v])
            continue;


        for (int i = 0; i < g[v].size(); i++) {
            nv = g[v][i].first;
            nd = g[v][i].second;

            if (d[v] + nd < d[nv]) {
                pq.push(mp(-d[v] - nd, nv));
                d[nv] = d[v] + nd;
                if (ch_edges) {
                    edges[nv].clear();
                    edges[nv].insert(mp(v, nd));
                    //cn[mp(v,nv)]++;

                }
            } else if (d[v] + nd == d[nv] && ch_edges) {

                if (ch_edges)
                    edges[nv].insert(mp(v, nd)); //cn[mp(v,nv)]++;
            }
        }



    }
}

vi dfs_parent, dfs_num, dfs_low;
int dfsNumberCounter, dfsRoot, rootChildren;

vpi input_;

map<pi, string> stat;
map<pi, int > val;

map<pi, int> mn;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (int j = 0; j < (int) spg[u].size(); j++) {
        pi v = spg[u][j];
        if (dfs_num[v.first] == UNVISITED) {
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++;
            articulationPointAndBridge(v.first);

            if (dfs_low[v.first] > dfs_num[u])
                stat[mp(u, v.first)] = "YES", stat[mp(v.first, u)] = "YES";
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        } else if (v.first != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }
}
ll L[MAX];

int main(int argc, char** argv) {

#ifndef ONLINE_JUDGE
    readfile;
#endif

    for (int i = 0; i < MAX; i++)
        d1[i] = d2[i] = OO;

    int n, m, s, t, a, b, l;
    cin >> n >> m >> s>>t;
    for (int i = 0; i < m; i++) {
        cin >> a >> b>>l;

        input_.pb(mp(a, b));
        L[i] = l;
        cn[mp(input_[i], l)]++;
        if (mn[input_[i]])
            mn[input_[i]] = min(mn[input_[i]], l);
        else
            mn[input_[i]] = l;


        vec[a].pb(mp(b, l));
        rev[b].pb(mp(a, l));

    }

    dij(s, t, vec, d1);
    ch_edges = 0;
    dij(t, s, rev, d2);
#ifndef ONLINE_JUDGE
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << d1[i] << '\n';

    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ' ' << d2[i] << '\n';

    }
    cout << endl;

    cout << "edges :\n";
#endif
    set<pair<int, ll> >::iterator it;
    for (int i = 0; i < MAX; i++) {

        for (it = edges[i].begin(); it != edges[i].end(); it++) {
#ifndef ONLINE_JUDGE
            cout << i << ' ' << it->first << endl;
#endif
            ll dd = it->second;
            if (d1[it->first] + d2[i] + dd == d1[t]) {
                spg[i].pb(mp(it->first, 0));
                spg[it->first].pb(mp(i, 0));
            }

        }

    }
#ifndef ONLINE_JUDGE
    for (int i = 0; i <= n; i++) {
        cout << i << " : ";
        for (int j = 0; j < spg[i].size(); j++) {
            cout << spg[i][j].first << ' ';

        }
        cout << endl;

    }
#endif

    dfsNumberCounter = 0;
    dfs_num.assign(MAX, UNVISITED);
    dfs_low.assign(MAX, 0);
    dfs_parent.assign(MAX, 0);

    for (int i = 0; i < MAX; i++) {
        if (dfs_num[i] == UNVISITED) {
            dfsRoot = i;
            rootChildren = 0;
            articulationPointAndBridge(i);
        }
    }

    int sol[MAX];
    memset(sol, -1, sizeof sol);
    for (int i = 0; i < m; i++) {
        if (stat[input_[i]] == "YES" && L[i] == mn[input_[i]] && cn[mp(input_[i], mn[input_[i]])] == 1 && (d1[input_[i].first] + d2[input_[i].second] + L[i] == d1[t]))
            continue;
        ll temp = d1[t]-(d1[input_[i].first] + d2[input_[i].second]) - 1;
        if (L[i] - temp > 0 && temp > 0)
            sol[i] = L[i] - temp;
        else
            sol[i] = 0;

    }
    string ss;
    for (int i = 0; i < m; i++) {
        if (!sol[i])
            cout << "NO\n";
        else if (sol[i] == -1)
            cout << "YES\n";
        else
            cout << "CAN " << sol[i] << endl;


        continue;
        ss = stat[input_[i]];
        cout << ss;
        if (ss == "CAN")
            cout << ' ' << val[input_[i]];
        cout << endl;
    }


    return 0;
}