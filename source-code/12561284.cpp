//Language: GNU C++


#pragma comment(linker,"/STACK:102400000,1024000")
#include <iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct node{
    int h,index;
};
struct point{
    short int ans[26];
};
vector<int> a[510000],r[510000];
vector<point> f[510000];
vector<node> c[510000];
int ans[510000],b[510000];
char ch[510000];
void dfs(int index,int h)
{
    int i,j,d1,t1,t2,t3;
    point p;
    for(i=0;i<c[index].size();i++)
        r[index].push_back(f[c[index][i].h].size()-1);
    for(i=0;i<a[index].size();i++)
        dfs(a[index][i],h+1);

    if (index==1)
    {
        int fft=1;
    }
    t1=f[h].size()-1;

    for(i=0;i<26;i++)
        p.ans[i]=f[h][t1].ans[i];
    p.ans[b[index]]=1-p.ans[b[index]];
    f[h].push_back(p);

    for(i=0;i<c[index].size();i++)
    {
        if (c[index][i].h<h)
        {
            ans[c[index][i].index]=1;
            continue;
        }
        d1=c[index][i].h;
        t1=r[index][i];
        t2=f[d1].size()-1;
        t3=0;
        for(j=0;j<26;j++)
            if ((f[d1][t1].ans[j]+f[d1][t2].ans[j])%2==1) t3++;
        if (t3>1) ans[c[index][i].index]=0;
        else
            ans[c[index][i].index]=1;
    }
}
int main()
{
    int n,m,i,x,y;
    point p1;
  /*  freopen("111.txt","r",stdin);
    freopen("222.txt","w",stdout);
    printf("500000 1\n");
    for(i=1;i<500000;i++)
        printf("1 ");
    printf("\n");
    for(i=1;i<=500000;i++)
        printf("a");
    printf("\n");
    printf("1 2\n");*/
    while(scanf("%d%d",&n,&m)!=EOF)
    {

        for(i=0;i<26;i++)
            p1.ans[i]=0;
        for(i=1;i<=n;i++)
            f[i].push_back(p1);
        for(i=1;i<=n;i++)
        {
            c[i].clear();
            a[i].clear();
            r[i].clear();
        }
        for(i=1;i<n;i++)
        {
            scanf("%d",&x);
            a[x].push_back(i+1);
        }
        scanf("%s",ch);
        for(i=1;i<=n;i++)
            b[i]=ch[i-1]-'a';
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            node tmp;
            tmp.h=y;
            tmp.index=i;
            c[x].push_back(tmp);
        }
        dfs(1,1);
        for(i=1;i<=m;i++)
            if (ans[i]==1) printf("Yes\n");
            else
                printf("No\n");
    }
    return 0;
}
