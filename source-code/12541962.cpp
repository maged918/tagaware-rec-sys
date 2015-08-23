//Language: GNU C++11


#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
using namespace std;

const int N = 500005;
vector <int> val[N];
vector <int> pos[N];
vector <int> v[N];
int tot, n, m, a[N], l[N], r[N];

void dfs(int x, int h)
{
	int y;

	l[x] = tot + 1;
	for(int i = 0; i < v[x].size(); i++)
	{
		y = v[x][i];
		dfs(y, h + 1);
	}
	r[x] = ++tot;
	if(!pos[h].size())
	{
		pos[h].push_back(0);
		val[h].push_back(0);
	}
	pos[h].push_back(tot);
	val[h].push_back(val[h].back() ^ a[x]);
}

int main() 
{
	char c;
	int vi, hi, x, y, tmp;

	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; i++)
	{
		scanf("%d", &x);
		v[x].push_back(i);
	}

	for(int i = 1; i <= n; i++)
	{
		scanf(" %c", &c);
		a[i] = 1 << (c - 'a');
	}
	
	tot = 0;
	dfs(1, 1);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d", &vi, &hi);
		if(!pos[hi].size())
		{
			puts("Yes");
			continue;
		}
		x = lower_bound(pos[hi].begin(), pos[hi].end(), l[vi]) - pos[hi].begin() - 1;
		y = upper_bound(pos[hi].begin(), pos[hi].end(), r[vi]) - pos[hi].begin() - 1;
		tmp = val[hi][y] ^ val[hi][x];
		if(tmp == (tmp & (-tmp))) puts("Yes");
		else puts("No");
	}

	return 0;
}
