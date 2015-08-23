//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define L_L "%I64d"
#define M 100010
#define LY(p) freopen (p".in", "r", stdin); freopen (p".out", "w", stdout)
using namespace std;
long long fac[M * 2], inv[M * 2], mo = 1e9 + 7, s[2010];
int x[M], y[M], n, m, k, w[M];

long long mod (long long x) {
	x %= mo;
	if (x < 0) x += mo;
	return x;
}

bool cmp (int i, int j) {
	if (x[i] == x[j]) return y[i] < y[j];
	return x[i] < x[j];
}

long long Inv (long long o) {
	int x = mo - 2;
	long long s = 1, t = o;
	while (x) {
		if (x & 1) s = mod (s * t);
		t = mod (t * t), x >>= 1;
	}
	return s;
}

void pre() {
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= 200000; i++)
		fac[i] = mod (fac[i - 1] * i), inv[i] = Inv (fac[i]);
}

long long C (int m, int n) {
	return mod (mod (fac[n + m] * inv[n]) * inv[m]);
}

int main()
{
	//LY("e");
	pre();
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
		scanf ("%d %d", &x[i], &y[i]), w[i] = i;
	++ k;
	w[k] = k, x[k] = n, y[k] = m;
	sort (w + 1, w + 1 + k, cmp);
	for (int i = 1; i <= k; i++) {
		s[i] = C (x[ w[i] ] - 1, y[ w[i] ] - 1);
		for (int j = 1; j < i; j++)
			if (y[ w[j] ] <= y[ w[i] ])
				s[i] = mod (s[i] - mod (C (x[ w[i] ] - x[ w[j] ], y[ w[i] ] - y[ w[j] ]) * s[j]));
	}
	printf (L_L, s[k]);
	return 0;
}
