//Language: GNU C++11


#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O500")
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <complex>
#include <sstream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
 
typedef unsigned long long ull;
typedef complex < double > cd;
typedef long double ld;
typedef long long ll;
 
template < class T > void read(T &x) { char c, mi = 0; while(c = getchar(), c <= 32); if(c == '-') mi = 1, x = 0; else if(c < 48 || c > 57) return void(x = c); else x = c - 48; while(c = getchar(), c > 32) x = 10 * x + c - 48; if(mi == 1) x = -x; }
template < class T > void read(T &x, T &y) { read(x); read(y); }
template < class T > void read(T &x, T &y, T &z) { read(x, y); read(z); }
template < class T > void reada(T *a, int n) { for(int i = 0; i < n; ++i) read(a[i]); }
template < class T > void write(T x) { static char s[20]; char pt = 0, mi = (x < 0); if(mi == 1) x = -x; while(!pt || x > 0) { s[++pt] = (char)(x % 10 + '0'); x /= 10; } if(mi == 1) putchar('-'); while(pt > 0) putchar(s[pt--]); }
template < class T > void write(T x, T y) { write(x); putchar(' '); write(y); }
template < class T > void write(T x, T y, T z) { write(x, y); putchar(' '); write(z); }
template < class T > void writeln(T x) { write(x); puts(""); }
template < class T > void writea(T *a, int n) { for(int i = 0; i < n; ++i) { write(a[i]); putchar(i + 1 == n ? '\n' : ' '); } }
template < class T > T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template < class T > T lcm(T a, T b) { return a / gcd(a, b) * b; }
template < class T > T qpom(T a, T b, T mod = 1000000007) { T r = 1; while(b > 0) { if(b & 1) r = r * a % mod; a = a * a % mod; b /= 2; } return r; }
template < class T > T qpow(T a, T b) { T r = 1; while(b > 0) { if(b & 1) r *= a; a *= a; b /= 2; } return r; }
template < class T > T imin(T a, T b) { return a < b ? a : b; }
template < class T > T imax(T a, T b) { return a > b ? a : b; }
template < class T > inline void rmin(T &a, const T &b) { if(a > b) a = b; }
template < class T > inline void rmax(T &a, const T &b) { if(a < b) a = b; }
template < class T > T sqr(const T &a) { return a * a; }
 
#define debug(x) cout << #x << "=" << x
#define debuge(x, c) cout << #x << "=" << x << (c)
#define debugn(x) cout << #x << "=" << x << "\n"
#ifndef DEBUG
#define eprintf(...) fprintf(stderr, "%s -> ", string(to_string((long long)__LINE__)).c_str()), fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
 
#define ppb pop_back
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
 
#define inf 1000000007
#define nmax 1000010
#define mmax 300010
#define eps 1e-9

int n, m;
char s[555][555];
int dp[503 * 502 / 2][501];
int X[503 * 502 / 2], Y[503 * 502 / 2];
int to[555][555];

inline void add(int &a, int b) {
	if((a += b) >= inf) {
		a -= inf;
	}
}

int go(int A, int y) {
	if(dp[A][y] >= 0) {
		return dp[A][y];
	}
#define x (X[A])
#define l (Y[A])
#define r (n + m - l - (x - 1) - (y - 1))
	if(!(x <= l && y <= r) || s[x][y] != s[l][r]) {
		return dp[A][y] = 0;
	}
	if(abs(x - l) + abs(y - r) <= 1) {
		return dp[A][y] = 1;
	}
	int &ret = dp[A][y];
	ret = 0;
	if(x + 1 <= n && l - 1 >= 1) {
		add(ret, go(to[x + 1][l - 1], y));
	}
	if(x + 1 <= n && r - 1 >= 1) {
		add(ret, go(to[x + 1][l], y));
	}
	if(y + 1 <= m && l - 1 >= 1) {
		add(ret, go(to[x][l - 1], y + 1));
	}
	if(y + 1 <= m && r - 1 >= 1) {
		add(ret, go(to[x][l], y + 1));
	}
	return ret;
}

int main() {
//	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
//	freopen("entropy.in", "r", stdin); freopen("entropy.out", "w", stdout);
	scanf("%d%d\n", &n, &m);
	for(int i = 1; i <= n; ++i) {
		gets(s[i] + 1);
	}
	int sz = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			to[i][j] = sz;
			X[sz] = i;
			Y[sz] = j;
			sz++;
		}
	}
//	cout << sizeof(dp) << endl;
	memset(dp, -1, sizeof(dp));
	cout << go(to[1][n], 1) << '\n';
	getchar(); getchar();
	return 0;
}  