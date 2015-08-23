//Language: GNU C++11


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
const ll INF = 1e15;
const int MAXN = 100001;

int n, m;
int s, t;
int partenza[MAXN], arrivo[MAXN];
ll lunghezza[MAXN];
bool ponte[MAXN];

vector<int> adj[MAXN];
vector<ll> lun[MAXN];

ll dis[MAXN];
ll dit[MAXN];

ll dist[MAXN];
struct info{ll di; int v; info(ll d, int V){di=d; v=V;}};
bool operator < (info a, info b){return a.di > b.di;}
priority_queue<info> pq;
void djk(int s){
	for(int i=1; i<=n; i++) dist[i] = INF;
	dist[s] = 0;
	pq.push(info(0,s));
	while(!pq.empty()){
		info f = pq.top(); pq.pop();
		int v = f.v;
		ll di = f.di;
		if(di != dist[v]) continue;
		for(int i=0; i<(int)adj[v].size(); i++){
			int u = adj[v][i];
			ll l = lun[v][i];
			if(dist[u] > di + l){
				dist[u] = di+l;
				pq.push(info(dist[u],u));
			}
		}
	}
}

int conta;
int num[MAXN], low[MAXN];
void dfs(int v, int p){
	conta++;
	num[v] = low[v] = conta;
	bool padre = true;
	for(int i=0; i<(int)adj[v].size(); i++){
		int u = adj[v][i];
		if(u == p && padre){
			padre = false;
			continue;
		}
		if(num[u]) low[v] = min(low[v], num[u]);
		else{
			dfs(u,v);
			low[v] = min(low[v], low[u]);
		}
		
		if(low[u] > num[v]) ponte[lun[v][i]] = true;
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s >> t;
	for(int i=1; i<=m; i++){
		cin >> partenza[i] >> arrivo[i] >> lunghezza[i];
		adj[partenza[i]].push_back(arrivo[i]);
		lun[partenza[i]].push_back(lunghezza[i]);
	}
	
	djk(s);
	for(int i=1; i<=n; i++) dis[i] = dist[i];
	
	for(int i=1; i<=n; i++){adj[i].clear(); lun[i].clear();}
	for(int i=1; i<=m; i++){
		adj[arrivo[i]].push_back(partenza[i]);
		lun[arrivo[i]].push_back(lunghezza[i]);
	}
	
	djk(t);
	for(int i=1; i<=n; i++) dit[i] = dist[i];
	
	//~ assert(dis[t] < INF && dit[s] < INF);
	
	for(int i=1; i<=n; i++){adj[i].clear(); lun[i].clear();}
	for(int i=1; i<=m; i++) if(dis[partenza[i]]+lunghezza[i]+dit[arrivo[i]] == dit[s]){
		adj[partenza[i]].push_back(arrivo[i]);
		adj[arrivo[i]].push_back(partenza[i]);
		lun[partenza[i]].push_back(i);
		lun[arrivo[i]].push_back(i);
	}
	
	dfs(s,0);
	for(int i=1; i<=m; i++){
		if(ponte[i]) {cout << "YES\n"; continue;}
		ll ca = dis[partenza[i]] + lunghezza[i] + dit[arrivo[i]] - dit[s] + 1;
		if(ca >= lunghezza[i]) {cout << "NO\n"; continue;}
		cout << "CAN " << ca << '\n';
	}
	return 0;
}
