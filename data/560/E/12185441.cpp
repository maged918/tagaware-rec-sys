//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N=100010;
const long long pr=(long long)((1e9)+7);
long long ans,p[N*2],f[2010],g[2010],q[N*2];
struct node
{
    int x,y;
}s[2010];
int h,w,n;

long long quick(long long a,long long b)
{
    long long ret=1LL;
    for(a%=pr;b;b>>=1LL)
    {
        if(b&1LL)
        {
            ret*=a;
            ret%=pr;
        }
        a*=a;
        a%=pr;
    }
    return ret;
}
long long cal(int x,int y)
{
    long long ret;
    ret=p[x];
    ret*=q[x-y];
    if(ret>=pr) ret%=pr;
    ret*=q[y];
    if(ret>=pr) ret%=pr;
    return ret;
}
bool cmp(node n1,node n2)
{
    if(n1.x!=n2.x) return n1.x<n2.x;
    return n1.y<n2.y;
}

int main()
{
    scanf("%d%d%d",&h,&w,&n);
    p[0]=1LL;
    for(int i=1;i<=h+w;i++)
    {
        p[i]=p[i-1]*(long long)i;
        if(p[i]>=pr) p[i]%=pr;
    }
    for(int i=0;i<=h+w;i++)
    {
        q[i]=quick(p[i],pr-2LL);
        if(q[i]>=pr) q[i]%=pr;
    }
    for(int i=0;i<n;i++)
        scanf("%d%d",&s[i].x,&s[i].y);
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++)
    {
        f[i]=cal(s[i].x+s[i].y-2,s[i].x-1);
        for(int j=0;j<i;j++)
            if(s[i].x>=s[j].x&&s[i].y>=s[j].y)
            {
                long long tmp=f[j]*cal(s[i].x-s[j].x+s[i].y-s[j].y,s[i].x-s[j].x);
                if(tmp>=pr) tmp%=pr;
                f[i]-=tmp;
                if(f[i]<0) f[i]+=pr;
            }
    }
  //  cout<<f[0]<<" "<<f[1]<<" "<<f[2]<<endl;
    for(int i=n-1;i>=0;i--)
    {
        g[i]=cal(w+h-s[i].x-s[i].y,h-s[i].x);
     /*   for(int j=n-1;j>i;j--)
            if(s[i].x<=s[j].x&&s[i].y<=s[j].y)
            {
                g[i]-=g[j];
                if(g[i]<0) g[i]+=pr;
            }*/
    }
   // cout<<g[0]<<" "<<g[1]<<" "<<g[2]<<endl;
    ans=cal(w+h-2,w-1);
    for(int i=0;i<n;i++)
    {
        long long tmp=f[i]*g[i];
        tmp%=pr;
        ans-=tmp;
        if(ans<0) ans+=pr;
    }
    cout<<ans<<endl;
    return 0;
}
