//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;

#define FilesX
#define TimeX
#define DEBUG

#ifdef DEBUG
#define DBG(x,s) cout<<s<<": "#x"="<<x<<"\n";
#else
#define DBG(x,s)
#endif
#define P(x) cout<<#x<<" = { "<<x<<" }\n"
#define All(a) (a).begin(), (a).end()
#define rep(i,n) for(int i=0;i<int(n);i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define repi(i,a,n) for(int i=int(a);i<int(n);i++)
#define clr(a, n) memset(a, n, sizeof(a));
#define scn(a,n) rep(i,n) cin>>a[i];
#define scn2(a,row,col) rep(i,row) rep(j,col) cin>>a[i][j];
#define prn(a,n) rep(i,n-1) cout<<a[i]<<" "; cout<<a[n-1]<<endl;
#define prn2(a,row,col) rep(i,row){rep(j,col-1) cout<<a[i][j]<<" "; cout<<a[i][col-1]<<endl;}
#define dri(x) scanf("%d",&(x))
#define drii(x,y) scanf("%d%d",&(x),&(y))
#define drl(x) scanf("%I64d",&(x))
#define drll(x,y) scanf("%I64d%I64d",&(x),&(y))
#define mp(a, b) make_pair(a, b)
#define Odd(x) x%2!=0
#define Even(x) x%2==0
#define PI 3.1415926535897932384626433832795
#define INF 20000000000
const double EPS = (1e-7);
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1;   }

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<int, string> is;
typedef vector<pii> vii;

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return (a * (b / gcd(a, b))); }

//*---------------------------*/

void solution(){
	int n;
	cin>>n;
	vi a(n);
	rep(i, n) cin>>a[i];
	sort(All(a));
	if (a[0] == 1) cout<<-1;
	else cout<<1;
}

//*---------------------------*/
int main(){
	#ifdef Files
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	double beg=clock();

	ios::sync_with_stdio(false);
	solution();

	#ifdef Time
	cout << endl;
	double end=clock();
	printf("*** Total time = %.3f sec ***", (end - beg) / CLOCKS_PER_SEC);
	#endif
	return 0;
}
