//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl;

int main() {
	#ifdef LCL
		#define task "file"
		freopen(task".in", "r", stdin);
		freopen(task".out", "w", stdout);
	#endif
	
	int n, m; scanf("%d%d", &n, &m);
	vector< vector<int> > a(m, vector<int>(n));
	
	vector<int> w(n, 0);
	for (int i = 0; i < m; i++) {
		int w_j = -1, w_max = -1;
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] > w_max) {
				w_j = j; w_max = a[i][j];
			}
		}
		w[w_j] = w[w_j] + 1;
	}
	
	int w_i = -1, w_max = -1;
	for (int i = 0; i < n; i++) {
		if (w[i] > w_max) {
			w_i = i;
			w_max = w[i];
		}
	}
	cout << w_i + 1;
	
	return 0;
}