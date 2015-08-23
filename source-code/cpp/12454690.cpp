//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	static long long v[4010][4010];
	v[0][0] = 1;
	for (int i = 0; i <= n; ++i){
		v[i+1][0] = v[i][i];
		for (int j = 0; j <= i; ++j)
			v[i+1][j+1] = (v[i+1][j] + v[i][j]) % MOD;
	}
	cout << (v[n][n] - v[n-1][n-1] + MOD) % MOD << '\n';
return 0;}
