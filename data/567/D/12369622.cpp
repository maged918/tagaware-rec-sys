//Language: GNU C++


#include <cstdio>
#include <set>

using namespace std;

struct Interval {
	int lo, hi;
	Interval (const int & _hi = -1) : lo (-1), hi (_hi) {
		return;
	}
	Interval (const int & _lo, const int & _hi) : lo (_lo), hi (_hi) {
		return;
	}
};

inline bool operator < (const Interval & a, const Interval & b) {
	if (a.hi != b.hi)
		return a.hi < b.hi;
	return a.lo < b.lo;
}

const int MAXN = 200000, MAXM = 200000;
set <Interval> st;
set <Interval>::iterator iter;
int x [MAXM], n, k, a, m, c, p, q, i;
bool hit [MAXN];

inline void remove_segment (const set <Interval>::iterator iter) {
	c -= (iter -> hi - iter -> lo + 1) / (a + 1);
	st.erase (iter);
	return;
}

inline void add_segment (const int & lo, const int & hi) {
	c += (hi - lo + 1) / (a + 1);
	st.insert (Interval (lo, hi));
	return;
}

int main () {
	scanf ("%d%d%d%d", & n, & k, & a, & m);
	add_segment (0, n);
	for (i = 0; i < m; i ++) {
		scanf ("%d", & x [i]);
		x [i] --;
		iter = st.lower_bound (Interval (x [i]));
		p = iter -> lo;
		if (p > x [i])
			continue;
		q = iter -> hi;
		remove_segment (iter);
		add_segment (p, x [i]);
		add_segment (x [i] + 1, q);
		if (c < k) {
			printf ("%d\n", i + 1);
			return 0;
		}
	}
	printf ("-1\n");
	return 0;
}
