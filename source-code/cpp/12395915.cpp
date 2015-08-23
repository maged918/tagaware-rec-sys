//Language: GNU C++


#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <cctype>
#include <utility>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define endl '\n'
#define cpy(a,e) memcpy(a,e,sizeof(e))
#define clr(a,e) memset(a,e,sizeof(a))
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define repd(i,n) for (int (i)=(n)-1;(i)>=0;i--)
#define reps(i,s,e) for (int (i)=(s);(i)<=(e);i++)
#define repds(i,s,e) for (int (i)=(s);(i)>=(e);i--)

const long long MOD= 479001599LL,INF=1e14;;
int n,m,s,t;
long long froms[100055],fromt[100055],dps[100055],dpt[100055];
bool used[100055];

struct edgeset {
    int from,to;long long cost;
    edgeset(int from,int to,long long cost):from(from),to(to),cost(cost){}
};

vector<edgeset> e;

struct edge {
    int to;long long cost;
    edge(int to,long long cost):to(to),cost(cost){}
};

vector<edge> g[100055],rg[100055];

struct node {
    int u;long long key;
    node(int u,long long key):u(u),key(key){}
};
struct compare {
    bool operator() (node u,node v) {
        return u.key>v.key;
    }
};

void dijk(int source,vector<edge> *vec,long long *d,long long *dp) {
    fill(d+1,d+n+1,INF);
    clr(used,0);
    priority_queue<node,vector<node>,compare> pq;
    dp[source]=1LL;
    d[source]=0LL;
    pq.push(node(source,0LL));
    while (!pq.empty()) {
        node v=pq.top();pq.pop();
        if (used[v.u]) continue;
        used[v.u]=1;
        rep(i,vec[v.u].size()) {
            edge ed=vec[v.u][i];
            if (d[ed.to]>d[v.u]+ed.cost) {
                d[ed.to]=d[v.u]+ed.cost;
                dp[ed.to]=dp[v.u];
                pq.push(node(ed.to,d[ed.to]));
            } else if (d[ed.to]==d[v.u]+ed.cost) { 
                dp[ed.to]=(dp[ed.to]+dp[v.u])%MOD;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> t;
    int x,y;long long z;
    rep(i,m) {
        cin >> x >> y >> z;
        g[x].pb(edge(y,z));
        rg[y].pb(edge(x,z));
        e.pb(edgeset(x,y,z));
    }
    dijk(s,g,froms,dps);
    dijk(t,rg,fromt,dpt);
    long long first=froms[t];
    long long tot=dps[t];
    rep(i,m) {
        int from=e[i].from,to=e[i].to;
        long long cost=e[i].cost;
        long long sum=froms[from]+fromt[to]+cost;
        if (sum==first&&((dps[from]*dpt[to])%MOD==(tot)%MOD)) {
            cout << "YES" << endl;
        } else if ((sum-first+1LL)<cost) {
            cout << "CAN " << sum-first+1LL << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}