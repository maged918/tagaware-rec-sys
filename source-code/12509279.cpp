//Language: GNU C++


#include<bits/stdc++.h>

#define MOD 1000000007
#define MAX 1000
#define ll long long
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define pb(x) push_back(x)

using namespace std;

int inp[101][101];
int dp[101];

int main()
{
	int n,m;
	sd(n);sd(m);
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			sd(inp[i][j]);
		}
	}
	
	for(int i=0;i<101;i++) dp[i]=0;
	
	for(int i=1;i<=m;i++){
		int mx=-1,win=0;
		for(int j=1;j<=n;j++){
			if(inp[i][j]>mx){
				mx=inp[i][j];
				win=j;
			}
		}
		dp[win]++;
	}
	
	int mx=-1,win=0;
	
	for(int i=0;i<101;i++){
		if(dp[i]>mx){
			mx=dp[i];
			win=i;
		}
	}
	
	pd(win);
}
