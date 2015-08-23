//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define INFLL 10000000000000000LL
#define MEMSET_INF 127
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD 2000000007

priority_queue< pair<ll, ll>, vector< pair<ll,ll> >, greater < pair<ll,ll> > > pq; 
vii g1[100001]; 
vii g2[100001]; 
ll dist1[100001]; 
set<int> from1[100001]; 
ll dist2[100001]; 
set<int> from2[100001];



void dijkstra1(int s) { 
    while(!pq.empty())
        pq.pop();

    pq.push(mp(0, s)); 
    dist1[s] = 0; 
    while (!pq.empty()) { 
        pair<ll,ll> cur = pq.top(); 
        pq.pop(); 
        ll cd = cur.F; 
        ll cn = cur.S; 
        if (cd > dist1[cn]) continue; 
        for (int i = 0; i < g1[cn].size(); ++i) { 
            pair<ll,ll> adj = g1[cn][i]; 
            ll ad = adj.F; 
            ll an = adj.S; 
            if (cd + ad < dist1[an]) { 
                dist1[an] = cd + ad; 
                from1[an].clear();
                from1[an].insert(cn);
                pq.push(mp(cd + ad, an)); 
            } 
            else if (cd + ad == dist1[an]) { 
                from1[an].insert(cn);
            } 
        } 
    } 
}

void dijkstra2(int s) { 
    while(!pq.empty())
        pq.pop();

    pq.push(mp(0, s)); 
    dist2[s] = 0; 
    while (!pq.empty()) { 
        pair<ll,ll> cur = pq.top(); 
        pq.pop(); 
        ll cd = cur.F; 
        ll cn = cur.S; 
        if (cd > dist2[cn]) continue; 
        for (int i = 0; i < g2[cn].size(); ++i) { 
            pair<ll,ll> adj = g2[cn][i]; 
            ll ad = adj.F; 
            ll an = adj.S; 
            if (cd + ad < dist2[an]) { 
                dist2[an] = cd + ad; 
                from2[an].clear();
                from2[an].insert(cn);
                pq.push(mp(cd + ad, an)); 
            } 
            else if (cd + ad == dist2[an]) { 
                from2[an].insert(cn);
            } 
        } 
    } 
}

ll ways1[100001];
ll calcways1(int curn, int target){
    if(curn == target){
        return 1LL;
    }else if(ways1[curn] != -1){
        return ways1[curn];
    }else{
        ll ret = 0;
        for(auto it = from1[curn].begin(); it != from1[curn].end(); it++){
                ret = (ret + calcways1(*it, target))%MOD;
        }
        return ways1[curn] = ret;
    }

}

ll ways2[100001];
ll calcways2(int curn, int target){
    if(curn == target){
        return 1LL;
    }else if(ways2[curn] != -1){
        return ways2[curn];
    }else{
        ll ret = 0;
        for(auto it = from2[curn].begin(); it != from2[curn].end(); it++){
                ret = (ret + calcways2(*it, target))%MOD;
        }
        return ways2[curn] = ret;
    }

}

int main() {
    int n,m,s,t;
    vector<pair<ii, ll > > edges;
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= n; i++){
        dist1[i] = INFLL;
        dist2[i] = INFLL;
    }

    map<ii, int> minnum;
    map<ii, int> mincnt;
    for(int i = 0 ; i < m ;i++){
        int a,b, l;
        cin >> a >> b >> l;
        g1[a].pb(mp(l, b));
        g2[b].pb(mp(l, a));
        edges.pb(mp(mp(a,b), l));
        if(minnum.find(mp(a,b)) == minnum.end()){
            minnum[mp(a,b)] = l;
            mincnt[mp(a,b)] = 1;
        }else{
            int aux = minnum[mp(a,b)];
            if(aux > l){
                minnum[mp(a,b)] = l;
                mincnt[mp(a,b)] = 1;
            }else if(aux == l){
                mincnt[mp(a,b)]++;
            }
        }
    }

    dijkstra1(s);
    dijkstra2(t);

    memset(ways1, -1, sizeof ways1);
    memset(ways2, -1, sizeof ways2);
    ways1[s] = 1LL;
    ways2[t] = 1LL;
    calcways1(t,s);
    calcways2(s,t);

    ll mindist = dist1[t];

    for(int i = 0; i < edges.size(); i++){
        if(dist1[edges[i].F.F] + dist2[edges[i].F.S] + edges[i].S == mindist)   {
            int cnt = mincnt[edges[i].F];
            if( (ways1[edges[i].F.F] * ways2[edges[i].F.S])%MOD == ways1[t] and cnt == 1){
                cout << "YES" << endl; 
                //edges[i].F.F << " "  << edges[i].F.S << " " << ways1[edges[i].F.F] << " " << ways2[edges[i].F.S]  << " " << ways1[t] << endl;
            }else if(edges[i].S > 1){
                cout << "CAN 1" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if(dist1[edges[i].F.F] + dist2[edges[i].F.S] + 1 >= mindist){
            cout << "NO" << endl;
        }else if(dist1[edges[i].F.F] + dist2[edges[i].F.S] + edges[i].S > mindist){
            cout << "CAN " << dist1[edges[i].F.F] + dist2[edges[i].F.S] + edges[i].S - mindist + 1 << endl;
        }else{
            cout << "whhhattt" << endl;
        }
    }


    return 0;
}
