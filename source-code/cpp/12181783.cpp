//Language: GNU C++


//Naveen Sangtani
#include<bits/stdc++.h>
using namespace std;
 
typedef  long long int          LL;
typedef unsigned long long     ULL;
typedef long double            LD;
 
 
#define pb                   push_back
#define ppb                  pop_back
#define mp                   make_pair
#define ff                   first
#define ss                   second
 
 
#define PI                   acos(-1.0)
#define E                    exp(1.0)
#define EPS                  1e-9

#define sin(x)                       (sin((x*PI)/180.0)) 
#define count_1(n)                   __builtin_popcountll(n)
#define ln(x)                        63-__builtin_clzll(x)
#define DIST(x1,y1,x2,y2)            ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define AREA(x1,y1,x2,y2,x3,y3)      (abS((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2.0))
 
 
 
#define fr(i,a,b)            for(int i=a;i<=b;++i)
#define rev(i,b,a)           for(int i=b;i>=a;--i)
#define foreach(v,c)         for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define CLR(A)               memset(A,false,sizeof(A))
#define FILL(A,n,val)        for(int i=0;i<n;++i) A[i]=val
#define all(x)               x.begin(),x.end()
#define TT()                 int tc;cin>>tc;while(tc--)
 
 
#define bug1(a)              cerr<<#a<<" = "<<a<<endl;
#define bug2(a,b)            cerr<<#a<<" = "<<a<<" :: "<<#b<<" = "<<b<<endl;
#define bug3(a,b,c)          cerr<<#a<<" = "<<a<<" :: "<<#b<<" = "<<b<<" :: "<<#c<<" = "<<c<<endl;
#define bug4(a,b,c,d)        cerr<<#a<<" = "<<a<<" :: "<<#b<<" = "<<b<<" :: "<<#c<<" = "<<c<<" :: "<<#d<<" = "<<d<<endl;
#define dbgA(A,n)            cerr<<endl;fr(i,0,n-1) cerr<<i<<" == > "<<A[i]<<endl;
#define dbgV(V)              cerr<<endl;fr(i,0,V.size()-1){cerr<<i<<" ==> "<<V[i].ff<<" "<<V[i].ss<<endl;}
#define dbgG(G,n)            cerr<<endl;fr(i,1,n){cerr<<i<<" ==> ";fr(j,0,(G[i].size())-1) cerr<<"("<<G[i][j].ff<<" , "<<G[i][j].ss<<")"<<"  ";cerr<<endl;}
#define ns                   cerr<<endl<<" ----- entered -----"<<endl;
#define SP                   system("pause");
 
 
#define maX(a,b)                ((a)>(b)?(a):(b))
#define miN(a,b)                ((a)<(b)?(a):(b))
#define abS(x)                  ((x)<0?-(x):(x))
 


typedef pair<int,int>            PII;
typedef vector<int>               VI;
typedef vector<PII>             VPII;
typedef vector<VPII>           VVPII;
typedef set<int>                  SI;
typedef set<PII>                SPII;
typedef map<string,int>         MPSI;
 
 
typedef pair<LL,LL>              PLL;
typedef vector<LL>                VL;
typedef vector<PLL>             VPLL;
typedef vector<VPLL>           VVPLL;
typedef set<LL>                   SL;
typedef set<PLL>                SPLL;
typedef map<LL,LL>              MPLL;
 
 
LL gcd(LL x, LL y) {return y == 0 ? x : gcd(y, x % y);}
LL power(LL x,LL y){LL temp = 1 ;while(y>0){if(y&1) temp = (temp*x);x*=x;y/=2;}return temp;}
bool isPalin(string x) {LL len = x.length();fr(i,0,(len/2)-1) {if (x[i] != x[len - 1 - i])return false;}return true;}
string tolowerStr(string x){string ret = "";fr(i,0,(LL)x.length()-1) {ret.pb(tolower(x[i]));}return ret;}
string toupperStr(string x) {string ret = "";fr(i,0,(LL)x.length()-1) {ret.pb(toupper(x[i]));}return ret;}
LL modulo(LL a,LL b,LL c){LL x = 1;LL y = a; while(b > 0){if(b%2 == 1){x=(x*y)%c;}y = (y*y)%c; b /= 2;}return x%c;}
LL mulmod(LL a,LL b,LL c){LL x = 0; LL y = a%c;while(b > 0){if(b%2 == 1){x = (x+y)%c;}y = (y*2)%c;b /= 2;}return x%c;}
LL DigitSum(LL n) {LL temp = 0; n = abS(n); while(n){temp += (n%10); n/=10; } return temp;}
bool double_equals(double a, double b, double epsilon = 0.1){return std::abs(a - b) < epsilon;}
bool comp(PLL a,PLL b){if(a.ff<b.ff)return true;else if(a.ff>b.ff)return false;else {if(a.ss>b.ss)return true;else return false;}}
 
 
#define INF                 INT_MAX
#define LINF                LONG_LONG_MAX
#define MAX                 1000007
#define MOD                 1000000007
 
//bool prime[1000005];void seive(){prime[0]=1;prime[1]=1;for(int i=2;i*i<=MAX;++i)if(!prime[i])for(int j=2*i;j<MAX;j+=i)if(!prime[j])prime[j]=1;}
//int ib[65];int I2B(LL x){CLR(ib);int k = 63;while(x>0){ib[k--] = x%2;x/=2;}}


int main()
{
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    
    LL a,b,c,d,ee,f;
    LD a1,a2,a3,a4,a5,a6;
    LD s1,area1,area2,area3,harea,tri,l1,l2,l3,area4;
    LL ans1;
    cin>>a>>b>>c>>d>>ee>>f;
    
    a1 = a;
    a2 = b;
    a3 = c;
    a4 = d;
    a5 = ee;
    a6 = f;
    //bug4(a1,a2,a3,a4);
    
    //cs = cos ( 120.0 * PI / 180.0 );
    l1 = (sqrtl((a1*a1)+(a2*a2)+(a1*a2)));
    l2 = (sqrtl((a3*a3)+(a4*a4)+(a3*a4)));
    l3 = (sqrtl((a5*a5)+(a6*a6)+(a5*a6)));
    //bug3(l1,l2,l3);
    
    s1 = (a1+a2+l1)/2.0;
    area1 = sqrtl(s1*(s1-a1)*(s1-a2)*(s1-l1));
    s1 = (a3+a4+l2)/2.0;
    area2 = sqrtl(s1*(s1-a3)*(s1-a4)*(s1-l2));
    s1 = (a5+a6+l3)/2.0;
    area3 = sqrtl(s1*(s1-a5)*(s1-a6)*(s1-l3));
    s1 = (l1+l2+l3)/2.0;
    area4 = sqrtl(s1*(s1-l1)*(s1-l2)*(s1-l3));
    
    harea = area1+area2+area3+area4;
    
    //bug1(harea);
    s1 = (1.0+1.0+1.0)/2.0;
    //bug1(s1);
    tri = sqrtl(s1*(s1-1.0)*(s1-1.0)*(s1-1.0));
    //bug1(tri);
    LD ans = (harea/tri);
    //bug1(ans);
    ans1 = ans;
    
    LD temp1 = ans1*tri;
    LD temp2 = (ans1+1)*tri;
    LD temp3 = (ans1-1)*tri;
    
    if(double_equals(temp1,harea))
    cout<<ans1<<endl;
    
    else if(double_equals(temp2,harea))
    cout<<ans1+1<<endl;
    
    else if(double_equals(temp3,harea))
    cout<<ans1-1<<endl;
    
    
return 0;
}
