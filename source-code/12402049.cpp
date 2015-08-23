//Language: GNU C++11


//ill hit the bottom and escape
#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define lwb lower_bound
#define upb upper_bound
#define X first
#define Y second
#define int long long
#define double long double
#define slowdown ios :: sync_with_stdio(false)
//#define cin fin
//#define cout fout

using namespace std;

typedef pair<int, int> pii;
typedef complex<double> point;

const double pi = acos(-1);
const int md = 1000 * 1000 * 1000 + 7;
const int o = 1000 * 1000 * 1000;
const int oo = o * o;
const double eps = 1e-7;
const int maxn = 2 * 100 * 1000 + 100;

int n, k, a;
int m, num = 0;
int dp[maxn], x[maxn];
set<int> s;

main() {
	slowdown;
	cin.tie(0);

	cin >> n >> k >> a;
	cin >> m;
	for (int i = 0;i < m; i++) 
		cin >> x[i];

	s.insert(0);
	s.insert(n + 1);

	for (int i = 1; i <= n + 1; i++)
		if (i == a)
			dp[i] = 1;
		else if (i > a)
			dp[i] = dp[i - a - 1] + 1;

	num = dp[n];
	int ans = -2;
	for (int i = 0; i < m; i++) {
		auto it1 = s.upb(x[i]), it2 = it1;
		it1--;
		int tmp1 = *it1, tmp2 = *it2;
		num -= dp[tmp2 - tmp1 - 1];
		num += dp[x[i] - tmp1 - 1]; 
		num += dp[tmp2 - x[i] - 1];
		s.insert(x[i]);
		if (num < k) {
			ans = i;
			break;

		}
	}

	cout << ans + 1 << endl;


	return 0;
}

