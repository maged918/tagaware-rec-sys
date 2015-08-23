//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=100010;
ll l,r;
int h,q,n;
typedef pair<ll,ll> pll;
pll p[maxn];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>h>>q;
	l=1LL<<h-1;
	r=1LL<<h;
	while(q--)
	{
		ll i,L,R,ans;
		cin>>i>>L>>R>>ans;
		L<<=h-i;
		R=R+1<<h-i;
		if(ans) l=max(l,L),r=min(r,R);
		else p[n++]=pll(L,R);
	}
	sort(p,p+n);
	for(int i=0;i<n;i++) if(p[i].first<=l && l<p[i].second) l=p[i].second;
	while(n--) if(p[n].first<r && r<=p[n].second) r=p[n].first;
	if(l>=r) puts("Game cheated!");
	else if(r-l>1) puts("Data not sufficient!");
	else cout<<l<<endl;
	return 0;
}
