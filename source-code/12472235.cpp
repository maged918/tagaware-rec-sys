//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#define Clr(a,x) memset(a,x,sizeof(a));
#define For(i,x,y) for (int i=x;i<=y;i++)
#define For_Edge(k,x) for (int k=head[u];k;k=e[k].next)
#define Dor(i,y,x) for (int i=y;i>=x;i--)
#define eps 1e-8
#define inf 2147483647
using namespace std;

/*---------------------------------------------------------------*/
int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
/*---------------------------------------------------------------*/
#define N  4005
#define M 100005
#define MOD 1000000007
int n;
long long dp[N][N],c[N][N];
int main()
{
    dp[0][0] = dp[1][1] = 1;
    for(int i = 2;i<N;i++){
        dp[i][1] = dp[i-1][i-1];
        for(int j = 2;j<=i;j++){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % MOD;
        }
    }
    for(int i = 1;i<N;i++){
        c[i][0] = c[i][i] = 1;
        for(int j = 1;j<i;j++){
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
        }
    }
     while(scanf("%d",&n)!=EOF)
    {
        long long ans = 0;
        for(int i = 0;i<n;i++){
            ans += c[n][i] * dp[i][i];
            ans %= MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}
