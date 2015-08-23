//Language: GNU C++11


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <climits>
#include <ctime>
using namespace std;

typedef long long ll;
#define ___ ios_base::sync_with_stdio(0);cin.tie(0);
#define N 4005
#define M 1000000007
#define judge(x,y) ((x)>=0&&(x)<h&&(y)>=0&&(y)<w)

template <class T>
inline bool getInt(T &x) {
	char c; T sign = 1;
	if ((c = getchar()) == EOF) { return false; }
	while ((c < '0' || c > '9') && c != '-') { c = getchar(); };
	if (c == '-') { sign = -1; c = getchar(); }
	x = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') { x = x * 10 + c - '0'; }
	x *= sign;
	return true;
}

int dp[N][N];

int main() {
	int n;
	getInt(n);
	dp[0][0] = 1; dp[1][0] = 1; dp[1][1] = 2;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][i - 1];
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			dp[i][j] %= M;
		}
	}
	printf("%d\n", dp[n][n - 1]);
}