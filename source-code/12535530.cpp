//Language: GNU C++11


/*/**/

#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 21;

char s[N];
int in[N], out[N], two[32], t = 0;
vector < int > adj[N];
vector < pair < int, int > > d[N];

void dfs(int node, int dep) {
	in[node] = ++t;
	d[dep].push_back(make_pair(t, d[dep].back().second ^ two[s[node] - 'a']));
	for(int i = 0; i < adj[node].size(); i++) {
		dfs(adj[node][i], dep + 1);
	}
	out[node] = ++t;
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i = 0; i < 30; i++) {
		two[i] = 1 << i;
	}
	for(int i = 1; i <= n; i++) {
		d[i].resize(1);
	}
	for(int i = 2; i <= n; i++) {
		int p;
		scanf("%d", &p);
		adj[p].push_back(i);
	}
	scanf("%s", s + 1);
	dfs(1, 1);
	while(q--) {
		int u, dep;
		scanf("%d%d", &u, &dep);
		int left = lower_bound(d[dep].begin(), d[dep].end(), make_pair(in[u], -1)) - d[dep].begin() - 1;
		int right = lower_bound(d[dep].begin(), d[dep].end(), make_pair(out[u], -1)) - d[dep].begin() - 1;
		int alpha = d[dep][left].second ^ d[dep][right].second;
		alpha -= alpha & -alpha;
		if(alpha) {
			puts("No");
		}
		else {
			puts("Yes");
		}
	}
	return 0;
}
