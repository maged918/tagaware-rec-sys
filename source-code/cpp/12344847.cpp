//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 200005
using namespace std;

const long long mod = 1000000007;
long long fac[N];
long long inv[N];
long long dp[N];
vector< pair<int, int> > black;

long long bigMod(long long b, long long p)
{
	if (p == 0)
		return 1 % mod;
	if (p == 1)
		return b % mod;
	if (p % 2)
		return b * bigMod(b, p-1) % mod;
	long long x = bigMod(b, p/2);
	return x * x % mod;
}

long long com(long long x, long long y)
{
	long long ret = fac[x];
	ret = ret * inv[y] % mod;
	ret = ret * inv[x-y] % mod;
	return ret;
}

int main()
{
	fac[0] = 1;
	for (int i = 1; i < N; i++)
		fac[i] = fac[i-1] * i % mod;
	for (int i = 0; i < N; i++)
		inv[i] = bigMod(fac[i], mod-2);

	int h, w, n;
	while (cin >> h >> w >> n) {
		memset(dp, 0, sizeof(dp));
		black.clear();
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			black.push_back(make_pair(x-1, y-1));
		}
		black.push_back(make_pair(h-1, w-1));
		sort(black.begin(), black.end());
		for (int i = 0; i < black.size(); i++) {
			int x = black[i].first;
			int y = black[i].second;
			dp[i] = com(x+y, y);
			for (int j = 0; j < i; j++) {
				int a = black[j].first;
				int b = black[j].second;
				if (a <= x && b <= y) {
					dp[i] = (mod + dp[i] - com(x-a + y-b, x-a) * dp[j] % mod) % mod;
				}
			}
		}
		cout << dp[black.size()-1] << endl;
	}
	return 0;
}


				  		   			 	 	 				 	  	 	