//Language: GNU C++


#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int two[35];
map <int,int>ttt;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int n;
int num[100005];
int main()
{
    two[0]=1;
    for(int i=1; i<32; i++)
    {
        two[i]=2*two[i-1];
    }
    for(int i=0; i<32; i++)
    {
        ttt[two[i]]=i+1;
    }
    scanf("%d",&n);
    int nummax=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
        nummax=max(nummax,num[i]);
    }
    int g=num[0];
    for(int i=1; i<n; i++)
    {
        g=gcd(g,num[i]);
    }
    int flag=1;
    if(g==1)
        flag=0;
    for(int i=0; i<n; i++)
    {
        if(ttt[num[i]/g]==0)
        {
            flag=0;
            break;
        }
    }
    sort(num,num+n);
    int t=0;
    int tt=g;
    int ans=0;
    int anans=0;
    if(flag==0)
    {
        tt=num[0];
        for(int i=1; i<n; i++)
        {
            int gg=num[i];
            while(gg>tt)
            {
                gg/=2;
                if(gg<tt)
                    tt/=2;
            }
        }
        for(int i=0; i<n; i++)
        {
            while(1)
            {
                if(num[i]%tt==0&&ttt[num[i]/tt])
                    break;
                if(tt%num[i]==0&&ttt[tt/num[i]])
                    break;
                num[i]/=2;
                anans++;
            }
        }
    }
//    printf("%d\n",anans);
    {
        ans=9999999;
        g=tt;
        for(int i=0; i<32; i++)
        {
            if(g*two[i]>nummax)
                break;
            int tg=g*two[i];
//            printf("%d ",tg);
            int tans=0;
            for(int j=0; j<n; j++)
            {
                if(num[j]>=tg)
                {
//                        printf("!%d ",ttt[num[j]/tg]);
                    tans=tans+(ttt[num[j]/tg]-1);
                }
                else
                {
//                    printf("!%d ",ttt[tg/num[j]]);
                    tans=tans+(ttt[tg/num[j]]-1);
                }
            }
//            printf("%d\n",tans);
            ans=min(ans,tans);
        }
    }
    printf("%d\n",ans+anans);
    return 0;
}