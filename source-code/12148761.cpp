//Language: GNU C++


#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int E[MAXN], F[MAXN];
bool vis[MAXN];

void solve(int X, int C)
{
	if(X > MAXN - 1) return;
	if(vis[X]) return;
	F[X] += C;
	E[X]++;
	vis[X] = true;
	solve(X / 2, C + 1);
	solve(X * 2, C + 1);
	return;
}

int main() 
{
	int N, tmp, ANS = INT_MAX;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		memset(vis, false, sizeof(vis));
		solve(tmp, 0);
	}
	for (int i = 1; i < MAXN; i++)
		if(E[i] == N)
			if(F[i] < ANS)
				ANS = F[i];
	cout << ANS << '\n';
	return 0;
}