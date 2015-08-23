//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define maxN 500005
vector<int> eh[maxN];
vector<int> table[maxN];
vector<int> pix[maxN];
int N,M;
int p[maxN],d[maxN],in[maxN],out[maxN];
char val[maxN];
int index;
void init()
{
    index = 1;
    //for(int i=1;i<=N;i++) eh[i].clear();
    //for(int i=1;i<=N;i++) table[i].clear();
    //for(int i=1;i<=N;i++) pix[i].clear();
}
void dfs(int u,int f)
{
    d[u] = f;
    in[u] = index++;
    table[f].push_back(u);
    int fsize = pix[f].size();
    if(fsize==0) pix[f].push_back(1<<(val[u]-'a'));
    else  pix[f].push_back((1<<(val[u]-'a'))^pix[f][fsize-1]);
    int len = eh[u].size();
    for(int i=0;i<len;i++)
    {
        int v=eh[u][i];
        dfs(v,f+1);
    }
    out[u]=index++;
}
bool isleft(int a,int b)
{
    return out[b]<in[a];
}
bool isright(int a,int b)
{
    return in[b]>out[a];
}
bool solve(int v,int h)
{
    if(h<=d[v]) return true;
    int low = 0,high=table[h].size()-1;
    if(high==-1) return true;
    while(low<high)
    {
        int mid = (low+high)/2;
        int x = table[h][mid];
        if(isleft(v,x)) low = mid+1;
        else if(isright(v,x)) high = mid-1;
        else high = mid;
    }
    int a = low;
    if(!(in[table[h][a]]>in[v]&&out[table[h][a]]<out[v])) return true;
    low = 0,high = table[h].size()-1;
    while(low<high)
    {
        int mid = (low+high+1)/2;
        int x = table[h][mid];
        if(isleft(v,x)) low = mid+1;
        else if(isright(v,x)) high = mid-1;
        else low = mid;
    }
    int b = high;
    int odd = 0;
    int res = a==0?pix[h][b]:pix[h][a-1]^pix[h][b];
    while(res>0)
    {
        if(res%2==1) odd++;
        res/=2;
    }
    if(odd<2) return true;
    else return false;
}
int main()
{
    //freopen("data.txt","r",stdin);
    //freopen("ans.txt","w",stdout);
    int h,v;
    while(scanf("%d %d",&N,&M)!=EOF)
    {
        int pa;
        init();
        for(int i=2;i<=N;i++)
        {
            scanf("%d",&pa);
            eh[pa].push_back(i);
        }
        scanf("%s",val+1);
        dfs(1,1);
        while(M--)
        {
            scanf("%d %d",&v,&h);
            if(solve(v,h)) printf("Yes\n");
            else printf("No\n");
        }
    }
}
