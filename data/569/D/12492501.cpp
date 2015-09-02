//Language: GNU C++11


//In the name of ALLAH
#include <bits/stdc++.h>
using namespace std;

#define fr(i,n,m) for (ll i = (ll)(n) ; i < (ll)(m) ; i ++)
#define rp(i,n,m) for (ll i = (ll)(n - 1) ; i >= (ll)(m) ; i --)
#define fr_(i,n,m,k) for (ll i = (n) ; i < (m) ; i += k)
#define rp_(i,n,m,k) for (ll i = (n - 1) ; i >= (m) ; i -= k)
#define pb push_back
#define mp make_pair
#define popb pop_back
#define sz size()

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;

ll const maxN = 4e3 + 20 , MOD = 1e9 + 7;
ll n, dp[maxN][maxN], c[maxN][maxN], ans = 1;

int main(){
	scanf("%I64d", &n);
	c[0][0] = 1;
	fr(i, 1, n+1){
		fr(j, 0, i+1){
			if (!j || j == i) c[j][i] = 1;
			else c[j][i] = (c[j-1][i-1] + c[j][i-1]) % MOD;
		}
	}
	dp[0][0] = 1;
	fr(i, 0, n+1){
		fr(j, 1, i+1){
			if (j == 1 || j == i) dp[i][j] = 1;
			else dp[i][j] = (dp[i-1][j-1] + j * dp[i-1][j]) % MOD;
		}
	}

	fr(i, 1, n) fr(j, 1, i+1) (ans += dp[i][j] * c[i][n]) %= MOD;
	
	return printf("%I64d", ans), 0;
}
