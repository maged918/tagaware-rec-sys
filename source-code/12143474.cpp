//Language: GNU C++11


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
using namespace std;
template <class T>
inline bool rd(T &ret) {
	char c; int sgn;
	if (c = getchar(), c == EOF) return 0;
	while (c != '-' && (c<'0' || c>'9')) c = getchar();
	sgn = (c == '-') ? -1 : 1;
	ret = (c == '-') ? 0 : (c - '0');
	while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
	ret *= sgn;
	return 1;
}
template <class T>
inline void pt(T x) {
	if (x <0) {
		putchar('-');
		x = -x;
	}
	if (x>9) pt(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 1e5 + 100;
#define lson (id<<1)
#define rson (id<<1|1)
#define L(x) tree[x].l
#define R(x) tree[x].r
#define Hav(x) tree[x].hav
#define Siz(x) tree[x].siz
#define Lazy(x) tree[x].lazy
struct Tree {
	struct Node {
		int l, r, siz;//siz??????
		int hav;//hav???????? 
		int lazy;//lazy?2?????? lazy?1????????1
	}tree[N << 2];
	void build(int l, int r, int id) {
		L(id) = l; R(id) = r; Siz(id) = r - l + 1;
		Hav(id) = Lazy(id) = 0;
		if (l == r)return;
		int mid = (l + r) >> 1;
		build(l, mid, lson); build(mid + 1, r, rson);
	}
	void Down(int id) {
		if (Lazy(id) == 1) {
			Lazy(id) = 0;
			Hav(lson) = Siz(lson); Hav(rson) = Siz(rson);
			Lazy(lson) = Lazy(rson) = 1;
		}
		else if (Lazy(id) == 2) {
			Lazy(id) = 0;
			Hav(lson) = Hav(rson) = 0;
			Lazy(lson) = Lazy(rson) = 2;
		}
	}
	void Up(int id) {
		Hav(id) = Hav(lson) + Hav(rson);
	}
	void updata(int l, int r, int val, int id) {
		if (l == L(id) && R(id) == r) {
			if (val == 1) 
				Hav(id) = Siz(id);
			else Hav(id) = 0;
			Lazy(id) = val;
			return;
		}
		Down(id);
		int mid = (L(id) + R(id)) >> 1;
		if (r <= mid)updata(l, r, val, lson);
		else if (mid < l)updata(l, r, val, rson);
		else {
			updata(l, mid, val, lson);
			updata(mid + 1, r, val, rson);
		}
		Up(id);
	}
	int query(int l, int r, int id) {
		if (l == L(id) && R(id) == r) {
			return Hav(id);
		}
		Down(id);
		int mid = (L(id) + R(id)) >> 1, ans = 0;
		if (r <= mid)ans = query(l, r, lson);
		else if (mid < l)ans = query(l, r, rson);
		else {
			ans = query(l, mid, lson) + query(mid + 1, r, rson);
		}
		Up(id);
		return ans;
	}
};
Tree alph[26];
int n, q;
char s[N];
int sum[26];
int main() {
	rd(n); rd(q);
	for (int i = 0; i < 26; i++)alph[i].build(1, n, 1);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		alph[s[i] - 'a'].updata(i, i, 1, 1);
	}
	while (q--) {
		int l, r, in;
		rd(l); rd(r); rd(in);
		memset(sum, 0, sizeof sum);
		for (int i = 0; i < 26; i++)
		{
			sum[i] += alph[i].query(l, r, 1);
			alph[i].updata(l, r, 2, 1);
		}
		int tim = 26, i;
		if (in)i = 0; else i = 25, in = -1;
		for (;tim--; i += in) {
			if (sum[i] == 0)continue;
			alph[i].updata(l, l + sum[i] - 1, 1, 1);
			l += sum[i];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 26; j++)
			if (alph[j].query(i, i, 1))
			{
				putchar(j + 'a'); break;
			}
	}
	return 0;
}
