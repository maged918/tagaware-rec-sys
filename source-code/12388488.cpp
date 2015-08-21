//Language: GNU C++11


#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>

#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)

#define bug printf("hihi\n")

#define eps 1e-8
typedef __int64 ll;

using namespace std;
#define INF 0x3f3f3f3f
#define N 100005

set<int>s;
set<int>::iterator it,itt;
int len,n,a;

int fdd(int le,int ri)
{
     int temp=(ri-le-1);
     int te=temp/(a+1);
     if(temp%(a+1)==a) te++;
     return te;
}

int main()
{
    int i,j;
    while(~scanf("%d%d%d",&len,&n,&a))
    {
        s.clear();
        s.insert(0);
        s.insert(len+1);
        int all=len/(a+1);
        if(len%(a+1)==a) all++;

       // printf("%d %d %d\n",len,a,all);

        int ans=-1;
        int m,x;
        scanf("%d",&m);

       // continue;
        for(i=1;i<=m;i++)
        {

            scanf("%d",&x);

            if(ans!=-1) continue;
            it=s.upper_bound(x);
            itt=it;
            itt--;

            all-=fdd(*itt,*it);
            all+=fdd(x,*it);
            all+=fdd(*itt,x);
            if(all<n) ans=i;
            s.insert(x);

        }
        printf("%d\n",ans);
    }
    return 0;
}
