//Language: GNU C++


#include <cstdio>
#include <algorithm>

const int N = 2000 + 10;
const int mod = 1000000000 + 7;

int h, w, n;
struct Point{
	int x, y;
	bool operator < (const Point &b) const
	{
		if(x == b.x) return y < b.y;
		return x < b.x;
	}
}a[N];
int dp[N];
int fac[200010], facI[200010];

int mul(int x, int y)
{
	int res = 1;
	while(y)
	{
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y /= 2;
	}
	return res;
}
int C(int n, int m)
{
	int res = fac[n];
	res = 1ll * res * facI[n-m] % mod;
	res = 1ll * res * facI[m] % mod;
	return res;
}

int main()
{
	fac[0] = facI[0] = 1;
	for(int i = 1; i <= 200005; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 1; i <= 200005; i++)
		facI[i] = mul(fac[i], mod - 2);
	scanf("%d%d%d", &h, &w, &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
	a[n+1] = (Point){h, w};
	std::sort(a+1, a+1+n+1);
	for(int i = 1; i <= n + 1; i++)
	{
		dp[i] = C(a[i].x - 1 + a[i].y - 1, a[i].x - 1);
		for(int j = 1; j < i; j++)
			if(a[i].x >= a[j].x && a[i].y >= a[j].y)
				dp[i] = ((dp[i] - 1ll * dp[j] * C(a[i].x - a[j].x + a[i].y - a[j].y, a[i].x - a[j].x) % mod) % mod + mod) % mod;
	}
	//for(int i = 1; i <= n; i++) printf("%d ", dp[i]);
	printf("%d\n", dp[n+1]);
	return 0;
}
