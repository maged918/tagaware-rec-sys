//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
using namespace std;typedef long long ll;
typedef unsigned long long ull;
typedef long long int int64;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii > vii;
typedef vector< pair < pair<int, int>,int > > viii;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<vii> vvii;
#define SIZE(X) ((int)(X.size()))
#define X first
#define Y second
#define LENGTH(X) ((int)(X.length()))
#define pb push_back
#define mp(X,Y) make_pair(X,Y)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define tr(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ain(a,n) int ((a)[(n)]); for(int i=0; i<(n); i++) cin>>((a)[i])
#define FOR(i,n) for(int i=0;i<n;i++)
#define FU(i,a,n) for(int i=a;i<=n;i++)
#define FD(i,a,n) for(int i=n;i>=a;i--)
#define GI(n) int (n); scanf("%d",&(n))
#define GS(n) scanf("%s"&s)
#define PII(n,m) printf("%d %d\n",n,m)
#define PL(n) printf("%I64d\n",n)
#define F(i,L,R) for (int i = L; i < R; i++)
#define GII(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define IN GI(t);while(t--)
#define PLL(n) printf("%I64d\n",n)
#define GLL(n) scanf("%I64d",&n)
#define GL(n) scanf("%I64d",&n)
#define PN printf("\n")


#define pr16
 
#ifdef pr16
  #define pr(x)                 cerr << #x << ": " << x << endl;
  #define pr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
  #define pr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
  #define pr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
  #define pr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
  #define pr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
  #define prdd(a,r,c) for(int i=0;i<(r);i++) { for(int j = 0;j<(c);j++) cerr<<a[i][j]<<" "; cerr<<endl; } cerr<<endl;
  #define prc(a) tr(a, it) cerr<<*(it)<<" "; cerr<<endl
  #define pra(a,n) for(int i=0; i<(n); i++) cerr<<((a)[i])<<" "; cerr<<"\n"
  #define prdd(a,r,c) for(int i=0;i<(r);i++) { for(int j = 0;j<(c);j++) cerr<<a[i][j]<<" "; cerr<<endl; } cerr<<endl; 
  #define prddd(a,x,y,z) for(int i=0;i<x;i++) {cerr<<"layer "<<i<<":\n";prdd(a[i],y,z)}
 
#else
  #define pr(x)
  #define pr2(x, y)
  #define pr3(x, y, z)
  #define pr4(a, b, c, d)
  #define pr5(a, b, c, d, e)
  #define pr6(a, b, c, d, e, f)
  #define tr(c,it)
  #define prc(a)
  #define pra(a,n)
  #define prdd(a, r, c)
  #define prddd(a,x,y,z)
#endif

#define MAXN 1007
# define PI 3.14159265
const ll MOD = 1e9+7;
const int INF = 1e9;

int n,k,a,m;
set<int> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>a;
    int cnt = (n+1) / (a+1);
    cin>>m;
    int ans = -1;
    s.insert(0); s.insert(n+1);
    FOR(i,m){
        int x;
        cin>>x;
        s.insert(x);
        auto it = s.lower_bound(x);
        it--;
        int l = *it;
        it = s.upper_bound(x);
        int r = *it;
        cnt -= (r-l) / (a+1);
        cnt += (r-x) / (a+1);
        cnt += (x-l) / (a+1);
        if(cnt < k){
            ans = i+1;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}