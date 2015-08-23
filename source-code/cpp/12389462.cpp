//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100009;

vector< pair<long long, long long> > ans;
int x[MAXN];

int main(int argc, char const *argv[]){
	
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++){
		scanf("%d", &x[i]);
	}

	sort(x, x + n);

	ans.push_back(make_pair(x[1] - x[0], x[n-1] - x[0]));
	for(int i=1; i<n-1; i++){
		ans.push_back(make_pair(min(abs(x[i-1] - x[i]), abs(x[i+1] - x[i])), max(abs(x[n-1] - x[i]), abs(x[0] - x[i]))));
	}
	ans.push_back(make_pair(x[n-1] - x[n-2], x[n-1] - x[0]));

	for(int i=0; i<n; i++){
		cout << ans[i].first << " " << ans[i].second << '\n';
	}

	return 0;
}