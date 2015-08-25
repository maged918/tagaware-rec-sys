//Language: GNU C++


#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <numeric>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file "a"

const ll inf = (ll)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);

struct edge {
    int a, b, c;
    edge(){}

    edge(int _a, int _b, int _c){
        a = _a;
        b = _b;
        c = _c;
    }
};

int n, m, s, t;
edge e[100100];
vector < int > g[100100];
vector < int > gr[100100];
ll ans[100100];

int getTo(int id, int u){
    if ( e[id].a == u ) return e[id].b;
    return e[id].a;
}

int getCost(int id){
    return e[id].c;
}

vector < ll >  djsk(int s, bool ok){
    vector < ll > d(n+1);
    for (int i=1;i<=n;i++){
        d[i] = inf; 
    }

    d[s] = 0;
    priority_queue < pair < ll, int >, vector < pair < ll, int > >, greater < pair < ll, int > > > pq;
    pq.push(mp(d[s], s));

    while(!pq.empty()){
        pair < ll, int > temp = pq.top(); pq.pop();
        ll val = temp.f;
        int u = temp.s;
        if ( val > d[u] ) continue;
        vector < int > gg = g[u];
        if ( ok ) gg = gr[u];
        forit(it, gg){
            int id = *it;
            int to = getTo(id, u);
            int cost = e[id].c;
            if ( d[u] + cost < d[to]){
                d[to] = d[u] + cost;
                pq.push(mp(d[to], to));
            }
        }   
    }   
    return d;
}

bool vis[100100];
int timer = 0;
int tin[100100], fup[100100];
bool used[100100];
bool isBridge[100100];
map < pii, int > M;

void addBridge(int id){
    int a = e[id].a;
    int b = e[id].b;
    if ( M[mp(a, b)] == 1 ) isBridge[id] = true;                
}

void dfs(int v, int p = -1){
    used[v] = true;     
    tin[v] = fup[v] = timer++;

    forit(it, g[v]){
        int id = *it;
        if ( !vis[id] ) continue;
        int to = getTo(id, v);
        if ( to == p ) continue;
        if ( used[to] ) fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if ( fup[to] > tin[v] ){
                addBridge(id);                                                                  
            }
        }   
    }

    forit(it, gr[v]){
        int id = *it;
        if ( !vis[id] ) continue;
        int to = getTo(id, v);
        if ( to == p ) continue;
        if ( used[to] ) fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if ( fup[to] > tin[v] ){
                addBridge(id);                                                                  
            }
        }   
    }

}

int main () {
    #ifdef LOCAL
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);
    #endif

    scanf("%d%d%d%d", &n, &m, &s, &t);

    for (int i=0;i<m;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[i] = edge(a, b, c);
        g[a].pb(i);
        gr[b].pb(i);
    }

    vector < ll > ds = djsk(s, false);
    vector < ll > dt = djsk(t, true);


    for (int i=0;i<m;i++){
        int a = e[i].a;
        int b = e[i].b;
        int c = e[i].c;

        if ( ds[a] + c + dt[b] == ds[t] )
            vis[i] = true;
    }

    for (int i=0;i<m;i++){
        if ( vis[i] ){
            M[mp(e[i].a, e[i].b)]++;
            M[mp(e[i].b, e[i].a)]++;
        }
    }


    dfs(s);

    ll total = ds[t];

    for (int i=0;i<m;i++){
        int a = e[i].a;
        int b = e[i].b;
        int c = e[i].c;
        ans[i] = inf;
        if (  total - 1 - ds[a] - dt[b] > 0){
            ans[i] = c - (total - 1 - ds[a] - dt[b]);
        }
    }

    for (int i=0;i<m;i++){
        if ( isBridge[i] ){
            printf("YES\n");
        }
        else if ( ans[i] == inf ){
            printf("NO\n");
        }
        else {
            cout <<"CAN "<<ans[i]<<endl;
        }
    }



    #ifdef LOCAL
    cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}




