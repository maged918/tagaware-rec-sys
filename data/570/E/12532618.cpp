//Language: GNU C++


#define N (1<<9)
#define M 1000000007
#define LL long long
#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[N][N];
LL dp[2][N][N],res;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);

	dp[0][1][n]=1;
	for(int x=2;x<=(n+m)/2+1;x++)
	{
		int y=n+m-x+2;
		memset(dp[1],0,sizeof(dp[1]));
		for(int i=1;i<=n;i++)
			for(int k=i;k<=n;k++)
			{
				int j=x-i,r=y-k;
				if(j<1 || j>m || r<1 || r>m || j>r) continue;
				if(s[i][j]!=s[k][r]) dp[1][i][k]=0;
				else dp[1][i][k]=(dp[0][i-1][k]+dp[0][i][k]+dp[0][i][k+1]+dp[0][i-1][k+1])%M;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[0][i][j]=dp[1][i][j];
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			res+=dp[1][i][j],res%=M;
	cout<<res<<endl;

	return 0;
}
