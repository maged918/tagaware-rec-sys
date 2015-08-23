//Language: GNU C++11


//Bismillah
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i=a;i<=n;i++)
#define rep(i,n) for (ll i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef long double ld;
ll res = 0 ;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector < pair<ll,ll> > a,b;
	rep(i,n)
	{
		ll x,y;
		cin>>x>>y;
		if (x>0)
			a.pb(mp(x,y));
		else
			b.pb(mp(x,y));
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	if (a.size()==b.size())
	{
		rep(i,a.size())
			res+=a[i].second;
		rep(i,b.size())
			res+=b[i].second;
		cout<<res<<endl;
		return 0;
	}
	if (a.size()<b.size())
	{
		int m = a.size();
		rep(i,m+1)
			res+=b[i].second;
		rep(i,m)
			res+=a[i].second;
	}
	else
	{
		int m = b.size();
		rep(i,m+1)
			res+=a[i].second;
		rep(i,m)
			res+=b[i].second;
	}
	cout<<res<<endl;
	return 0;	
}
