//Language: GNU C++11


/*************************************************************************
    > File Name: code/cf/#316/EE.cpp
    > Author: 111qqz
    > Email: rkz2013@126.com 
    > Created Time: 2015年08月15日 星期六 04时10分13秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<stack>
#define y0 abc111qqz
#define y1 hust111qqz
#define yn hez111qqz
#define j1 cute111qqz
#define tm crazy111qqz
#define lr dying111qqz
using namespace std;
#define REP(i, n) for (int i=0;i<int(n);++i)  
typedef long long LL;
typedef unsigned long long ULL;
const int inf = 0x7fffffff;
const int MOD=1E9+7;
const int N=5E2+7;
int n,m;
char st[N][N];

int dp[2][N][N];
int main()
{
    scanf("%d %d",&n,&m);
    for ( int i = 1 ; i <= n ; i++)
    {
    scanf("%s",&st[i][1]);
    }
  //  dp[0][1][n]= st[1][1]==st[n][m];
    if (st[1][1]==st[n][m])
    {
    dp[0][1][n]=1;
    }
    else
    {
    dp[0][1][n]=0;
    }
    int cur = 0;
    int mx = (m+n-2)/2;
    for ( int step = 1 ; step <= mx ; step++)
    {
    cur = cur ^ 1;
    for (int i = 1 ; i<= n ; i++)
    {
        for ( int j = 1 ; j <= n ; j++ )
        {
        dp[cur][i][j]  =0 ;
        }
    }
    
     for ( int x1 = 1 ; x1 <= n&&x1-1<=step ;x1++)
     {
        for ( int x2 = n ; x2>=1 &&n-x2<=step ;x2--)
        {
            int y1 = 1+step-(x1-1);         
            int y2 = m-step+(n-x2);         //由x1,x2 可以计算出y1,y2
            if (st[x1][y1]==st[x2][y2])
            {
            dp[cur][x1][x2] = (dp[cur][x1][x2] + dp[cur^1][x1][x2])%MOD;
            dp[cur][x1][x2] = (dp[cur][x1][x2] + dp[cur^1][x1][x2+1])%MOD;
            dp[cur][x1][x2] = (dp[cur][x1][x2] + dp[cur^1][x1-1][x2])%MOD;
            dp[cur][x1][x2] = (dp[cur][x1][x2] + dp[cur^1][x1-1][x2+1])%MOD;
            }//只有当前pic 相同的时候才转移
        }   
     }
    }
     int ans = 0;
     for ( int i = 1 ; i<= n ; i++ )
     {
         ans = (ans + dp[cur][i][i]) % MOD;
     }
     if ((m+n)%2)
     {
        for ( int i = 1 ; i<= n-1 ; i++)
        {
        ans = (ans + dp[cur][i][i+1])%MOD;
        }
     }
     cout<<ans<<endl;
  
    return 0;
}
