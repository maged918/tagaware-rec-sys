//Language: GNU C++11


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#include <set>
#include <map>
#include <fstream>
#include <iterator>

using namespace std;

typedef long long ll;

const int maxN = 222222;

int n, k, a, m, A[maxN], b[maxN], dp[maxN];

int calc(int v) {
	return dp[v];
}

bool f(int cnt) {
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= cnt; ++i) {
		b[A[i]] = 1;
	}
	int l = 1, cur = 0;
	while (l <= n) {
		if (b[l] == 1) ++l; else {
			int r = l;
			while (r <= n && b[r] == 0) ++r; --r;
			int len = r - l + 1;
			cur += calc(len);
			l = r + 1;
		}
	}                  
	return (cur >= k);	
}
                               
int main() {                            
	//freopen("input.txt", "r", stdin);
	scanf("%d %d %d\n", &n, &k, &a);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i) {
		if (i < a) dp[i] = 0; else
		if (i == a) dp[i] = 1; else
		dp[i] = dp[i - a - 1] + 1;
	}
	scanf("%d\n", &m);
	for (int i = 1; i <= m; ++i) scanf("%d", &A[i]);
	int l = 0, r = m;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (!f(mid)) r = mid; else l = mid;
	}
	if (f(r)) printf("%d\n", -1); else
	printf("%d\n", r);
	return 0;
}