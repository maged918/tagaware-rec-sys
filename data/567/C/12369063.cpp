//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+10;
typedef long long ll;
ll dp[MAX_N];
ll a[MAX_N];
map<ll, ll> p;
map<ll, ll> cnt;
int main(){
	//freopen("in", "r", stdin);
	ll n, k;
	ll ans=0;
	scanf("%lld%lld", &n, &k);
	ll kk=k*k;
	for(int i=1; i<=n; i++)
		scanf("%lld", a+i);
	for(int i=1; i<=n; i++){
		if(a[i]%kk==0){
			ans+=p[a[i]/k];
		}
		if(a[i]%k==0){
			p[a[i]]+=cnt[a[i]/k];
		}
		cnt[a[i]]++;
	}
	printf("%lld\n", ans);
	return 0;
}
