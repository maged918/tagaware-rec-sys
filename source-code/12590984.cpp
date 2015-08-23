//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int maxm=505;
const int mod=1e9+7.5;
int n,m;
char M[maxn][maxm];
int dp[2][maxm][maxn];
bool ok(int x1,int y1,int x2,int y2)
{
    if(x1<1||x1>n||y1<1||y1>m||x2<x1||x2>n||y2<y1||y2>m)return false;
    return true;
}
int main()
{
//	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&n,&m)==2)
	{
        for(int i=1;i<=n;i++)scanf("%s",M[i]+1);
//        for(int i=1;i<=n;i++)printf("%s\n",M[i]+1);
		dp[1][1][n]=(M[1][1]==M[n][m]);

//		cout<<dp[1][1][n]<<endl;
		int mid=(n+m+2)/2;
//		cout<<mid<<endl;
		int ans=0;
		for(int x1=1;x1<=n;x1++)
			for(int y1=1;y1<=m&&x1+y1<=mid;y1++)
			{
				if(x1==1&&y1==1)continue;
				for(int x2=x1;x2<=n;x2++)
				{
					int y2=n+m+2-x1-y1-x2;
					if(y2<y1||y2>m)continue;
//					cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
					int &ret=dp[x1%2][y1][x2]=0;
					if(M[x1][y1]==M[x2][y2])
					{
						if(ok(x1-1,y1,x2+1,y2))ret=(ret+dp[(x1-1)%2][y1][x2+1])%mod;
						if(ok(x1-1,y1,x2,y2+1))ret=(ret+dp[(x1-1)%2][y1][x2])%mod;
						if(ok(x1,y1-1,x2+1,y2))ret=(ret+dp[x1%2][y1-1][x2+1])%mod;
						if(ok(x1,y1-1,x2,y2+1))ret=(ret+dp[x1%2][y1-1][x2])%mod;
					}
//					printf("%d\n",M[x1][y1]==M[x2][y2]);
//					printf("dp[%d][%d][%d][%d]=%d\n",x1,y1,x2,y2,dp[x1][y1][x2]);
					if(x1+y1==mid)
					{
//						printf("dp[%d][%d][%d][%d]=%d\n",x1,y1,x2,y2,dp[x1%2][y1][x2]);
						ans=(ans+dp[x1%2][y1][x2])%mod;
					}
				}
			}
        printf("%d\n",ans);
	}
	return 0;
}
