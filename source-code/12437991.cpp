//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%I64d", &x)
#define loop(i,s,e) for(int i=s ; i<e ; i++)
#define rep(i,s,e) for(int i=s ; i>=e ; i--)
#define INF 10000
#define MOD 100000000
#define f first
#define s second
#define EPS 1e-9
#define Rd freopen("in.txt", "r", stdin);
#define Wr freopen("out.txt", "w", stdout);
#define M_PI           3.14159265358979323846  /* pi */

int main(){
#ifndef ONLINE_JUDGE
	// Rd;
	// Wr;
#endif
	int n, k, x;
	ll ans = 0;
	map<int, ll> C, Map;
	sc(n); sc(k);
	loop(i,0,n) {
		sc(x);
		if( x % k == 0 ) {
			ans += Map[ x/k ];
			Map[x] += C[ x/k ];
		}
		C[x]++;
	}
	printf("%I64d\n", ans);
	return 0;
}