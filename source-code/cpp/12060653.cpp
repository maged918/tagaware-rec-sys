//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define ls (t << 1)
#define rs (t << 1) | 1

const int maxn = 100005;

struct Shit {
	int d[26];
	Shit() {
		memset(d, 0, sizeof(d));
	}
	Shit operator + (Shit const &I) const {
		Shit ret;
		for(int i = 0; i < 26; i++) ret.d[i] += d[i] + I.d[i];
		return ret;
	}
};

typedef pair <Shit, Shit> PSS;

struct SegTree {
	int left, right, state;
	bool lazy;
	Shit p;
} T[maxn << 2];

char str[maxn];

PSS Distribute(int x, int k, Shit p) {
	Shit q;
	if(k == 1) {
		for(int i = 0; i < 26; i++) {
			int u = min(x, p.d[i]);
			q.d[i] += u;
			p.d[i] -= u;
			x -= u;
		}
	} else {
		for(int i = 25; i >= 0; i--) {
			int u = min(x, p.d[i]);
			q.d[i] += u;
			p.d[i] -= u;
			x -= u;
		}
	}
	return make_pair(q, p);
}
void PushUp(int t) {
	T[t].p = T[ls].p + T[rs].p;
	T[t].state = 0; //乱序
}

void PushDown(int t) {
	if(T[t].lazy) {
		T[ls].state = T[rs].state = T[t].state;
		T[ls].lazy = T[rs].lazy = true;
		PSS U = Distribute(T[ls].right - T[ls].left + 1, T[t].state, T[t].p);
		T[ls].p = U.first;
		T[rs].p = U.second;
		T[t].lazy = false;
	}
}
void Build(int l, int r, int t) {
	T[t].left = l;
	T[t].right = r;
	T[t].lazy = false;
	T[t].state = 1;
	if(l == r) {
		T[t].p.d[str[l] - 'a'] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	Build(l, mid, ls);
	Build(mid + 1, r, rs);
	PushUp(t);
}

Shit Query(int l, int r, int t) {
	if(T[t].left == l && T[t].right == r) return T[t].p;
	PushDown(t);
	if(r <= T[ls].right) {
		return Query(l, r, ls);
	} else if(l >= T[rs].left) {
		return Query(l, r, rs);
	} else {
		return Query(l, T[ls].right, ls) + Query(T[rs].left, r, rs);
	}
}
void Update(int l, int r, int t, int k, Shit p) {
	//k = 0 乱序, k = 1升序, k = 2降序
	if(T[t].left == l && T[t].right == r) {
		T[t].p = p;
		T[t].state = k;
		T[t].lazy = true;
		return;
	}
	PushDown(t);
	if(r <= T[ls].right) {
		Update(l, r, ls, k, p);
	} else if(l >= T[rs].left) {
		Update(l, r, rs, k, p);
	} else {
		PSS U = Distribute(T[ls].right - l + 1, k, p);
		Update(l, T[ls].right, ls, k, U.first);
		Update(T[rs].left, r, rs, k, U.second);
	}
	PushUp(t);
}

void Output(int t) {
	if(T[t].state == 0) {
		PushDown(t);
		Output(ls);
		Output(rs);
	} else if(T[t].state == 1) {
		for(int i = 0; i < 26; i++) {
			while(T[t].p.d[i]--) putchar('a' + i);
		}
	} else {
		for(int i = 25; i >= 0; i--) {
			while(T[t].p.d[i]--) putchar('a' + i);
		}
	}
}
int main() {
	int n, q, l, r, k;
	scanf("%d%d", &n, &q);
	scanf("%s", str + 1);
	Build(1, n, 1);
	while(q--) {
		scanf("%d%d%d", &l, &r, &k);
		Update(l, r, 1, (k ^ 1) + 1, Query(l, r, 1));
	}
	Output(1);
	return 0;
}
