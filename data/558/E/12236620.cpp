//Language: MS C++


#pragma comment (linker,"/stack:102400000,102400000")
#include <cstdio>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>
#include <ctime>
#include <bitset>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ls (root << 1)
#define rs (root << 1 | 1)
#define lson l, mid, ls
#define rson mid + 1, r, rs
#define MID mid = ((l + r) >> 1)
#define PR pair<int, int>
#define MP make_pair
#define sqr(x) ((x) * (x))

int lowbit(int x) {return (x & -x);}
//int sgn(double x) {return (x > eps) - (x < -eps);}
template <class T_> T_ f_abs(T_ x) {return x < 0 ? -x : x;}
template <class T_> T_ f_max(T_ a, T_ b) {return a > b ? a : b;}
template <class T_> T_ f_min(T_ a, T_ b) {return a < b ? a : b;}
template <class T_> void chkmax(T_ &a, T_ b) {if(a == -1 || a < b) a = b;}
template <class T_> void chkmin(T_ &a, T_ b) {if(a == -1 || a > b) a = b;}
template <class T_> T_ gcd(T_ a, T_ b) {while(T_ t = a % b) a = b, b = t; return b;}
template <class T_> void f_swap(T_ &a, T_ &b) {T_ t = a; a = b; b = t;}

const double eps = 1e-9;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[] = {0, 0, -1, 1, -1, 1, -1, 1};//UDLR
const int inf = 0x7fffffff;
const int mod = 1000000007;
const int N = 100003;
int n, q, cnt[26], tree[N << 2][26], lazy[N << 2];
char s[N];

void Init() {}

void GetData() {scanf("%s", s + 1);}

void push_up(int root) {
	for(int i = 0; i < 26; ++i)
		tree[root][i] = tree[ls][i] + tree[rs][i];
}

void push_down(int l, int r, int root) {
	if(lazy[root] == -1) return;
	int MID;
	memset(tree[ls], 0, sizeof(tree[ls]));
	memset(tree[rs], 0, sizeof(tree[rs]));
	tree[ls][lazy[root]] = mid - l + 1;
	tree[rs][lazy[root]] = r - mid;
	lazy[ls] = lazy[rs] = lazy[root];
	lazy[root] = -1;
}

void Build(int l, int r, int root) {
	lazy[root] = -1;
	if(l == r) {
		memset(tree[root], 0, sizeof(tree[root]));
		tree[root][s[l] - 'a'] = 1;
		return;
	} int MID;
	Build(lson); Build(rson);
	push_up(root);
}

void Update(int L, int R, int v, int l, int r, int root) {
	if(L <= l && r <= R) {
		memset(tree[root], 0, sizeof(tree[root]));
		tree[root][v] = r - l + 1;
		lazy[root] = v;
		return;
	} int MID;
	push_down(l, r, root);
	if(L <= mid) Update(L, R, v, lson);
	if(R > mid) Update(L, R, v, rson);
	push_up(root);
}

int Query(int L, int R, int id, int l, int r, int root) {
	if(L <= l && r <= R)
		return tree[root][id];
	int MID, res = 0;
	push_down(l, r, root);
	if(L <= mid) res += Query(L, R, id, lson);
	if(R > mid) res += Query(L, R, id, rson);
	push_up(root);
	return res;
}

void Print(int l, int r, int root) {
	if(l == r) {
		int i;
		for(i = 0; i < 26; ++i) {
			if(tree[root][i] != 0)
				break;
		}
		printf("%c", i + 'a');
		return;
	} int MID;
	push_down(l, r, root);
	Print(lson); Print(rson);
}

void Solve() {
	int i, l, r, op;
	Build(1, n, 1);
	while(q--) {
		scanf("%d%d%d", &l, &r, &op);
		for(i = 0; i < 26; ++i)
			cnt[i] = Query(l, r, i, 1, n, 1);
		if(op == 1) {
			for(i = 0; i < 26; ++i) {
				if(cnt[i] != 0) {
					Update(l, l + cnt[i] - 1, i, 1, n, 1);
					l += cnt[i];
				}
			}
		}
		else {
			for(i = 25; i >= 0; --i) {
				if(cnt[i] != 0) {
					Update(l, l + cnt[i] - 1, i, 1, n, 1);
					l += cnt[i];
				}
			}
		}
	}
	Print(1, n, 1); printf("\n");
}

int main() {
	while(~scanf("%d%d", &n, &q)) {
		Init();
		GetData();
		Solve();
	}
	return 0;
}
 	 	 		    		 	    	 	 	    	