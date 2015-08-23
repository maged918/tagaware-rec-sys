//Language: GNU C++11


//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>

using namespace std;

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;
typedef vector<LL> VL;
typedef vector<VL> VVL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL INF = 1e15;
const LL MOD = 1e9+7;

LL powm(LL a, LL b){
  return (b==0?1: powm(a*a%MOD, b/2)*(b%2?a:1)%MOD);
}

LL inv(LL a){
  return powm(a, MOD-2);
}

struct Edge{
  int from, to, cost, num;

  Edge(){}
  Edge(int f, int t, int c, int n): from(f), to(t), cost(c), num(n)
  {}
  bool operator>(const Edge& rhs) const{
	return cost > rhs.cost;
  }
};
typedef vector< vector<Edge> > Graph;
void add_edge(Graph& graph, int u, int v, int cost, int n){
  graph[u].push_back(Edge(u,v,cost,n));
}

void Dijkstra(const Graph& edges, VL& d, int s){
  const int V = edges.size();
  priority_queue<PLL, vector<PLL>, greater<PLL> > pq;
  REP(i,V) d[i] = INF;
  d[s] = 0;
  pq.push(MP(0,s));

  while(!pq.empty()){
	PLL pii = pq.top(); pq.pop();
	int v = pii.second;
	if(d[v] < pii.first) continue;
	for(int i=0;i<edges[v].size();++i){
	  const Edge& e = edges[v][i];
	  LL nc = d[v] + e.cost;
	  if(d[e.to] > nc){
		d[e.to] = nc;
		pq.push(MP(nc, e.to));
	  }
	}
  }
}

void Dijkstra_(const Graph& edges, VL& x, int s){
  const int V = edges.size();
  priority_queue<PLL, vector<PLL>, greater<PLL> > pq;
  VL d(V, INF);
  d[s] = 0;
  REP(i,V) x[i] = 0;
  x[s] = 1;
  pq.push(MP(0,s));

  while(!pq.empty()){
	PLL pii = pq.top(); pq.pop();
	int v = pii.second;
	if(d[v] < pii.first) continue;
	for(int i=0;i<edges[v].size();++i){
	  const Edge& e = edges[v][i];
	  LL nc = d[v] + e.cost;
	  if(d[e.to] > nc){
		d[e.to] = nc;
		pq.push(MP(nc, e.to));
	  }
	  x[e.to] = (x[e.to] + x[v]*inv(SZ(edges[v]))%MOD)%MOD;
	}
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int V, E, S, T; cin >> V >> E >> S >> T;
  vector<Edge> ve(E);
  Graph G(V), rG(V);
  --S; --T;
  REP(i,E){
	int a, b, l; cin >> a >> b >> l;
	--a, --b;
	add_edge(G, a, b, l, i);
	add_edge(rG, b, a, l, i);
	ve[i].from = a;
	ve[i].to = b;
	ve[i].cost = l;
  }

  VL d(V), rd(V);
  Dijkstra(G, d, S);
  Dijkstra(rG, rd, T);

  Graph G_(V);
  REP(i,E){
	int u = ve[i].from, v = ve[i].to, c = ve[i].cost;
	if(d[u] + c + rd[v] == d[T]) add_edge(G_, u, v, c, i);
  }
  VL x(V);
  Dijkstra_(G_, x, S);

  REP(i,E){
  	int u = ve[i].from, v = ve[i].to, c = ve[i].cost;
	if(SZ(G_[u]) == 1 && d[u]+c+rd[v] == d[T] && x[u] == 1 && x[v] == 1)
	  cout << "YES" << endl;
	else if(d[u] + rd[v] + 1 >= d[T])
	  cout << "NO" << endl;
	else
	  cout << "CAN " << (d[u] + rd[v] + c - d[T] + 1) << endl;
  }
  
  return 0;
}
