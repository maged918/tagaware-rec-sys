//Language: GNU C++11


#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 500001;
int N, M;
char let[MAXN];
vector<int> adj[MAXN];
int dep[MAXN];
int R[MAXN][2], idx = 0;
vector<int> A[MAXN][26]; //A[depth][letter] holds all nodes with those conditions

void dfs(int cur)
{
	R[cur][0] = ++idx;
	A[dep[cur]][let[cur] - 'a'].push_back(R[cur][0]);
	for (int i = 0; i < adj[cur].size(); i++)
		dfs(adj[cur][i]);
	R[cur][1] = idx;
}

int main()
{
	scanf("%d %d", &N, &M);
	dep[1] = 1;
	for (int i = 2, p; i <= N; i++)
	{
		scanf("%d", &p);
		adj[p].push_back(i);
		dep[i] = dep[p] + 1;
	}

	scanf(" %s", let + 1);
	dfs(1);

	for (int i = 0, v, h; i < M; i++)
	{
		scanf("%d %d", &v, &h);
		
		if (dep[v] >= h) //empty palindrome or 1 letter palindrome
		{
			printf("Yes\n");
			continue;
		}

		int cnt = 0;
		for (int j = 0; j < 26 && cnt < 2; j++)
		{
			int num = upper_bound(A[h][j].begin(), A[h][j].end(), R[v][1]) - lower_bound(A[h][j].begin(), A[h][j].end(), R[v][0]);
			cnt += (num % 2 == 1);
		}
		
		if (cnt < 2)
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}