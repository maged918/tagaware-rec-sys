//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define ll long long
#define pli pair<ll, int>
#define x first
#define y second
#define INF 1000000000LL
#define eps 1E-9
#define debug(x) cout << #x << " : " << x << endl;
using namespace std;
int main() {
	ll N, K;
	cin >> N >> K;
	vector<pli> vec(N);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i].x;
		vec[i].y = i;
	}
	sort(vec.begin(), vec.end());
	vector<pli>::iterator begin, end;
	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		if (vec[i].x % K != 0 || vec[i].x * K > INF || vec[i].x * K < -INF) continue;
		begin = lower_bound(vec.begin(), vec.end(), pli(vec[i].x / K, 0));
		end = upper_bound(vec.begin(), vec.end(), pli(vec[i].x / K, vec[i].y - 1));
		ll cnt1 = end - begin;
		begin = lower_bound(vec.begin(), vec.end(), pli(vec[i].x * K, vec[i].y + 1));
		end = upper_bound(vec.begin(), vec.end(), pli(vec[i].x * K, N - 1));
		ll cnt2 = end - begin;
		ans += cnt1 * cnt2;
	}
	cout << ans << endl;
	return 0;
}
