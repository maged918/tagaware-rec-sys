//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define mp make_pair

using namespace std;
typedef long long ll;

const int maxn = 100003;
const ll inf = (ll)1e12;
vector<pair<int, int> > g[maxn], gt[maxn], gd[maxn];
vector<pair< pair<int, int>, int> > in;
map<pair<pair<int, int>, int>, int> ed;
ll d1[maxn], d2[maxn];
int tin[maxn], up[maxn];
bool vis[maxn], ans[maxn];
int n, m, t;

void dfs(int v, int p = -1){
	vis[v] = true;
	tin[v] = up[v] = t++;
	for (int i = 0; i < (int)gd[v].size(); ++i){
		int u = gd[v][i].first;
		int idx = gd[v][i].second;
		if (u == p) continue;
		if (vis[u]){
			up[v] = min(tin[u], up[v]);
		}
		else{
			dfs(u, v);
			up[v] = min(up[u], up[v]);
			if (up[u] > tin[v] && ed[mp(in[idx].first, in[idx].second)] == 1) ans[idx] = true;
		}
	}
}

void path(ll *d, int s, int t, vector<pair<int, int> > *r){
	set<pair<ll, int> > q;
	for (int i = 0; i < n; ++i) d[i] = inf;
	d[s] = 0;
	q.insert(mp(d[s], s));
	while (!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		for (int i = 0; i < (int)r[v].size(); ++i){
			int u = r[v][i].first, len = r[v][i].second;
			if (d[v] + len < d[u]){
				q.erase(mp(d[u], u));
				d[u] = d[v] + len;
				q.insert(mp(d[u], u));
			}
		}
	}
}



int main(){
	int s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t); --s, --t;
	for (int i = 0; i < m; ++i){
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l); 
		--a, --b;
		ed[mp(mp(a, b), l)] += 1;
		g[a].push_back(mp(b, l));
		gt[b].push_back(mp(a, l));
		in.push_back(mp(mp(a, b), l));
	}
	path(d1, s, t, g);
	path(d2, t, s, gt);
	ll best = d1[t];
	for (int i = 0; i < m; ++i){
		int a = in[i].first.first, b = in[i].first.second, len = in[i].second;
		if (d1[a] + len + d2[b] == best){
			gd[a].push_back(mp(b, i));
			gd[b].push_back(mp(a, i));
		}
	}
	dfs(s);
	for (int i = 0; i < m; ++i){
		if (ans[i]) puts("YES");
		else {
			int a = in[i].first.first, b = in[i].first.second;
			ll len = in[i].second;
			ll nlen = best - 1 - d1[a] - d2[b];
			if (nlen > 0)
				printf("CAN %d\n", len - nlen);
			else
				puts("NO");
		}
	}
	return 0;
}