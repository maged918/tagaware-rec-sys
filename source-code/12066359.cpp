//Language: GNU C++11


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<math.h>
#include<cctype>
#define ll long long
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define REPP(i,a,b,t) for(int (i)=(a);(i)<=(b);(i)+=(t))
#define rep(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define repp(i,a,b,t) for(int (i)=(a);(i)>=(b);(i)-=(t))
#define PII pair<int,int>
#define fst first
#define snd second
#define MP make_pair
#define PB push_back
#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d%d",&(x),&(y))
#define RIII(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define DRI(x) int (x);scanf("%d",&(x))
#define DRII(x,y) int (x),(y);scanf("%d%d",&(x),&(y))
#define DRIII(x,y,z) int (x),(y),(z);scanf("%d%d%d",&(x),&(y),&(z))
#define RS(x) scanf("%s",x)
#define RSS(x,y) scanf("%s%s",x,y)
#define DRS(x) char x[maxn];scanf("%s",x)
#define DRSS(x,y) char x[maxn],y[maxn];scanf("%s%s",x,y)
#define MS0(a) memset((a),0,sizeof((a)))
#define MS1(a) memset((a),-1,sizeof((a)))
#define MS(a,b) memset((a),(b),sizeof((a)))
#define ALL(v) v.begin(),v.end()
#define SZ(v) (int)(v).size()

using namespace std;

const int maxn=100010;
const int INF=(1<<29);
const double EPS=0.0000000001;
const double Pi=acos(-1.0);

int n;
int a[maxn];
int cnt[maxn];
int cost[maxn];
bool vis[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    while(~RI(n)){
        MS0(cnt);
        MS0(cost);
        REP(i,1,n){
            RI(a[i]);
            queue<PII> q;
            q.push({a[i],0});
            MS0(vis);
            while(!q.empty()){
                PII u=q.front();q.pop();
                if(u.fst>=maxn||u.fst<=0||vis[u.fst]) continue;
                vis[u.fst]=1;
                cnt[u.fst]++;
                cost[u.fst]+=u.snd;
                q.push({u.fst/2,u.snd+1});
                q.push({u.fst*2,u.snd+1});
            }
        }
        int ans=INF;
        REP(i,1,maxn-1){
            if(cnt[i]==n){
                if(cost[i]<ans) ans=cost[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

















