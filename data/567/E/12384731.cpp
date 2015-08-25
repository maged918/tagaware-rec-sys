//Language: GNU C++


//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;

struct TT{
ll a,b;
bool operator <(const TT & btt)const
    {
        return (b>btt.b);
    }
}temp;

ll inf=1LL<<60LL,dis[3][300000],dp[300000];
vector<int>Ed[3][300000],cst[3][300000];
void bfs(int s,int t)
{
    int i,j,u,v;

    for(i=0;i<=500000;i++)
        dis[t][i]=inf;
    priority_queue<TT>Q;
    dis[t][s]=0;
    TT tm;
    temp.a=s;
    temp.b=0;
    Q.push(temp);
    while(!Q.empty())
    {
        tm=Q.top();Q.pop();
        u=tm.a;
        for(i=0;i<Ed[t][tm.a].size();i++)
        {
            v=Ed[t][tm.a][i];
            if(dis[t][v]>dis[t][u]+cst[t][u][i])
            {
                dis[t][v]=dis[t][u]+cst[t][u][i];
                temp.a=v;
                temp.b=dis[t][v];
                Q.push(temp);
            }
        }
    }

}
const int sz=300000;
vector<int>Edd[sz],Num[300000];
int vis[sz],low[sz],tim[sz],par[sz];
int tm=0;
int dfs(int u,int p)
{
    vis[u]=1;
    par[u]=p;
    tim[u]=low[u]=++tm;
    int i,v;
    for( i=0;i<Edd[u].size();i++)
    {
        v=Edd[u][i];
        if(!vis[v]&&v!=p)
           {
               low[u]=min(low[u],dfs(v,u));
               if(low[v]>tim[u])
               {
                  dp[Num[u][i]]|=1;
               }
           }
           else if(v!=par[u])
                low[u]=min(low[u],tim[v]);

    }
   return low[u];
}
struct T{
int a,b,c,d,e;
}ar[300000];

bool cmp( T x, T y)
{
    if(x.a==y.a)
    {
        if(x.b==y.b)
            return x.c<y.c;
        return x.b<y.b;
    }
    return x.a<y.a;
}
bool cmpp( T x, T y)
{
    return x.d<y.d;
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    sn("%I64d %I64d %I64d %I64d",&n,&m,&s,&d);
    for(i=0;i<m;i++)
    {
        sn("%I64d %I64d %I64d",&ar[i].a,&ar[i].b,&ar[i].c);ar[i].d=i;
    }
    sort(ar,ar+m,cmp);
    e=n+1;
    for(i=0;i<m;i++)
    {
        if(i>0&&ar[i].a==ar[i-1].a&&ar[i].b==ar[i-1].b&&ar[i].c==ar[i-1].c)
        {
            dp[ar[i].d]=dp[ar[i-1].d]=3;
        }
        Ed[0][ar[i].a].pb(ar[i].b);
        Ed[1][ar[i].b].pb(ar[i].a);
        cst[0][ar[i].a].pb(ar[i].c);
        cst[1][ar[i].b].pb(ar[i].c);
    }
     bfs(s,0);
     bfs(d,1);
     h=dis[0][d];
    for(i=0;i<m;i++)
    {
        u=ar[i].a;v=ar[i].b;c=ar[i].c;
        if(dis[0][u]+dis[1][v]+c==h)
        {
            Edd[u].pb(v);
            Edd[v].pb(u);
            Num[u].pb(ar[i].d);
            Num[v].pb(ar[i].d);
        }
    }
    memset(tim,0,sizeof(tim));
    memset(vis,0,sizeof(vis));
    memset(low,0,sizeof(low));
    tm=0;dfs(s,s);
    sort(ar,ar+m,cmpp);
    for(i=0;i<m;i++)
    {
        u=dis[0][ar[i].a];
        v=dis[1][ar[i].b];
        f=h-1-u-v;
        if(dp[i]==1)
        {
            pf("YES\n");
        }
        else if(f<=0)
        {
            pf("NO\n");
        }
        else
        {
            pf("CAN %I64d\n",ar[i].c-f);
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
