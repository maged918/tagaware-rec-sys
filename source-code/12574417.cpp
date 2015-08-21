//Language: GNU C++


#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

#define MAX 505
#define MOD 1000000007

int n, m;
int s, t, i, j, r, c, k;
char ch[MAX][MAX];
long a[2][MAX][MAX];

inline bool check(int r1, int c1, int r2, int c2)
{
	return (r1 <= r2 && c1 <= c2 && ch[r1][c1] == ch[r2][c2]);
}

inline void add(long& a, long b)
{
	a += b;
	if (a >= MOD)
		a -= MOD;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", ch[i]);

	int total = n + m - 2;

	for (s = total / 2; s >= 0; s--) {
		memset(a[s & 1], 0, sizeof(a[s & 1]));
		t = (s ^ 1) & 1;
		if (s == total / 2) {
			if ((total ^ 1) & 1) {
				for (i = 0; i < n; i++)
					a[s & 1][i][i] = 1;
			}
			else {
				for (i = 0; i <= min(s, n - 1); i++) {
					j = s - i;
					for (r = n - 1; r >= max(0, n - 1 - s); r--) {
						c = total - s - r;
						if (i <= r && j <= c && ch[i][j] == ch[r][c]) {
							a[s & 1][i][r] = 1;
						}
					}
				}
			}
		}
		else {
			for (i = 0; i <= min(s, n - 1); i++) {
				j = s - i;
				for (r = n - 1; r >= max(0, n - 1 - s); r--) {
					c = total - s - r;
					if (i <= r && j <= c && ch[i][j] == ch[r][c]) {
						long x = 0;

						if (check(i + 1, j, r - 1, c))
							add(x, a[t][i + 1][r - 1]);

						if (check(i + 1, j, r, c - 1))
							add(x, a[t][i + 1][r]);

						if (check(i, j + 1, r - 1, c))
							add(x, a[t][i][r - 1]);

						if (check(i, j + 1, r, c - 1))
							add(x, a[t][i][r]);

						a[s & 1][i][r] = x;
					}
				}
			}
		}
	}


	cout << a[0][0][n - 1] << endl;

	return 0;
}