//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unsigned long long ull;
#define RI(x) scanf("%d",&x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRI(x) int x;RI(x)
#define DRII(x,y) int x,y;RII(x,y)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(a) a.begin(),a.end()
#define min3(a,b,c) min(a, min(b,c))
#define max3(a,b,c) max(a, max(b,c))
#define sz(a) ((int)a.size())
#define clr(x,a) memset(x, a, sizeof x)
#define REP(i,n) for(int i=0; i<n; ++i)
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define repp(i,a,b) for(int i=a ; i>=b ; --i)
const int MAX=123456789;
const int inf=123456789;
const double EPS = 1e-10;
const double PI = 2*asin(1.0);
const ll mod=1e9+7;
inline int double_cmp(double x, double y = 0, double tol = EPS){return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;}

int main() 
{
	DRII(n, a);
	
	if(n==1)PI(1);
	else if(a==1)PI(2);
	else if(a==n)PI(n-1);
	else if(abs(n-a)<a)PI(a-1);
	else PI(a+1);
}
