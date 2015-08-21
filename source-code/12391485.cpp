//Language: GNU C++


#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<utility>
#include<vector>
#include<list>
#include<queue>
#include<set>
#include<map>
using namespace std;
#define NSIZ 110
#define MSIZ 1000010
#define inf 1010580540
#define mxint 2147483647
#define mxll 9223372036854775807LL
#define prime15 1000000000000037LL
#define prime16 10000000000000061LL
#define mod 1000000007LL
#define F first
#define S second
#define vit(T) vector<T>::iterator
#define lit(T) list<T>::iterator
#define lrit(T) list<T>::reverse_iterator
#define sit(T) set<T>::iterator
#define mit(T1,T2) map<T1,T2>::iterator
#define MAXPQ(T) priority_queue<T>
#define MINPQ(T) priority_queue<T,vector<T>,greater<T> >
#define ab(x) ((x)<0?-(x):(x))
typedef pair<int,int> pii;
typedef pair<long long,int> pli;
typedef pair<long long,long long> pll;
typedef pair<double,double> pdd;
typedef pair<int,pair<int,int> > pip;
typedef pair<pair<int,int>,pair<int,int> > ppp;

int n, m, o, re=0;
long long res=0;
int a[NSIZ], b[NSIZ];
list<pii> lis[NSIZ];
long long dp[NSIZ][NSIZ];
bool chk[NSIZ];
void func(int d, int e){
    if(d==n){
        for(lit(pii) it=lis[e].begin(); it!=lis[e].end(); it++){
            if(it->F!=e+1)continue;
            if(it->S>=-1 && it->S<=1)continue;
            dp[d][e]=0;return ;
        }
        dp[d][e]=1;return ;
    }
//    printf("---- %d %d ----\n", d, e);
    int f=(n-d+1)*2+e-1;
    dp[d][e]=0;
    bool ch=0;
    ///case 11...
    for(lit(pii) it=lis[e].begin(); it!=lis[e].end(); it++){
        int k=it->F;
        if(k<e || k>f)continue;
        if(k==e+1 && it->S>=-1 && it->S<=1)continue;
        if(k>e+1 && k<=f && it->S<=-1)continue;
        ch=1;break;
    }
    for(lit(pii) it=lis[e+1].begin(); it!=lis[e+1].end(); it++){
        int k=it->F;
        if(k<e+1 || k>f)continue;
        if(it->S<=-1)continue;
        ch=1;break;
    }
//    printf(".%d\n", ch);
    if(!ch){
        if(dp[d+1][e+2]==-1)func(d+1,e+2);
        dp[d][e]+=dp[d+1][e+2];
    }
    ///case ...11
    ch=0;
    for(lit(pii) it=lis[f].begin(); it!=lis[f].end(); it++){
        int k=it->F;
        if(k<e || k>f)continue;
        if(k==f-1 && it->S>=-1 && it->S<=1)continue;
        if(k<f-1 && it->S<=-1)continue;
        ch=1;break;
    }
    for(lit(pii) it=lis[f-1].begin(); it!=lis[f-1].end(); it++){
        int k=it->F;
        if(k<e || k>f-1)continue;
        if(it->S<=-1)continue;
        ch=1;break;
    }
//    printf(".%d\n", ch);
    if(!ch){
        if(dp[d+1][e]==-1)func(d+1,e);
        dp[d][e]+=dp[d+1][e];
    }
    ///case 1...1
    ch=0;
    for(lit(pii) it=lis[e].begin(); it!=lis[e].end(); it++){
        int k=it->F;
        if(k<e || k>f)continue;
        if(k==f && it->S>=-1 && it->S<=1)continue;
        if(k<f && it->S<=-1)continue;
        ch=1;break;
    }
    for(lit(pii) it=lis[f].begin(); it!=lis[f].end(); it++){
        int k=it->F;
        if(k<e+1 || k>f)continue;
        if(it->S<=-1)continue;
        ch=1;break;
    }
//    printf(".%d\n", ch);
    if(!ch){
        if(dp[d+1][e+1]==-1)func(d+1,e+1);
        dp[d][e]+=dp[d+1][e+1];
    }
//    printf("%d %d = %I64d\n", d,e, dp[d][e]);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int i, j, k, l;
    long long ll=0, rr=mxll, mid;
    scanf("%d %d", &n, &m);
    for(i=0; i<m; i++){
        char c[3];
        scanf("%d %s %d", &j, c, &k);
        if(c[0]=='=')l=0;
        else if(c[0]=='<' && c[1]=='=')l=-1;
        else if(c[0]=='>' && c[1]=='=')l=1;
        else if(c[0]=='<')l=-2;
        else l=2;
        if(j==k){
            if(l>=-1 && l<=1)continue;
            printf("0");return 0;
        }
        lis[j].push_back(pii(k,l));
        lis[k].push_back(pii(j,-l));
    }
    func(1,1);
    printf("%I64d", dp[1][1]);
    return 0;
}

