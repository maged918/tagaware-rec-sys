//Language: GNU C++


#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")

using namespace std;
#define   MAX       200005
#define   MAXN      2000005
#define   lson      l,m,rt<<1
#define   rson      m+1,r,rt<<1|1
#define   lrt       rt<<1
#define   rrt       rt<<1|1
#define   mid       int m=(r+l)>>1
#define   LL        long long
#define   ull       unsigned long long
#define   mem0(x)   memset(x,0,sizeof(x))
#define   mem1(x)   memset(x,-1,sizeof(x))
#define   meminf(x) memset(x,INF,sizeof(x))
#define   lowbit(x) (x&-x)

const LL     mod   = 1000000;
const int    prime = 999983;
const int    INF   = 0x3f3f3f3f;
const int    INFF  = 1e9;
const double pi    = 3.141592653589793;
const double inf   = 1e18;
const double eps   = 1e-10;

/**************读入外挂*********************/
inline int read_int(){
    int ret=0;
    char tmp;
    while(!isdigit(tmp=getchar()));
    do{
        ret=(ret<<3)+(ret<<1)+tmp-'0';
    }while(isdigit(tmp=getchar()));
    return ret;
}
/*******************************************/

int len[MAX];
int miss[MAX];
set<int> ss;
int main(){
    int n,k,a,m;
    scanf("%d%d%d%d",&n,&k,&a,&m);
    int flag=-1;
    int num=(n+1)/(a+1);
    ss.insert(1);
    len[1]=n;
    mem0(miss);
    for(int i=1;i<=m;i++){
        int t;
        scanf("%d",&t);
        if(flag!=-1||miss[t]) continue;
        set<int>::iterator it=ss.upper_bound(t);
        it--;
        int x=*it;
        ss.erase(x);
        int p=(t-x+1)/(a+1);
        int q=(len[x]-t+1)/(a+1);
        num-=((len[x]-x+1+1)/(a+1))-(p+q);
        if(num<k) flag=i;
        else{
            if(t!=len[x]) ss.insert(t+1);
            if(t!=x) ss.insert(x);
            len[t+1]=len[x];
            len[x]=t-1;
        }
        miss[t]=1;
    }
    printf("%d\n",flag);
    return 0;
}
