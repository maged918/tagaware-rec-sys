//Language: GNU C++11


#include <bits/stdc++.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define XINF INT_MAX
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define RIT reverse_iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
typedef tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update > rb_tree;
#define ALL(X) (X).begin(),(X).end()
#define PQ std::priority_queue
#define HEAP __gnu_pbds::priority_queue
#define X first
#define Y second
#define lson(X) ((X)<<1)
#define rson(X) ((X)<<1|1)

int G[70][70];
ull dp[70][70];

ull dfs(int l, int r) {
	if(dp[l][r] + 1 != 0) return dp[l][r];
	if(l + 1 == r) {
		if(G[l][l+1] & 2) return 1;
		return 0;
	}
	ull ans = 0;
	if(G[l][l+1] & 2) {
		int f = 0;
		REP2(i,l+2,r) {
			if(!(G[l][i] & 1)) f = 1;
			if(!(G[l+1][i] & 1)) f = 1;
		}
		if(!f) ans += dfs(l+2, r);
	}
	
	if(G[l][r] & 2) {
		int f = 0;
		REP2(i,l+1,r-1) {
			if(!(G[l][i] & 1)) f = 1;
			if(!(G[r][i] & 1)) f = 1;
		}
		if(!f) ans += dfs(l+1, r-1);
	}
	
	if(G[r][r-1] & 2) {
		int f = 0;
		REP2(i,l,r-2) {
			if(!(G[r][i] & 1)) f = 1;
			if(!(G[r-1][i] & 1)) f = 1;
		}
		if(!f) ans += dfs(l, r-2);
	}
	return dp[l][r] = ans;
}

int main()
{
#ifdef LOCAL
	   //freopen("x.in","r",stdin);
	   //freopen("x.out","w",stdout);
#endif
	CLR(dp, -1);
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	REP(i,n*2)
	REP(j,n*2) {
		G[i][j] = i==j?2:7;
	}
	REP(i,k) {
		int a,b;
		char s[3];
		cin>>a>>s>>b; a--; b--;
		if(s[0] == '=') {
			G[a][b] &= 2;
			G[b][a] &= 2;
		}else if(s[0] == '>' && s[1] == '=') {
			G[a][b] &= 6;
			G[b][a] &= 3;
		}else if(s[0] == '<' && s[1] == '=') {
			G[a][b] &= 3;
			G[b][a] &= 6;
		}else if(s[0] == '>') {
			G[a][b] &= 4;
			G[b][a] &= 1;
		}else if(s[0] == '<') {
			G[a][b] &= 1;
			G[b][a] &= 4;
		}
	}
	cout<<dfs(0, 2*n-1)<<endl;
	return 0;
}

