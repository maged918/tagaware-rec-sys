//Language: GNU C++


#include <iostream>
#include <queue>
using namespace std;

#define HASHES 2

const int MAXN = 100005;
struct Edge{
    int u, v, c;
}edges[MAXN];

typedef long long ll;
ll HA[] = {1e9 + 7, 1e9 + 9};
typedef pair<ll, int> pi;

vector<pi> E[MAXN], E2[MAXN];

ll dist[MAXN], rev_dist[MAXN];

ll ways[MAXN][2], rev_ways[MAXN][2];


void add(int to, int from, bool clean){

    for(int j = 0; j < HASHES; j++){

        if(clean) ways[to][j] = 0;

        ways[to][j] += ways[from][j];
        ways[to][j] %= HA[j];
    }
}

void add_rev(int to, int from, bool clean){

    for(int j = 0; j < HASHES; j++){

        if(clean) rev_ways[to][j] = 0;

        rev_ways[to][j] += rev_ways[from][j];
        rev_ways[to][j] %= HA[j];
    }
}


void dij(int source){

    priority_queue< pi, vector<pi> > Q;

    for(int i = 1; i < MAXN; i++) dist[i] = (1LL << 62);
    dist[source] = 0;
    ways[source][0] = ways[source][1] = 1;

    Q.push( make_pair(0, source) );
    while(!Q.empty()){

        int vertex = Q.top().second;
        ll d = -Q.top().first;

        Q.pop();
        if( dist[vertex] < d) continue;

   //     cout << "PROCESSING " << vertex << " " << d << endl;

        for(int i = 0 ; i < E[vertex].size(); i++){

            int to = E[vertex][i].first;
            int cost = E[vertex][i].second;

            if( dist[vertex] + cost < dist[to] ){
                dist[to] = dist[vertex] + cost;
                add(to, vertex, true);

     //           cout << "QUEUED " << to << " WAYS DAD = " << ways[vertex][0] << endl;

                Q.push( make_pair( -dist[to], to) );
            }else{

                if(dist[vertex] + cost == dist[to])
                    add(to, vertex, false);

            }
        }
    }
}

void rev_dij(int source){

    for(int i = 1; i < MAXN; i++) rev_dist[i] = (1LL << 62);
    priority_queue< pi, vector<pi> > Q;

    rev_dist[source] = 0;
    rev_ways[source][0] = rev_ways[source][1] = 1;

    Q.push( make_pair(0, source) );
    while(!Q.empty()){

        int vertex = Q.top().second;
        ll d = -Q.top().first;
        Q.pop();
        if( rev_dist[vertex] < d) continue;

        for(int i = 0 ; i < E2[vertex].size(); i++){

            int to = E2[vertex][i].first;
            int cost = E2[vertex][i].second;

            if( rev_dist[vertex] + cost < rev_dist[to] ){
                rev_dist[to] = rev_dist[vertex] + cost;

                add_rev(to, vertex, true);

                Q.push( make_pair( -rev_dist[to], to) );
            }else{

                if(rev_dist[vertex] + cost == rev_dist[to])
                    add_rev(to, vertex, false);

            }
        }
    }

}

int main()
{

    int n , m , s, t; cin >> n >> m >> s >> t;

    for(int i = 0 ; i < m ; i++){

        cin >> edges[i].u >> edges[i].v >> edges[i].c;

        int from = edges[i].u;
        int to = edges[i].v;
        int cost = edges[i].c;

        E[from].push_back( make_pair(to, cost) );
        E2[to].push_back( make_pair(from, cost) );
    }

    dij(s);
    rev_dij(t);


    for(int i = 0; i < m; i++){

        int u = edges[i].u;
        int v = edges[i].v;
        int c = edges[i].c;

        ll tot = dist[u] + c + rev_dist[v];

       // cout << i << " " << tot << " " << dist[t] << endl;

        if(tot == dist[t]){

            bool ok = true;
            for(int j = 0; j < HASHES; j++){
                ll product = ways[u][j] * rev_ways[v][j];
                product %= HA[j];

   //             cout << i << " " << product << " " << ways[t][j] << endl;


                if(product != ways[t][j]) ok = false;
            }

            if(ok){
                cout << "YES" << endl;
                continue;
            }
        }

        ll needed_weight = dist[t] - dist[u] - rev_dist[v] - 1;

        ll final_weight = c - needed_weight;
        if(c - final_weight > 0) cout << "CAN " << final_weight << endl;
        else cout << "NO" << endl;

    }

    return 0;
}
