//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> vi;
typedef vector<pair<int,int> >vpii;
typedef vector <LL> vl;
typedef vector <pair<LL,LL> > vpll;
typedef pair <int,int> pii;
typedef pair <LL,LL> pll;

#define forup(i,a,b) for(int i=(a); i<(b); ++i)
#define fordn(i,a,b) for(int i=(a); i>(b); --i)
#define rep(i,a) for(int i=0; i<(a); ++i)
#define gi(x) scanf("%d ",&x)
#define gll(x) scanf("%lld ",&x)
#define gd(x) scanf("%lf ",&x)
#define gs(x) scanf(" %s",x) 
#define fs first
#define sc second 
#define pb push_back
#define mp make_pair
#define endl '\n'
void setup()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(15);
}
long long C(long long a)
{
	return a*(a-1)*(a-2)/6;
}
int main()
{
	//setup();
	int n,k;
	cin >> n >> k;
	int a[200005];
	map<int,long long int> m;
	map<int,long long int> cnt;
	long long ans=0;
	if(k==1)
	{
		rep(i,n)
		{	cin >> a[i];
		if(cnt.find(a[i])==cnt.end())
			cnt[a[i]]=1;
		else
			cnt[a[i]]++;
		}
		rep(i,n)
			if(cnt[a[i]]>=3 and m[a[i]]!=1)
			{
				ans+=C(cnt[a[i]]);
				m[a[i]]=1;
			}
	}
	else
	rep(i,n)
	{
		cin >> a[i];
		if(a[i]%k==0 and (a[i]%(k*k))==0)
		{
			if(cnt.find(a[i]/k)!=cnt.end() and cnt.find(a[i]/(k*k))!=cnt.end())
			{
				ans+=m[a[i]/k];
			}
		}
		if(cnt.find(a[i])==cnt.end())
		{
			if(a[i]%k==0 and cnt.find(a[i]/k)!=cnt.end())
				m[a[i]]=cnt[a[i]/k];
			cnt[a[i]]=1;
		}
		else
		{
			if(a[i]%k==0 and cnt.find(a[i]/k)!=cnt.end())
				m[a[i]]+=cnt[a[i]/k];
			cnt[a[i]]++;
		}
	}
	cout << ans << endl;


	return 0;
}

