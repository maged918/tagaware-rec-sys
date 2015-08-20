//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define llong long long
#define long llong

const int module = 1000000007;

string A[510];
int F[2][510][510];
int m, n;

inline bool valid (int x,int y) { return 0 < x && x <= m && 0 < y && y <= n; }
inline bool valid (int x,int y,int u,int v) { return valid(x, y) && valid(u, v) && A[x][y] == A[u][v]; }
inline void add (int &s,int x) { s = (s + x) % module; }

void enter ()
{
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) cin >> A[i], A[i] = " " + A[i];
}

void solve ()
{
	if (A[1][1] != A[m][n]) {cout << 0; return;}
	F[1][1][m] = 1;

	int res = 0;
	for (int i = 1, k = 1; i <= m; ++i, k ^= 1)
	for (int j = 1; j <= n; ++j)
	if (i != 1 || j != 1)
		for (int x = 1; x <= m; ++x)
		{
			int y = m + n - x - i - j + 2;
			if (!valid(i, j, x, y)) continue;

			int s = 0;
			if (valid(i, j - 1, x, y + 1)) add(s, F[k][j - 1][x]);
			if (valid(i - 1, j, x, y + 1)) add(s, F[k ^ 1][j][x]);
			if (valid(i, j - 1, x + 1, y)) add(s, F[k][j - 1][x + 1]);
			if (valid(i - 1, j, x + 1, y)) add(s, F[k ^ 1][j][x + 1]);
			F[k][j][x] = s;

			if ((i == x && j == y) || (i + 1 == x && j == y) || (i == x && j + 1 == y))
				add(res, F[k][j][x]);
		}

	cout << res;
}

int main ()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
	if (ifstream("test.inp")) cin.rdbuf((new ifstream("test.inp"))->rdbuf());

	enter();
	solve();
}