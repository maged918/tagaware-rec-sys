//Language: GNU C++


// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << (x) << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define rep(i,n) for (int i = 0; i < (n); i ++)
#define repd(i,n) for (int i = (n); i >= 0; i --)
#define PI 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> plli;

struct edge
{
	int from, to, cost;
	int id;
	
	edge (int _from = 0, int _to = 0, int _cost = 0, int _id = 0)
	{
		from = _from;
		to = _to;
		cost = _cost;
		id = _id;
	}
};

const int max_n = 100*1000;
vector <edge> adj [max_n];
edge E [max_n];
bool vis [max_n];
priority_queue <plli, vector<plli>, std::greater<plli> > Q;
bool ans [max_n];
vector <edge> tmp;
const ll inf = 1e15;

void fill_adj (int n, int m)
{
	rep (i, n)
		adj[i].clear();
	rep (i, m)
		adj [E[i].from].pb (E[i]);
}

void dijkstra (ll d[], int n, int source)
{
	memset (vis, false, sizeof vis);
	rep (i, n)
		d[i] = inf;
	d[source] = 0;
	Q.push (mp(0, source));
	
	while ( Q.size() )
	{
		int at = Q.top().Y;
		Q.pop();
		if ( vis[at] )
			continue;
		vis [at] = true;
		rep (i, adj[at].size())
		{
			int to = adj[at][i].to;
			ll cost = d[at] + adj[at][i].cost;
			if ( d[to] > cost )
			{
				d[to] = cost;
				Q.push (mp(cost, to));
			}
		}
	}
}

ll ds [max_n], dt [max_n];

bool cmp (const edge &a, const edge &b)
{
	return ds[a.from] < ds[b.from];
}

int main()
{
	int n, m, s, t;
	scanf ("%d%d%d%d", &n, &m, &s, &t);
	s --, t --;
	rep (i, m)
	{
		int a, b, l;
		scanf ("%d%d%d", &a, &b, &l);
		a --, b --;
		E [i] = edge (a, b, l, i);
	}
	
	fill_adj (n, m);
	dijkstra (ds, n, s);
	rep (i, m)
		swap (E[i].from, E[i].to);
	fill_adj (n, m);
	dijkstra (dt, n, t);
	rep (i, m)
		swap (E[i].from, E[i].to);

	memset (ans, false, sizeof ans);
	rep (i, m)
		if ( ds[E[i].from] + E[i].cost + dt[E[i].to] == ds[t] )
		{
			ans [i] = true;
			tmp.pb (E[i]);
		}	
		
	sort (tmp.begin(), tmp.end(), cmp);
	ll max_to = 0;
	rep (i, int(tmp.size())-1)
	{
		max_to = max (ds[tmp[i].to], max_to);
		if ( ds[tmp[i+1].from] < max_to )
		{
			ans [tmp[i].id] = false;
			ans [tmp[i+1].id] = false;
		}
	}	
	
	rep (i, m)
		if ( ans[i] )
			printf ("YES\n");
		else 
		{
			ll cost2 = ds[t]-ds[E[i].from]-dt[E[i].to]-1;
			if ( cost2 > 0 )
				printf ("CAN %d\n", int(E[i].cost-cost2));
			else
				printf ("NO\n");
		}
	
	return 0;
}
