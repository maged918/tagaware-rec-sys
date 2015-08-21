//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 109
typedef long long ll;
ll dp[M][M];
int req[M][5];
char s[20];
int n,k;
// 0 < 1 <= 2 = 3 >= 4 >
bool ok(int a,int b,int l,int r) //a ->要放的位置左下标，b->右下标 //l ,r 原本的
{
    for(int i = 0;i < k;i++)
    {
        if((req[i][0] == a && req[i][1] == b) || (req[i][0] == b && req[i][1] == a)) //自身比较
        {
            if(req[i][2]==0 || req[i][2]==4)
                return false;
        }
        else if(req[i][0] == a || req[i][0] == b)
        {
            if(req[i][1] >= l && req[i][1] <= r)
            {
                if(req[i][2] >= 2)
                    return false;
            }
        }
        else if(req[i][1] == a || req[i][1] == b)
        {
            if(req[i][0] >= l && req[i][0] <= r)
            {
                if(req[i][2] <= 2)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    while(scanf("%d %d",&n,&k)==2)
    {
        for(int i = 0;i < k;i++)
        {
            scanf("%d %s %d",&req[i][0],s,&req[i][1]);
            if(s[0]=='<' && strlen(s)==1)
                req[i][2] = 0;
            else if(s[0] == '<') req[i][2] = 1;
            else if(s[0] == '=') req[i][2] = 2;
            else if(s[0] == '>' && strlen(s)==2) req[i][2] = 3;
            else req[i][2] = 4;
        }
        for(int l = 2;l <= 2*n;l += 2)
        {
            for(int i = 1;i <= 2*n-l+1;i++)
            {
                int j = i+l-1;
                dp[i][j] = 0;
                if(l == 2)
                {
                    if(ok(i,j,i+1,j-1))
                    {
                        dp[i][j] = 1;
                    }
                }
                else
                {
                    if(ok(i,i+1,i+2,j)) // 首
                    {
                        dp[i][j] += dp[i+2][j];
                    }
                    if(ok(j-1,j,i,j-2)) //wei
                    {
                        dp[i][j] += dp[i][j-2];
                    }
                    if(ok(i,j,i+1,j-1)) //liangbian
                    {
                        dp[i][j] += dp[i+1][j-1];
                    }
                }
            }
        }
        printf("%I64d\n",dp[1][2*n]);
    }
    return 0;
}

				    	  		   		 			   			  	