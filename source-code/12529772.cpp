//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <iterator>
#include <string>
#include <queue>
#include <cctype>
using namespace std;
#define LL long long
const LL l1 = 1LL;
const int Len = 500;
const int Mod = 1000000007;
int dp[2][Len+5][Len+5];
char mat[Len+5][Len+5];
int n, m;
inline bool check(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2) return true;
	if (x1 == x2 && y1 + 1 == y2) return true;
	if (x1 + 1 == x2 && y1 == y2) return true;
	return false;
}
void solve()
{
	memset(dp, 0, sizeof(dp));
	int ans = 0, mid = (n+m-1)/2, cur = 0;
	for (int len = 0; len <= mid; ++len) {
		memset(dp[cur], 0, sizeof(dp[cur]));
		for (int i = 0; i <= len && i < n; ++i) {
			for (int j = 0; j <= len && i + j < n; ++j) {
				int x1 = i, y1 = len-i, x2 = n-1-j, y2 = m-1-(len-j);
				if (x1 > x2 || y1 > y2 || mat[x1][y1] != mat[x2][y2]) {
					dp[cur][i][j] = 0;
				} else if (!len) {
					dp[cur][i][j] = 1;
				} else {
					if (x1 > 0) {
						if (x2 < n-1) {
							dp[cur][i][j] = (dp[cur][i][j] + dp[cur^1][i-1][j-1])%Mod;
						}
						if (y2 < m-1) {
							dp[cur][i][j] = (dp[cur][i][j] + dp[cur^1][i-1][j])%Mod;
						}
					}
					if (y1 > 0) {
						if (x2 < n-1) {
							dp[cur][i][j] = (dp[cur][i][j] + dp[cur^1][i][j-1])%Mod;
						}
						if (y2 < m-1) {
							dp[cur][i][j] = (dp[cur][i][j] + dp[cur^1][i][j])%Mod;
						}
					}
				}
				if (check(x1, y1, x2, y2)) {
					ans = (ans+dp[cur][i][j])%Mod;
				}
			}
		}
		cur ^= 1;
	}
	printf("%d\n", ans);
}
int main()
{
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%s", mat[i]);
		}
		solve();
	}
	return 0;
}