//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i,n) for(int i = 0;i < n;i ++)
#define repe(i,n) for(int i=1;i<=n;i++)
#define mst(A,k) memset(A,k,sizeof(A))

const ll mod = 1e9 + 7;
int n,m;
char maze[505][505];
ll dp[2][505][505];

void add_mod(ll& a,ll& b,const ll& mod)
{
	if(!b) return;
	a = (a + b) % mod;
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,n)
		rep(j,m)
			scanf(" %c",&maze[i][j]);
	if(n == 1 && m == 1)
	{
		printf("1\n");
		return 0;
	}
	int up = (n + m - 1) >> 1;
	int down = n + m - up;
	mst(dp[0],0);
	for(int i=0; i<n && up - 1 - i >= 0; i++)
	{
		for(int j=i; ;j++)
		{
			if(down - 1 - j < up - 1 - i) break;
			if(maze[i][up-1-i] == maze[j][down-1-j])
			{
				dp[0][i][j]++;
				if(down - up == 2 && j - i == 1) dp[0][i][j]++;
			}
		}
	}
	int cnt = 0;
	for(int r=1; r<up; r++)
	{
		cnt ^= 1;
		mst(dp[cnt],0);
		int a = up - r;
		int b = down + r;
		for(int i=0; i<a && i < n; i++)
		{
			for(int j=0; j<b && j < n; j++) if(maze[i][a-1-i] == maze[j][b-1-j])
			{
				add_mod(dp[cnt][i][j],dp[1-cnt][i][j],mod);
				if(j) add_mod(dp[cnt][i][j],dp[1-cnt][i][j-1],mod);
				if(i < n - 1) add_mod(dp[cnt][i][j],dp[1-cnt][i+1][j],mod);
				if(j && i < n - 1) add_mod(dp[cnt][i][j],dp[1-cnt][i+1][j-1],mod);
			}
		}
	}
	printf("%I64d\n",dp[cnt][0][n-1]);
	return 0;
}
