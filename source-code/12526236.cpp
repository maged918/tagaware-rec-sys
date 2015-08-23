//Language: GNU C++


//author: WHW
//First Edit Time:	2015-08-14 10:44
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <limits>
using namespace std;
typedef long long LL;
const int MAXN=1e+4;
const int MAXM=1e+5;
const int INF = numeric_limits<int>::max();
const LL LL_INF= numeric_limits<LL>::max();
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int n,m;
int dep[500010],has[500010];
vector<int> v[500010];
struct node
{
    int chu,ru;
}f[500010];
char str[500010];
int dfsxu;
int shu[500010],vis[500010];
void dfs(int x,int deep)
{
    dep[x]=deep;
    f[x].chu=dfsxu++;
    vis[f[x].chu]=x;
    for(int i=0;i<v[x].size();i++)
    {
        dfs(v[x][i],deep+1);
    }
    f[x].ru=dfsxu;
}
bool cmp(int a,int b)
{
    if(dep[vis[a]]==dep[vis[b]])
        return a<b;
    return dep[vis[a]]<dep[vis[b]];
}
int sum[500010<<2];
void Init()
{
    memset(sum,0,sizeof sum);
}
void Pushup(int rt)
{
    sum[rt]=((sum[rt<<1])^(sum[rt<<1|1]));
}
void Build(int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]^=(1<<(str[vis[shu[l-1]]]-'a'));
        //printf("%d:%c %d %d %d\n",l,str[vis[shu[l-1]]],vis[shu[l-1]],shu[l-1],sum[rt]);
        return ;
    }
    int m=(l+r)>>1;
    if(m>=l) Build(lson);
    if(m<r) Build(rson);
    Pushup(rt);
    //printf("%d %d %d\n",l,r,sum[rt]);
}
int Query(int L,int R,int l,int r,int rt)
{
    //printf("%d %d %d\n",l,r,sum[rt]);
    if(l>=L&&r<=R)
    {
        return sum[rt];
    }
    int m=(l+r)>>1,su=0;
    if(m>=L) su^=Query(L,R,lson);
    if(m<R) su^=Query(L,R,rson);
    return su;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<=n;i++)
            v[i].clear();
        for(int i=2,x;i<=n;i++)
        {
            scanf("%d",&x);
            v[x].push_back(i);
        }
        scanf("%s",str+1);
        dfsxu=1;
        dfs(1,1);
        for(int i=0;i<n;i++)
            shu[i]=i+1;
        sort(shu,shu+n,cmp);
        memset(has,0,sizeof has);
        int yingshe=1;
        has[yingshe]=0;
        for(int i=0;i<n;i++)
        {
            if(dep[vis[shu[i]]]==yingshe)
            {
                ;
            }
            else
            {
                yingshe++;
                has[yingshe]=i;
                //printf("%d %d\n",yingshe,i);
            }
        }
        for(int i=yingshe+1;i<=n;i++)
            has[i]=n;
        Init();
        Build(1,n,1);
        //for(int i=0;i<n;i++)
            //printf("%d ",shu[i]);
        //puts("");
        //for(int i=1;i<=n;i++)
            //printf("%d ",has[i]);
        //puts("");
        for(int i=0,vi,hi;i<m;i++)
        {
            scanf("%d%d",&vi,&hi);
            if(dep[vi]>=hi)
                puts("Yes");
            else
            {
                int ai,bi;
                ai=lower_bound(shu+has[hi],shu+has[hi+1],f[vi].chu)-shu;
                bi=lower_bound(shu+has[hi],shu+has[hi+1],f[vi].ru)-shu;
                bi--;
                int pan=Query(ai+1,bi+1,1,n,1);
                //printf("%d %d %d %d %d %d %d\n",has[hi],has[hi+1]-1,f[vi].chu,f[vi].ru,ai,bi,pan);
                int biao=0;
                for(int j=0;j<26;j++)
                {
                    if((pan>>j)&1)
                        biao++;
                }
                if(biao>1)
                    puts("No");
                else puts("Yes");
            }
        }
    }
    return 0;
}
