//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int mmax = 100010;
const int mod  = 1000000007;
typedef __int64 LL;
LL dp[2][510][510];
char ss[510][510];
int n,m;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
bool in(int x,int y)
{
    return 0<=x&&x<n && 0<=y && y<m;
}
int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
            scanf("%s",ss[i]);
        if(ss[0][0]!=ss[n-1][m-1] ) 
        {
            puts("0");
            continue;
        }
        int fg=0;
        memset(dp[fg],0,sizeof dp[fg]);
        dp[fg][0][n-1]=1;
        for(int len=1;len<(n+m)/2;len++)
        {
            memset(dp[fg^1],0,sizeof dp[fg^1]);
            for(int i=0;i<n;i++)
            {
                int x=i,y=len-1-x;
                if(!in(x,y))
                    continue;
                for(int j=0;j<n;j++)
                {
                    int tx=j,ty=n+m-1-tx-len;
                    if(!in(tx,ty))
                        continue;
                    //cout<<len<<"->>"<<endl;
                    //cout<<x<<" "<<y<<endl;
                    //cout<<tx<<" "<<ty<<endl;
                    //cout<<"------"<<endl;
                    for(int k=0;k<2;k++)
                    {
                        for(int e=2;e<4;e++)
                        {
                            int xx=x+dir[k][0];
                            int yy=y+dir[k][1];
                            int txx=tx+dir[e][0];
                            int tyy=ty+dir[e][1];
                            if(in(xx,yy) && in(txx,tyy) && ss[xx][yy]==ss[txx][tyy])
                            {
                                //cout<<len<<endl;
                                //cout<<xx<<" "<<yy<<endl;
                                //cout<<txx<<" "<<tyy<<endl;
                                //cout<<"------"<<endl;
                                dp[fg^1][xx][txx]+=dp[fg][i][j];
                                dp[fg^1][xx][txx]%=mod;
                            }
                        }
                    }
                }
            }
            fg^=1;
        }
        LL ans=0;
        if((n+m-1)&1)
            for(int i=0;i<n;i++)
                ans+=dp[fg][i][i],ans%=mod;
        else
            for(int i=0;i<n;i++)
            {
                ans+=dp[fg][i][i];
                if(i+1<n)
                    ans+=dp[fg][i][i+1];
                ans%=mod;
            }
        cout<<ans<<endl;
    }
    return 0;
}
