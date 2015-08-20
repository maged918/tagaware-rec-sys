//Language: GNU C++


#include <bits/stdc++.h>
#define R first
#define L second
#define MP make_pair
#define PB push_back

using namespace std;

typedef pair<int, int> pie;

const int maxn = 2 * 1e5 + 10;
set<pie> st;

main() {
	int n, k, a, x, m;
	cin >> n >> k >> a;
	st.insert(MP(n + 1, 0));
	cin >> m;
	int sum = (n + 1) / (a + 1);
	int ans = -1;
	for(int i = 0;i < m;i ++) {
		cin >> x;
		pie pos = *st.upper_bound(MP(x, -1));
		sum -= (pos.R - pos.L) / (a + 1);
		st.erase(st.find(pos));
		st.insert(MP(x, pos.L));
		sum += (x - pos.L) / (a + 1);
		st.insert(MP(pos.R, x));
		sum += (pos.R - x) / (a + 1);
		if(sum < k and ans == -1)
			ans = i + 1;
	}
	cout << ans << endl;
	return 0;
}
