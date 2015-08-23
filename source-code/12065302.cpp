//Language: GNU C++11


#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std ;

typedef long long LL ;
#define maxn 200005
struct xx
{
    long long l,r;
    xx(){};
    xx(long long _l ,long long _r) {l=_l,r=_r;}
}u[maxn];
int lu=0;
bool cmp(xx a,xx b){
    if(a.l!=b.l) return a.l<b.l;
    return a.r>b.r;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        long long k,a,b,c;
        scanf("%lld%lld%lld%lld",&k,&a,&b,&c);
        long long a1=a*(1LL<<(n-k));
        long long b1=(b+1)*(1LL<<(n-k))-1;
        if(c==0)
            u[lu++]=xx(a1,b1);
        else 
        {
            if(a1>(1LL<<(n-1))) u[lu++]=xx(1LL<<(n-1),a1-1);
            if(b1<((1LL<<n)-1)) u[lu++]=xx(b1+1,(1LL<<n)-1);
        }
    }
    sort(u,u+lu,cmp);
    long long  now=(1LL<<(n-1))-1;
    long long sum=0;
    long long ans=-1;
    for(int i=0;i<lu;i++)
    {
    //  printf("%lld %lld \n",u[i].l,u[i].r);
        if(now<u[i].r)
        {
            if(now<u[i].l)
            {
                if(now+1<u[i].l) ans=now+1;
                sum+=u[i].r-u[i].l+1;
                now=u[i].r;
            }
            else
            {
                sum+=u[i].r-now;
                now=u[i].r;
            }

        }
    }
    if(now<(1LL<<n)-1) ans=now+1;
    if(sum==(1LL<<(n-1))) puts("Game cheated!");
    else if(sum+1==(1LL<<(n-1))) printf("%lld\n",ans);  
    else puts("Data not sufficient!");
}