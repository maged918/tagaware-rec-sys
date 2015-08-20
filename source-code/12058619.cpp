//Language: GNU C++


//by vanjape rajas mangesh

#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef vector< pii > vpii;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (int)(a.size())
#define all(a) a.begin(),a.end()
#define mset(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//Works for forward as well as backward iteration

#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define drt() int t; cin>>t; while(t--)
#define ___ ios_base::sync_with_stdio(false);cin.tie(NULL);

#define pluswrap(index,n) index = (index+1)%n		//index++; if(index>=n) index=0
#define minuswrap(index,n) index = (index + n -1)%n 	//index--; if(index<0) index=n-1
#define roundofint(d) d = (int)((double)d + 0.5)	//Round off d to nearest integer

#define flushn while(gu()!='\n')
#define flushs while(gu()!=' ')

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

int a[100005],vis[1000005],ans[1000005];
int main()
{
	int n;
	cin>>n;
	rep(i,0,n)
	{
		cin>>a[i];
		int tmp=a[i],ct=0;
		int nct=0,limi=100005;
		while(tmp>0)
		{
		//	vis[tmp]++;
		//	ans[tmp]+=ct;
		//	if(tmp%2==1)
		//	{
				int tmp2=tmp;
				int ct2=ct;
				while(tmp2<limi)
				{
					vis[tmp2]++;
					ans[tmp2]+=ct2;
					tmp2*=2;
					ct2++;
				}
				limi=tmp;
		//	}
			if(tmp%2==1)
			{
				nct++;
				limi=100005;
			}
			tmp/=2;
			ct++;
		}
/*		tmp=2*a[i];
		ct=1;
		while(tmp<100005)
		{
			vis[tmp]++;
			ans[tmp]+=ct;
			tmp*=2;
			ct++;
		}*/
	}
	int mini=100000000;
	rep(i,1,100005)
	{
		if(vis[i]==n&&ans[i]<=mini)
		{
			mini=ans[i];
		}
	}
	cout<<mini<<"\n";
	return 0;
}
