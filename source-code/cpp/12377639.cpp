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

LL mov[200010];
set<PII> s;
set<PII>::iterator it;
int main()
{
    FastIO(); 

    LL n,k,a,m,mn=INF;       
    cin>>n>>k>>a>>m;
    s.insert(mp(1,n)); 
    LL pos=((n-a)/(a+1));
    if(n>=a)
        pos++;
    LL ans=-1;
    fi(i,0,m)
        cin>>mov[i];
    fi(i,0,m)
    {
        it=s.upper_bound(mp(mov[i],n+1));
        it--;
        PII p=*(it);
        if(mov[i]<p.X||mov[i]>p.Y)
            continue;
        s.erase(it);
        pos-=((p.Y-p.X+1-a)/(a+1));
        if(p.Y-p.X+1>=a)
            pos--;
        if(p.X==mov[i]&&p.Y==mov[i])
            ;
        else if(p.X==mov[i])
        {
            pos+=((p.Y-mov[i]-a)/(a+1));
            if(p.Y-mov[i]>=a)
                pos++;
            s.insert(mp(mov[i]+1,p.Y));
        }
        else if(p.Y==mov[i])
        {
            pos+=((mov[i]-p.X-a)/(a+1));
            if(mov[i]-p.X>=a)
                pos++;
            s.insert(mp(p.X,mov[i]-1));
        }
        else
        {
            pos+=((mov[i]-p.X-a)/(a+1));
            if(mov[i]-p.X>=a)
                pos++;
            pos+=((p.Y-mov[i]-a)/(a+1));
            if(p.Y-mov[i]>=a)
                pos++;
            s.insert(mp(p.X,mov[i]-1));
            s.insert(mp(mov[i]+1,p.Y));
        }
        if(pos<k)
        {
            ans=i+1;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

