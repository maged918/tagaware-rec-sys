//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;

#define pb push_back
#define mp make_pair
#define sc second
#define ft first

#define FOR(i,N) for (int i=1; i<=N; i++)
#define REP(i,l,r) for (int i=l; i<=r; i++)

#define INF ~0U>>1
#define eps 1e-9

int N, M;
char s[510][510];
int f[2][510][510], ans;

const int mod = 1000000007;

int main ()
{
#ifndef ONLINE_JUDGE
#ifndef MEKTPOY
	freopen (".in", "r", stdin);
	freopen (".out", "w", stdout);
#else
	freopen ("in.txt", "r", stdin);
#endif
#endif
	cin >> N >> M;
	for (int i=1; i<=N; i++)
		scanf ("%s", s[i]+1);
	if (s[1][1] == s[N][M]) f[0][1][M] = 1;
	int tot = (N+M-1);
	if (tot & 1) tot = tot/2;
	else tot = tot/2-1;
	for (int now=1; now<=tot; now++)
		for (int j=1; j<=M; j++)
			for (int k=1; k<=M; k++)
			{
				int i = (now&1), lst = (i^1);
				f[i][j][k] = 0;
				int X1 = now-(j-1)+1, Y1 = j;
				int X2 = N-(now-(M-k)), Y2 = k;
				if (X1 < 1 || X1 > N) continue;
				if (X2 < 1 || X2 > N) continue;
				if (s[X1][Y1] == s[X2][Y2])
				{
					f[i][j][k] = (f[i][j][k]+f[lst][j][k])%mod;
					f[i][j][k] = (f[i][j][k]+f[lst][j-1][k])%mod;
					f[i][j][k] = (f[i][j][k]+f[lst][j][k+1])%mod;
					f[i][j][k] = (f[i][j][k]+f[lst][j-1][k+1])%mod;
				}
				if (now == tot)
				{
					if ((N+M-1) & 1)
					{ 
						if (X1 == X2 && Y1 == Y2)
							ans = (ans+f[i][j][k])%mod;
					}
					else if (f[i][j][k])
					{
						if (X1 == X2 && Y1+1 == Y2) ans = (ans+f[i][j][k])%mod;
						if (X1+1 == X2 && Y1 == Y2) ans = (ans+f[i][j][k])%mod;
					}
				}
			}
	if (N == 1 && M == 2 || N == 2 && M == 1)
	{
		if (s[1][1] == s[N][M]) cout << 1;
		else cout << 0;
		return 0;
	}
	else
		if (N == M && N == 1) cout << 1; 
	else
		cout << ans;
	return 0;
}

