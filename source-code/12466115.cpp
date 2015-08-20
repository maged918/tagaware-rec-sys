//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#define N 2000000
using namespace std;
int su[N];
bool u[N];
int n[N];
void sai()
{
    memset(u,true,sizeof(u));
    int s=1;
    u[1] = false;
    for(int i=2; i<N; i++)
    {
        if(u[i]) su[s++]=i;
        for(int j=1; j<s; j++)
        {
            if(i*su[j]>N) break;
            u[i*su[j]]=false;
            if(i%su[j]==0) break;
        }
    }
    int sum=0;
    for(int i=1;i<N;i++)
    {
        if(u[i])
            sum++;
        n[i]=sum;
    }
}
bool judge(int x)
{
    int a[15];
    int c=1;
    while(x)
    {
        a[c++] = x%10;
        x /=10;
    }
    int r = c/2;
    for(int i=1;i<=r;i++)
    {
        if(a[i] != a[c-i])
            return false;
    }
    return true;
}
int rub[N];
void huiwen()
{
    int sum=0;
    for(int i=1;i<N;i++)
    {
        if(i<10 || judge(i))
            {
                //printf("i==%d\n",i);
                sum++;
            }
        rub[i]=sum;
    }
}
int main()
{
    int p ,q;
    sai();
    huiwen();
    while( ~scanf("%d%d",&p,&q))
    {
        int ans=1;
        for(int i=1; i<N;i++)
        {
            //printf("i==%d  nn=%d rub==%d\n",i,n[i],rub[i]);
            if(n[i]*q <= rub[i]*p)
            {
                ans=i;
            }
          // else break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
