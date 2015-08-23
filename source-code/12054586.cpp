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
#define nmax 100010
#define mmax 300010
#define eps 1e-9

struct node {
	int a[26], sz, y;
	char isSorted;
	char c;
	node *l, *r;
	node(char _c) : c(_c), y(rand() * RAND_MAX + rand()), sz(1), l(0), r(0), isSorted(0) {
		memset(a, 0, sizeof(a));
		a[c - 'a'] = 1;
	}
};

int n, q;
char s[123456];
int l, r, c;

int sz(node *t) {
	return t ? t->sz : 0;
}

void upd(node *t) {
	if(t) {
		t->sz = 1 + sz(t->l) + sz(t->r);
		for(int i = 0; i < 26; ++i) {
			t->a[i] = (t->l ? t->l->a[i] : 0) + (t->r ? t->r->a[i] : 0);
		}
		t->a[t->c - 'a'] += 1;
	}
}

void push(node *t) {
	if(t && t->isSorted) {
		if(t->l) t->l->isSorted = t->isSorted;
		if(t->r) t->r->isSorted = t->isSorted;
		int arr[26];
		for(int i = 0; i < 26; ++i) {
			arr[i] = t->a[i];
		}
		if(t->isSorted == 1) {
			if(t->l) {
				for(int i = 0; i < 26; ++i) {
					t->l->a[i] = 0;
				}
				int sl = sz(t->l);
				for(int i = 0; i < 26 && sl != 0; ++i) {
					int mi = min(arr[i], sl);
					sl -= mi;
					arr[i] -= mi;
					t->l->a[i] = mi;
				}
			}
			for(int i = 0; i < 26; ++i) {
				if(arr[i] != 0) {
					t->c = (char)(i + 'a');
					arr[i]--;
					break;
				}
			}
			if(t->r) {
				for(int i = 0; i < 26; ++i) {
					t->r->a[i] = arr[i];
				}
			}
		} else {
			if(t->l) {
				for(int i = 0; i < 26; ++i) {
					t->l->a[i] = 0;
				}
				int sl = sz(t->l);
				for(int i = 25; i >= 0 && sl != 0; --i) {
					int mi = min(arr[i], sl);
					sl -= mi;
					arr[i] -= mi;
					t->l->a[i] = mi;
				}
			}
			for(int i = 25; i >= 0; --i) {
				if(arr[i] != 0) {
					t->c = (char)(i + 'a');
					arr[i]--;
					break;
				}
			}
			if(t->r) {
				for(int i = 25; i >= 0; --i) {
					t->r->a[i] = arr[i];
				}
			}
		}
		t->isSorted = false;
	}
}

void split(node *t, node *&l, node *&r, int x) {
	push(t);
	if(!t) {
		l = r = NULL;
		return;
	}
	if(sz(t->l) + 1 <= x) {
		split(t->r, t->r, r, x - sz(t->l) - 1);
		l = t;
		upd(l);
		return;
	}
	split(t->l, l, t->l, x);
	r = t;
	upd(r);
}

node *merge(node *l, node *r) {
	push(l); push(r);
	if(!l || !r) {
		return l ? l : r;
	}
	if(l->y < r->y) {
		l->r = merge(l->r, r);
		upd(l);
		return l;
	}
	r->l = merge(l, r->l);
	upd(r);
	return r;
}

void out(node *root) {
	if(!root) {
		return;
	}
	push(root);
	out(root->l);
	putchar(root->c);
	out(root->r);
}

int main() {
//	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
//	freopen("entropy.in", "r", stdin); freopen("entropy.out", "w", stdout);
	scanf("%d%d\n", &n, &q);
	gets(s + 1);
	node *root = NULL;
	for(int i = 1; i <= n; ++i) {
		root = merge(root, new node(s[i]));
	}
	while(q --> 0) {
		scanf("%d%d%d", &l, &r, &c);
		node *a, *b;
		split(root, a, root, l - 1);
		split(root, root, b, r - l + 1);
		if(c == 0) {
			root->isSorted = 2;
		} else {
			root->isSorted = 1;
		}
		root = merge(a, merge(root, b));
	}
	out(root);
	putchar('\n');
	getchar(); getchar();
	return 0;
}