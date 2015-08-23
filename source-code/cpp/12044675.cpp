//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<climits>
#include<cassert>
#include<time.h>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define s(n) scanf("%d",&n)
#define ll long long
#define mp make_pair
#define PII pair <int ,int >
#define PLL pair<ll,ll>
#define inf 1000*1000*1000+5
#define v(a,size,value) vi a(size,value)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define tri pair < int , PII >
#define TRI(a,b,c) mp(a,mp(b,c))
#define xx ff
#define yy ss.ff
#define zz ss.ss
#define in(n) n = inp()
#define vii vector < PII >
#define vll vector< PLL >
#define viii vector < tri >
#define vs vector<string>
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define ok if(debug)
#define trace1(x) ok cerr << #x << ": " << x << endl;
#define trace2(x, y) ok cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)    ok      cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)  ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
								<< #d << ": " << d << endl;
#define trace5(a, b, c, d, e) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
									 << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) ok cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " \
									<< #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
ll MOD = int(1e9) + 7;

int debug = 1;
const int N = int(1e5) + 5;
using namespace std;
PII a[N];
int main()
{
      int i,j,n,t;
      ios::sync_with_stdio(false);
	cin>>n;
	rep(i,n)
	{
		cin>>a[i].ff>>a[i].ss;
	}
	sort(a,a+n);
	int pos = 0 , neg = 0;
	rep(i,n)
	{
		if(a[i].ff > 0)
			pos++;
		else
			neg++;
	}
	int no = min(pos,neg);
	if(pos == neg)
	{
		int sum = 0;
		rep(i,n)
			sum += a[i].ss;
		cout<<sum;
	}
	else if(pos < neg)
	{
		int sum = 0;
		rep(i,n)
		{
			if(a[i].ff > 0)
				sum += a[i].ss;
			else if(a[i+pos+1].ff >= 0)
				sum += a[i].ss;
		}
		cout<<sum;
	}
	else
	{
		int sum = 0;
		rep(i,n)
		{
			if(a[i].ff < 0)
				sum += a[i].ss;
			else if(i <= 2*neg)
				sum += a[i].ss;
		}
		cout<<sum;
	}
}
