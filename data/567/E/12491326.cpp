//Language: GNU C++


#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

const int maxn = 100010;
const ll INF = 1e12, mod = 1e9+13;

int n, m;
ll s, t, u, v, w;

inline ll input() {
	ll a=0;
	char c=getchar();
	for(; c<'0' || c>'9'; c=getchar());
	for(; c >= '0' && c <= '9'; c=getchar()) a=(a<<3)+(a<<1)+(c-'0');
	return a;
}

struct edge {
	ll from, to, cost;
	edge(ll from, ll to, ll cost): from(from), to(to), cost(cost) {}
};

struct dijkstra {
	ll c[2][maxn], d[2][maxn];
	vector <edge> es[2];
	vector <int> G[2][maxn];
	void addedge(ll u, ll v, ll w) {
		G[0][u].push_back(es[0].size());
		es[0].push_back(edge(u, v, w));
		G[1][v].push_back(es[1].size());
		es[1].push_back(edge(v, u, w));
	}
	void solve(int o, ll s) {
		for(int i=1; i <= n; i++) c[o][i]=0;		
		c[o][s]=1;
		for(int i=1; i <= n; i++) d[o][i]=INF;		
		d[o][s]=0;		
		priority_queue < p, vector<p>, greater<p> > pq;
		pq.push(p(0, s));		
		while(!pq.empty()) {					
			p node=pq.top();
			pq.pop();	
			ll dist=node.first, u=node.second; 
			if(dist>d[o][u]) continue;
			for(int i=0; i<G[o][u].size(); i++) {
				edge& e=es[o][G[o][u][i]];
				if(d[o][e.to] == dist+e.cost) c[o][e.to]=(c[o][e.to]+c[o][u])%mod; 
				if(d[o][e.to]>dist+e.cost) {
					c[o][e.to]=c[o][u];
					d[o][e.to]=dist+e.cost;
					pq.push(p(d[o][e.to], e.to));
				}
			}
		}		
	}
}d;

int main() {
	scanf("%d%d%I64d%I64d", &n, &m, &s, &t);
	for(int i=0; i<m; i++) {
		u=input(); v=input(); w=input();
		d.addedge(u, v, w);
	}
	d.solve(0, s);
	d.solve(1, t);
	for(int i=0; i<m; i++) {
		edge& e=d.es[0][i];
		u=e.from, v=e.to, w=e.cost;
		ll d1=d.d[0][u], d2=d.d[1][v], dt=d.d[0][t]; 
		ll c1=d.c[0][u], c2=d.c[1][v], ct=d.c[0][t];
		if(d1+d2+w == dt && (c1*c2)%mod == ct) puts("YES");
		else {
			ll exp=dt-d1-d2-1;
			if(exp<1 || w == 1) puts("NO");
			else printf("CAN %I64d\n", w-exp);
		}
	}
	return 0;
}
					    	    		   	  			     	