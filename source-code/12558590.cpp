//Language: GNU C++


#include<cstdio>
using namespace std;
const int MAXN=1501;
const long long MOD=1000000007;
long long n,m;
long long dp[MAXN][MAXN][2];
char a[MAXN][MAXN];
void read()
{
    long long i,j;
    char blank;
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%c",&blank);
        for(j=1;j<=m;j++)
            scanf("%c",&a[i][j]);
    }
}
void solve()
{
    long long i,j,h;
    long long x1,y1,x2,y2;
    long long answer=0LL;
    if(a[1][1]==a[n][m])dp[1][n][0]=1;
    for(i=2;i<=(n+m)/2;i++)
    {
        for(j=1;j<=n;j++)
        {
            x1=j;
            y1=i-j+1;
            if(y1<1||y1>m)continue;
            for(h=1;h<=n;h++)
            {
                x2=h;
                y2=m-i+(n-h)+1;
                if(y2<1||y2>m)continue;
                //printf("%lld %lld %lld | %lld %lld %lld %lld | %c %c\n",i,j,h,x1,y1,x2,y2,a[x1][y1],a[x2][y2]);
                if(x2<x1||y2<y1)continue;
                if(a[x1][y1]!=a[x2][y2])continue;
                //printf("%lld\n",dp[2][4][0]);
                dp[j][h][1]+=dp[j][h][0]+dp[j][h+1][0]+dp[j-1][h][0]+dp[j-1][h+1][0];
                if(dp[j][h][1]>=MOD)dp[j][h][1]%=MOD;
                //printf("! %lld %lld %lld | %lld %lld %lld %lld | %lld | %lld %lld %lld\n",i,j,h,x1,y1,x2,y2,dp[j][h][1],j-1,h+1,dp[j-1][h+1][0]);
            }
        }
        //printf("@\n");
        for(j=1;j<=n;j++)
            for(h=1;h<=n;h++)
            {
                //if(j==2&&h==4)printf("%lld\n",dp[j][h][1]);
                dp[j][h][0]=dp[j][h][1];
                dp[j][h][1]=0;
            }
    }
    for(j=1;j<=h;j++)
        for(h=1;h<=n;h++)
            answer+=dp[j][h][0];
    answer%=MOD;
    printf("%lld\n",answer);
}
int main()
{
    read();
    solve();
}

