//Language: GNU C++




#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define LL long long 
#define ULL unsigned long long
#define MID(x, y) (((x) + (y)) >> 1)

using namespace std;

const int inf = 0x3f3f3f3f;
const LL INF = 1e18;

const int N = 121234;

int n;

int cnt[N];
int ans[N];

void dfs(int x, int fa, int num)
{
	cnt[x]++;
	ans[x] += num;
	if (x * 2 < N && x * 2 != fa) dfs(x * 2, x, num + 1);
	if (x / 2 > 0 && x / 2 != fa) dfs(x / 2, x, num + 1);
}
int main()
{
	while (cin >> n)
	{
		int i, j, x;
		for (i = 0; i < n; ++i)
		{
			cin >> x;
			dfs(x, -1, 0);
		}
		int res = inf;
		for (i = 0; i < N; ++i)
		{
			if (cnt[i] == n) res = min(res, ans[i]);
		}
		cout << res << endl;
	}
}