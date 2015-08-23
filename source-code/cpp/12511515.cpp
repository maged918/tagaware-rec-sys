//Language: GNU C++


//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<set>
#include<ctime>
#include<cmath>
#include <cstdlib>
using namespace std;
typedef __int64 LL;
const int mmax = 500010;
const int inf = 0x3fffffff;
const int mod= 1000000007;
char ss[mmax];
struct node
{
    int en,next;
}E[mmax];
int p[mmax],num;
void init()
{
    memset(p,-1,sizeof p);
    num=0;
}
void add(int st,int en)
{
    E[num].en=en;
    E[num].next=p[st];
    p[st]=num++;
}
int Times;
int deep[mmax],First[mmax],Last[mmax];
void dfs(int u,int Deep)
{
    Times++;
    First[u]=Times;
    deep[u]=Deep;
    for(int i=p[u];i+1;i=E[i].next)
    {
        int v=E[i].en;
        dfs(v,Deep+1);
    }
    Last[u]=Times;
}

int w[mmax];
struct nodes
{
    int l,r;
    int val;
    int mid()
    {
        return (l+r)>>1;
    }
}T[4*mmax];
void build(int id,int l,int r)
{
    T[id].l=l,T[id].r=r;
    T[id].val=0;
    if(l==r)
        return ;
    int mid=T[id].mid();
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
}
void update(int id,int pos,int val)
{
    if(T[id].l==T[id].r)
    {
        T[id].val^=val;
        return ;
    }
    int mid=T[id].mid();
    if(mid>=pos)
        update(id<<1,pos,val);
    else
        update(id<<1|1,pos,val);
    T[id].val=T[id<<1].val^T[id<<1|1].val;
}
int query(int id,int l,int r)
{
    if(l<=T[id].l && T[id].r<=r)
    {
        return T[id].val;
    }
    int mid=T[id].mid();
    int sum=0;
    if(mid>=l)
        sum^=query(id<<1,l,r);
    if(mid<r)
        sum^=query(id<<1|1,l,r);
    return sum;
}
struct Qu
{
    int u,h;
    int id,fg;
    bool operator < (const Qu &a) const
    {
        return h>a.h;
    }
}Op[mmax];
bool ans[mmax];
vector<int>a[mmax];
int main()
{
    int n,q;
    while(cin>>n>>q)
    {
        for(int i=0;i<mmax;i++)
            a[i].clear();
        init();
        for(int i=2;i<=n;i++)
        {
            int u;
            scanf("%d",&u);
            add(u,i);
        }
        Times=0;
        memset(deep,-1,sizeof deep);
        dfs(1,1);
        for(int i=1;i<=n;i++)
            a[deep[i]].push_back(i);
        scanf("%s",ss);
        for(int i=1;i<=n;i++)
            w[i]=(1<< ((ss[i-1])-'a') );
        build(1,1,n);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&Op[i].u,&Op[i].h);
            Op[i].id=i;
        }
        sort(Op,Op+q);
        int cnt=0;
        for(int h=n;h>=1;h--)
        {
            int sz=a[h].size();
            for(int i=0;i<sz;i++)
            {
                update(1,First[a[h][i]],w[a[h][i]]);
            }
            while(cnt<q && Op[cnt].h==h)
            {
                int u=Op[cnt].u;
                int tmp=query(1,First[u],Last[u]);
//                if(u==1)
//                {
//                    cout<<tmp<<endl;
//                }
                int cc=0;
                for(int i=0;i<26;i++)
                {
                    if(tmp&(1<<i))
                        cc++;
                }
                if(cc>1)
                    Op[cnt].fg=0;
                else
                    Op[cnt].fg=1;
                cnt++;
            }
            for(int i=0;i<sz;i++)
            {
                update(1,First[a[h][i]],w[a[h][i]]);
            }
        }
        for(int i=0;i<q;i++)
        {
            ans[Op[i].id]=Op[i].fg;
        }
        for(int i=0;i<q;i++)
        {
            if(ans[i])
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
