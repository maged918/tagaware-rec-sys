//Language: GNU C++11


//techwiz911
#include<bits/stdc++.h>
#define pb push_back
#define SZ(a) (int)(a.size())
#define all(a) a.begin(),a.end()
#define gcd __gcd
#define b_c __builtin_popcount
#define mp make_pair
#define fi(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define tr(c,it) for(typeof(c).begin() it=(c).begin();it!=(c).end();it++) 
#define X first
#define Y second
#define init(a,b) memset(a,b,sizeof(a))
#define n_p next_permutation
#define b_s binary_search
#define endl '\n'
#define INF INT_MAX
#define INFL LLONG_MAX
#define sd(n) scanf("%d",&n)
#define pd(n) printf("%d\n",n);
#define slf(n) scanf("%lf",&n);
#define plf(n) printf("%lf",n);
#define ss(n) scanf("%s",n)
#define ps(n) printf("%s",n);
#define sp() printf(" ");
#define ln() printf("\n");
#define TC() int t;sd(t);while(t--)
#define trace1(x)                cerr <<#x<<": "<<x<<endl;
#define trace2(x, y)             cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)          cerr <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)       cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)    cerr <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
#define die(s)  cout<<s<<endl; exit(0);

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef set<int> SI;
typedef set<LL> SLL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;

void FastIO()
{ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);}
LL modpow(LL a, LL p, LL mod)
{LL ret=1;while(p){if(p&1)ret=(ret*a)%mod;a=(a*a)%mod;p/=2;}return ret;}
LL power(LL a, LL p)
{LL ret=1;while(p){if(p&1)ret=(ret*a);a=(a*a);p/=2;}return ret;}
//Template Ends Here


LL fac[200011],inv[200011],dp[2011],mod=1e9+7;

void pre()
{
    fac[0]=1;
    inv[0]=modpow(fac[0],mod-2,mod);
    fi(i,1,200011)
    {
        fac[i]=(i*fac[i-1])%mod;
        inv[i]=modpow(fac[i],mod-2,mod);
    }
}

LL nCr(LL n,LL r)
{
    if(n==r)
        return 1;
    return (((fac[n]*inv[r])%mod)*inv[n-r])%mod;
}

vector<PLL> vec;
int main()
{
    FastIO(); 
    pre();

    LL h,w,n,x,y;
    cin>>h>>w>>n;
    vec.resize(n+1);
    fi(i,0,n)
    {
        cin>>x>>y;
        vec[i]=mp(x,y);
    }
    vec[n]=mp(h,w);
    sort(all(vec));
    fi(i,0,n+1)
    {
        dp[i]=nCr(vec[i].X+vec[i].Y-2,vec[i].X-1);
        fi(j,0,i)
            if(vec[j].X<=vec[i].X&&vec[j].Y<=vec[i].Y)
                dp[i]=(dp[i]+mod-((dp[j]*nCr(vec[i].X-vec[j].X+vec[i].Y-vec[j].Y,vec[i].X-vec[j].X))%mod))%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}

