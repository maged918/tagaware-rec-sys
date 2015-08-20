//Language: GNU C++11


#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<string>
#include<iostream>
#include<map>
using namespace std;

#define sd(a) scanf("%lld",&a)
#define pd(a) printf("%d\n",(a))
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 10000000000000000ll
#define MOD0 1000000007
#define MOD1 1000000009

typedef long long ll;
bool mark[100010];
vector<pair<ll,pair<ll,ll> > > v[2][100010];
ll d[2][100010];
ll num[100010];
ll ans[100010];
ll cnt[2][2][100010];
ll n,m,s,t;
void dijkstra(ll st,bool f)
{
    ll i;
    //n1 cur1(0,0);
    ll cur;
    for(i=0;i<100010;++i)
    {
        mark[i]=0;
        d[f][i]=INF;
    }
    priority_queue<pair<ll,ll> > q;
    //printf("size:%d\n",q.size());
    d[f][st]=0;
    cnt[f][0][st]=cnt[f][1][st]=1;
    q.push(MP(0,st));
    while(!q.empty())
    {
        pair<ll,ll> p=q.top();
        cur=p.S;
        q.pop();
        if(!mark[cur])
        {
            mark[cur]=1;
            for(i=0;i<v[f][cur].size();++i)
            {
                    if(d[f][v[f][cur][i].F]>(d[f][cur]+v[f][cur][i].S.F))
                    {
                        d[f][v[f][cur][i].F]=(d[f][cur]+v[f][cur][i].S.F);
                        q.push(MP(-d[f][v[f][cur][i].F],v[f][cur][i].F));
                        cnt[f][0][v[f][cur][i].F]=cnt[f][0][cur];
                        cnt[f][1][v[f][cur][i].F]=cnt[f][1][cur];
                    }
                    else if(d[f][v[f][cur][i].F]==(d[f][cur]+v[f][cur][i].S.F))
                    {
                        cnt[f][0][v[f][cur][i].F]=(cnt[f][0][v[f][cur][i].F]+cnt[f][0][cur])%MOD0;
                        cnt[f][1][v[f][cur][i].F]=(cnt[f][1][v[f][cur][i].F]+cnt[f][1][cur])%MOD1;
                    }
            }
        }
    }
}
void go(ll cur)
{
    mark[cur]=1;
    int i;
    /*int cnt1=0;
    if(!f)
    {
        for(i=0;i<v[0][cur].size();++i)
        {
            if(d[1][cur]==d[1][v[0][cur][i].F]+v[0][cur][i].S.F)
            {
                cnt1++;
            }
        }
    }
    if(cnt1>1)
        f=1;
    */
    for(i=0;i<v[0][cur].size();++i)
    {
        //cout<<"yo"<<' '<<v[0][cur][i].S.S<<'\n';
        //cout<<d[1][cur]<<'\n';
        //cout<<d[1][v[0][cur][i].F]<<'\n';
        //cout<<v[0][cur][i].S.F<<'\n';
        if(d[1][cur]==d[1][v[0][cur][i].F]+v[0][cur][i].S.F)
        {
            /*if(f)
            {
                if(v[0][cur][i].S.F>1)
                {
                    num[v[0][cur][i].S.S]=2;
                    ans[v[0][cur][i].S.S]=1;
                }
                else
                    num[v[0][cur][i].S.S]=3;
            }
            else
            {
                num[v[0][cur][i].S.S]=1;
            }
            if(!mark[v[0][cur][i].F])
                go(v[0][cur][i].F,f);
            */
            bool g=0;
            if((cnt[0][0][cur]*cnt[1][0][v[0][cur][i].F])%MOD0==cnt[0][0][t])
            {
                if((cnt[0][1][cur]*cnt[1][1][v[0][cur][i].F])%MOD1==cnt[0][1][t])
                {
                    g=1;
                    num[v[0][cur][i].S.S]=1;
                }
            }
            if(!g)
            {
                if(v[0][cur][i].S.F>1)
                {
                    num[v[0][cur][i].S.S]=2;
                    ans[v[0][cur][i].S.S]=1;
                }
                else
                    num[v[0][cur][i].S.S]=3;
            }
            if(!mark[v[0][cur][i].F])
                go(v[0][cur][i].F);
        }
    }
}
void go1(int cur)
{
    int i;
    mark[cur]=1;
    for(i=0;i<v[0][cur].size();++i)
    {
        if(!num[v[0][cur][i].S.S])
        {
            if(d[0][cur]+1+d[1][v[0][cur][i].F]<d[0][t])
            {
                num[v[0][cur][i].S.S]=2;
                ans[v[0][cur][i].S.S]=d[0][cur]+v[0][cur][i].S.F+d[1][v[0][cur][i].F]-d[0][t]+1;
            }
            else
            {
                num[v[0][cur][i].S.S]=3;    
            }
        }
        if(!mark[v[0][cur][i].F])
            go1(v[0][cur][i].F);
    }
}
int main()
{
    ll i,x,y,l;
    sd(n);
    sd(m);
    sd(s);
    sd(t);
    for(i=0;i<m;++i)
    {
        sd(x);
        sd(y);
        sd(l);
        v[0][x].PB(MP(y,MP(l,i)));
        v[1][y].PB(MP(x,MP(l,i)));
        num[i]=0;
    }
    dijkstra(s,0);
    dijkstra(t,1);
    for(i=0;i<=n;++i)
        mark[i]=0;
    go(s);
    for(i=0;i<=n;++i)
        mark[i]=0;
    go1(s);
    for(i=0;i<m;++i)
    {
        if(num[i]==1)
            printf("YES\n");
        else if(num[i]==2)
            printf("CAN %lld\n",ans[i]);
        else
            printf("NO\n");
    }
    /*for(i=1;i<=n;++i)
        printf("%lld ",d[0][i]);
    printf("\n");
    for(i=1;i<=n;++i)
        printf("%lld ",d[1][i]);
    cout<<'\n';
    cout<<cnt[0][0][t]<<' '<<cnt[0][1][t]<<'\n';
    cout<<cnt[1][0][t]<<' '<<cnt[1][1][t]<<'\n';
    cout<<cnt[0][0][5]<<' '<<cnt[0][1][5]<<'\n';
*/
}