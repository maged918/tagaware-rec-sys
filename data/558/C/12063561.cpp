//Language: GNU C++11


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>

#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)

#define bug printf("hihi\n")

#define eps 1e-8

typedef __int64 ll;

using namespace std;

#define INF 0x3f3f3f3f
#define N 100005

int dp[N],vis[N];

void dfs(int pre,int cur,int dir,int step)
{
      if(cur>N) return ;
      if(cur==0) return ;

     // printf("%d ",cur);
      vis[cur]++;
      dp[cur]+=step;
      if(dir)
        dfs(-1,cur*2,dir,step+1);
      if(!dir)
      {
          dfs(cur,cur/2,dir,step+1);
          if(cur*2!=pre)
            dfs(-1,cur*2,1,step+1);
      }

}

int main()
{
    int i,j;
    int n;
    #ifndef ONLINE_JUDGE
     freopen("C:/Users/ksh/Desktop/in.txt","r",stdin);
    #endif

    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        int x;
        int m=n;
        while(m--)
        {
            scanf("%d",&x);
           // printf("%d :",x);
            dfs(x,x,0,0);
           // printf("\n");
        }
        int ans=INF;
        for(i=1;i<N;i++)
            if(vis[i]==n) ans=min(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
