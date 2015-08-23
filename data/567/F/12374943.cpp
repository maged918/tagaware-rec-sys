//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
ll dp[90][90];
int e[105][5];
int in(int a,int l,int r)
{
    return a>=l&&a<=r;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    memset(dp,0,sizeof(dp));
    n*=2;

    for(int i=1; i<=k; i++)
    {
        char s[10];
        scanf("%d %s %d",&e[i][0],s,&e[i][1]);
        if(s[0]=='=')
            e[i][2]=1;
        else if(s[0]=='<'&&s[1]=='=')
            e[i][2]=2;
        else if(s[0]=='>'&&s[1]=='=')
            e[i][2]=3;
        else if(s[0]=='<')
            e[i][2]=4;
        else
            e[i][2]=5;
    }
    for(int i=1; i<n; i++)
    {
        int flag=1;
        for(int x=1; x<=k; x++)
        {
            if(in(e[x][0],i,i+1)&&in(e[x][1],i,i+1))
                if(e[x][2]==4||e[x][2]==5)
                    flag=0;
        }
        if(flag)
            dp[i][i+1]=1;
    }
    for(int l=4; l<=n; l+=2)
    {
        for(int i=1; i+l-3<=n; i++)
        {
            int j=i+l-3;
            if(i>2)
            {
                int flag=1;
                for(int x=1; x<=k; x++)
                {
                    if(in(e[x][0],i-2,i-1)&&in(e[x][1],i-2,i-1))
                    {
                        if(e[x][2]==4||e[x][2]==5)
                            flag=0;
                    }
                    if(in(e[x][0],i-2,i-1)&&in(e[x][1],i,j))
                    {
                        if(e[x][2]!=2&&e[x][2]!=4)
                            flag=0;
                    }
                    if(in(e[x][1],i-2,i-1)&&in(e[x][0],i,j))
                    {
                        if(e[x][2]!=3&&e[x][2]!=5)
                            flag=0;
                    }
                }
                if(flag)
                    dp[i-2][j]+=dp[i][j];
            }
            if(j<n-1)
            {
                int flag=1;
                for(int x=1; x<=k; x++)
                {
                    if(in(e[x][0],j+1,j+2)&&in(e[x][1],j+1,j+2))
                    {
                        if(e[x][2]==4||e[x][2]==5)
                            flag=0;
                    }
                    if(in(e[x][0],j+1,j+2)&&in(e[x][1],i,j))
                    {
                        if(e[x][2]!=2&&e[x][2]!=4)
                            flag=0;
                    }
                    if(in(e[x][1],j+1,j+2)&&in(e[x][0],i,j))
                    {
                        if(e[x][2]!=3&&e[x][2]!=5)
                            flag=0;
                    }
                }
                if(flag)
                    dp[i][j+2]+=dp[i][j];
            }
            if(i>1&&j<n)
            {
                int flag=1;
                for(int x=1; x<=k; x++)
                {
                    if((e[x][0]==i-1||e[x][0]==j+1)&&(e[x][1]==i-1||e[x][1]==j+1))
                    {
                        if(e[x][2]==4||e[x][2]==5)
                            flag=0;
                    }
                    if((e[x][0]==i-1||e[x][0]==j+1)&&in(e[x][1],i,j))
                    {
                        if(e[x][2]!=2&&e[x][2]!=4)
                            flag=0;
                    }
                    if(in(e[x][0],i,j)&&(e[x][1]==i-1||e[x][1]==j+1))
                    {
                        if(e[x][2]!=3&&e[x][2]!=5)
                            flag=0;
                    }
                }
                if(flag)
                    dp[i-1][j+1]+=dp[i][j];
            }
        }
    }
    printf("%I64d\n",dp[1][n]);
    return 0;
}
