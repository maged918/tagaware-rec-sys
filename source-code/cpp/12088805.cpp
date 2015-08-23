//Language: GNU C++11


#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <climits>
#include <map>
#include <iterator>
#include <queue>
#define mp make_pair
#define pb push_back
#define nfor(i, x, y) for (int i = x; i < y; i++)
#define si(n) scanf("%d", &n)
#define pi(n) printf("%d", n)
#define sl(n) scanf("%I64d", &n)
#define pl(n) printf("%I64d", n)

const int mod = 1000000007;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector <pii> vpii;

void stop()
{
	puts("0");
	exit(0);
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	/*freopen("sum2.in", "r", stdin);
	freopen("sum2.out", "w", stdout);*/
#endif
	int h, q; si(h); si(q);
	ll al = 1ll << (h - 1);
	ll ar = 1ll << h;
	vector <pair <ll, ll>> m;
	nfor(i, 0, q)
	{
		ll l, r;
		int hg, ans; si(hg);
		sl(l); sl(r); si(ans);
		l <<= (h - hg);
		r = (r + 1) << (h - hg);
		if (ans)
		{
			al = max(al, l);
			ar = min(ar, r);
		}
		else m.pb(mp(l, r));
	}
	sort(m.begin(), m.end());
	for (auto i : m)
		if (i.first <= al && al < i.second) al = i.second;
	for (int i = m.size() - 1; i >= 0; i--)
		if (m[i].second >= ar && ar > m[i].first) ar = m[i].first;
	if (al >= ar) puts("Game cheated!");
	else if (ar - al > 1) puts("Data not sufficient!");
	else pl(al);
	return 0; 
}