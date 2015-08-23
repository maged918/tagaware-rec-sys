//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define X first
#define Y second
#define REP(i,a) for(int i=0;i<a;++i)
#define REPP(i,a,b) for(int i=a;i<b;++i)
#define FILL(a,x) memset(a,x,sizeof(a))
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	mp make_pair
#define	pb push_back
#define sz(a) int((a).size())
#define all(a)  a.begin(), a.end()
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;
#define present(c,x) ((c).find(x) != (c).end())
const double eps = 1e-8;
#define EQ(a,b) (fabs((a)-(b))<eps)
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
const int mod = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;
ll fl(ll x, ll y) {
    if (x >= 0) return x / y;	return x / y - (x % y ? 1 : 0);
}
ll cl(ll x, ll y) {
    if (x >= 0) return (x + y - 1) / y;    return x / y;
}

pii B[N];
int C[N];
int A[N];

int main(){
	int n;
	scanf("%d",&n);
	REP(i,n){
		int x;
		scanf("%d",&x);
		if(B[x].X==0)	B[x].X=B[x].Y=i+1;
		else{
			B[x].Y = max(B[x].X,i+1);
		}
		C[x]++;
	}
	int x,y,cnt=0,cnt1=0;
	REP(i,1000001){
		if(B[i].X==0)	continue;
		if(C[i]>cnt1 || ( C[i]==cnt1 && B[i].Y-B[i].X+1<cnt)){
			cnt = B[i].Y-B[i].X+1;
			x = B[i].X;y = B[i].Y;
			cnt1 = C[i];
		}
	}
	printf("%d %d\n",x,y);
  return 0;
}
