//Language: GNU C++


/// *********************************************** K
/// B *                                           * H
/// I *    Solved By : Bir Bahadur Khatri(B'ru)   * A
/// R *      Be Positive,be Happy.                * T
/// U *                                           * R
/// *********************************************** I

#include<bits/stdc++.h>

#define LL long long int
#define ULL unsigned LL
#define PI 2.0*acos(0.0)
#define D double
#define sz size()
#define PB push_back
#define cp printf("***** here here here here *****\n");
#define NL printf("\n")
#define CHR getchar()
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define S1(a) a=in<int>()
#define S2(a,b) a=in<int>(),b=in<int>()
#define S3(a,b,c) a=in<int>(),b=in<int>(),c=in<int>()
#define SL1(a) a=in<LL>()
#define SL2(a,b) a=in<LL>(),b=in<LL>()
#define SL3(a,b,c) a=in<LL>(),b=in<LL>(),c=in<LL>()
#define F(i,a,b) for(int i=a;i<b; i++)
#define R(i,a,b) for(int i=a-1;i>=b; i--)
#define all(a) a.begin(),a.end()
#define cnt_bit(a) __builtin_popcountll(a)
#define InpOut freopen("A.in","r",stdin),freopen("A1.out","w",stdout)
#define _cin ios_base::sync_with_stdio(0)
#include <time.h>

using namespace std;
template <typename T> T in(){char ch;T n = 0;bool ng = false;while (1){ch = getchar();if (ch == '-'){ng = true;ch = getchar();break;}if (ch>='0' && ch<='9')     break;}while (1){n = n*10 + (ch - '0');ch = getchar();if (ch<'0' || ch>'9')   break;}return (ng?-n:n);}
template<typename T>inline T Dist(T x1,T y1,T x2, T y2){return sqrt( SQR(x1-x2) + SQR(y1-y2) );}
template<typename T>inline T POW(T B,T P){ if(P==0) return 1; if(P&1) return B*POW(B,P-1);  else return SQR(POW(B,P/2));}
template<typename T>inline T ABS(T a) {if(a<0)return -a;else return a;}
template<typename T>inline T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template<typename T>inline T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
long long Bigmod(long long base, long long power, long long MOD){long long ret=1;while(power){if(power & 1)ret=(ret*base)%MOD;base=(base*base)%MOD;power>>=1;}return ret;}
long long ModInverse(long long number, long long MOD){return Bigmod(number, MOD-2, MOD);}
int Set(int N,int pos){ return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Chkbit(int N,int pos){return (bool)(N & (1<<pos));}
bool isVowel(char ch){ ch=toupper(ch); if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true; return false;}
bool isConst(char ch){if (isalpha(ch) && !isVowel(ch)) return true; return false;}
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
long long int toLlint(string s) { long long int sm; stringstream ss(s); ss>>sm; return sm;}

///**********************************************************//


///         0123456789
#define MX  100007
#define MOD 1000000007
#define INF (1<<28)
#define eps 1e-9

/// ==========================================////

int a[MX],b[MX],c[MX];

vector<int> A[MX][2];

struct z
{
    int u,pv;
    LL t;
    z(){}
    z(int _,LL __,int p)
    {
        u=_,t=__,pv=p;
    }
    bool operator<(const z &p) const
    {
        return (p.t<t);
    }
};

LL D1[MX][2];

int vis[MX][2];

void Dijkestra(int s,int f)
{
    priority_queue<z> Q;
    Q.push(z(s,0,-1));
    while(Q.sz) {
        z u=Q.top();Q.pop();
        int U=u.u;
        if(vis[U][f]) continue;
        D1[U][f]=min(D1[U][f],u.t);
        vis[U][f]=1;
        for(int i=0;i<A[U][f].sz;i+=2) {
            int v=A[U][f][i];
            if(D1[v][f]>D1[U][f]+A[U][f][i+1])
            Q.push( z(v,u.t+A[U][f][i+1],U) );
        }
    }
}

int Tme,Start[MX],Ed[MX];
vector<int> Adj[MX];

map< pair<int,int> ,int> mp;

void Dfs(int u,int p)
{
    Start[u]=Tme,Ed[u]=Tme++;
    for(int i=0;i<Adj[u].sz;i++) {
        int v=Adj[u][i];
        if(v==p) continue;
        if(!Start[v]){
            Dfs(v,u);
            Ed[u]=min(Ed[u],Ed[v]);
        }
        else Ed[u]=min(Ed[u],Start[v]);
    }
}

int Ok[MX];

int main()
{
    for(int i=0;i<MX;i++) {
        for(int j=0;j<2;j++) {
            D1[i][j]=(1LL<<60);
        }
    }
    int n,m,s,t;
    S3(n,m,s),S1(t);
    for(int i=1;i<=m;i++) {
        S3(a[i],b[i],c[i]);
        A[ a[i] ][0].PB(b[i]);
        A[ a[i] ][0].PB(c[i]);

        A[ b[i] ][1].PB(a[i]);
        A[ b[i] ][1].PB(c[i]);
    }
    Dijkestra(s,0),Dijkestra(t,1);
    LL Dst=D1[t][0];
    Tme=1;
    for(int i=1;i<=m;i++) {
        int lf=a[i],rg=b[i];
        LL Lft=D1[lf][0],Rgt=D1[rg][1];
        if(Lft+Rgt+c[i]==Dst) {
            Adj[lf].PB(rg);
            Adj[rg].PB(lf);
            mp[ make_pair(lf,rg) ]++;
        }
        else  {
            Ok[i]=1;
        }
    }
    Dfs(s,-1);

    for(int i=1;i<=m;i++) {
        int lf=a[i],rg=b[i];
        LL Lft=D1[lf][0],Rgt=D1[rg][1];
        if(!Ok[i]&&(Start[lf]<Ed[rg]||Start[rg]<Ed[lf])&&mp[ make_pair(lf,rg) ]==1) {
            printf("YES\n");
        }
        else {
            LL nwC=Lft+Rgt+c[i]-Dst +1;
            if(c[i]-nwC>0) printf("CAN %lld\n",nwC);
            else printf("NO\n");
        }
    }

    return 0;
}

///============= Thank You ===================///
