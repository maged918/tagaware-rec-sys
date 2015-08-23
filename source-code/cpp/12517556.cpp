//Language: GNU C++11


#pragma comment(linker, "/STACK:102400000,102400000")
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int n, m;

#define N 500010
char s[N];
struct Edge{
    int from, to, next;
}edge[N << 1];
int head[N],numedge;
void build_edge(int a,int b)
{
    int t = ++numedge;
    edge[t].from = a;
    edge[t].to = b;
    edge[t].next = head[a];
    head[a] = t;
}

int vto1[N],vto2[N],t,maxto[N], dep[N], maxdep[N];
vector<int>d[N];
void dfs(int now)
{
    d[dep[now]].push_back(now);
    vto2[now] = ++t;
    maxto[now] = vto2[now];
    maxdep[now] = dep[now];
    for(int i = head[now]; i != -1; i = edge[i].next)
    {
        int to = edge[i].to;
        dep[to] = dep[now] + 1;
        dfs(to);
        maxto[now] = max(maxto[now], maxto[to]);
        maxdep[now] = max(maxdep[now], maxdep[to]);
    }
}

int v[N];
int pre[N][26];

int main(){
    //freopen("/Users/peteryuanpan/data.txt","r",stdin);
    
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) head[i] = -1;
    for(int i = 2; i <= n; i++)
    {
        int p;
        scanf("%d",&p);
        build_edge(p, i);
    }
    scanf("%s",s+1);
    
    queue<int>q;
    q.push(1);
    t = 0;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        vto1[now] = ++t;
        for(int i = head[now]; i != -1; i = edge[i].next)
        {
            int to = edge[i].to;
            q.push(to);
        }
    }
    
    t = 0;
    dep[1] = 1;
    dfs(1);
    
    for(int i = 1; i <= n; i++)
    {
        v[vto1[i]] = s[i] - 'a';
    }
    for(int i = 1; i <= n; i++)
    {
        pre[i][v[i]] += 1;
        for(int j = 0; j < 26; j++)
        {
            pre[i][j] += pre[i-1][j];
        }
    }
    
    for(int im = 1; im <= m; im++)
    {
        int v, h;
        scanf("%d%d",&v,&h);
        if(h < dep[v] || h > maxdep[v]) printf("Yes\n");
        else
        {
            int from, to;
            int l, r, mid;
            l = 0, r = (int)d[h].size() - 1;
            while(l < r)
            {
                mid = (l + r) >> 1;
                int now = d[h][mid];
                if(vto2[v] <= vto2[now] && vto2[now] <= maxto[v]) r = mid;
                else if(vto2[now] < vto2[v]) l = mid + 1;
                else r = mid - 1;
            }
            from = vto1[d[h][l]];
            
            l = 0, r = (int)d[h].size() - 1;
            while(l < r)
            {
                mid = (l + r) >> 1;
                mid ++;
                int now = d[h][mid];
                if(vto2[v] <= vto2[now] && vto2[now] <= maxto[v]) l = mid;
                else if(vto2[now] < vto2[v]) l = mid + 1;
                else r = mid - 1;
            }
            to = vto1[d[h][l]];
            
            int nodd = 0;
            for(int i = 0; i < 26; i++)
            {
                int t = pre[to][i] - pre[from-1][i];
                if(t & 1) nodd++;
                if(nodd > 1) break;
            }
            if(((to - from + 1)&1) && nodd == 1) printf("Yes\n");
            else if(((to - from + 1)&1)==0 && nodd == 0) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}


