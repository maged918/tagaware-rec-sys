//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
vector<int>f[555555];
vector<int>g[555555];
vector<int> myxor[555555];
int m,n;
char s[555555];
int tim,fst[555555],nxt[555555];
int x,y;
int maxdeep=0;
int hsh[555555];

void dfs(int u,int dis)
{
    tim++;
    fst[u]=tim;
    hsh[tim]=u;
    f[dis].push_back(tim);
    for(unsigned int i=0;i<g[u].size();i++)
        dfs(g[u][i],dis+1);
    nxt[u]=tim;
    maxdeep=max(maxdeep,dis);
}

void work(int l,int r,int d,int &ans)
{
    r--;
    l--;
    int ret;
    if(r<0)
        return;
        
    ret=myxor[d][r];
    if(l>=0)
        ret^=myxor[d][l];
    while(ret)
    {
        ans=ans+(ret&1);
        ret>>=1;
    }
}

int main()
{
    scanf("%d%d",&m,&n);
    for(int i=2;i<=m;i++)
    {
        scanf("%d",&x);
        g[x].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        scanf(" %c",&s[i]);
    }
    dfs(1,1);
    for(int i=1;i<=maxdeep;i++)
    {
        myxor[i].push_back(1<<(s[hsh[f[i][0]]]-'a'));

        for(int j=1;j<f[i].size();j++)
        {
            myxor[i].push_back((1<<(s[hsh[f[i][j]]]-'a'))^myxor[i][j-1]);
        }
    }
    
    int has;
    for(int ti=1;ti<=n;ti++)
    {
        has=0;
        scanf("%d%d",&x,&y);        //root x    deepth y
        int l =lower_bound(f[y].begin(),f[y].end(),fst[x])-f[y].begin();
        int r =upper_bound(f[y].begin(),f[y].end(),nxt[x])-f[y].begin();
        //cout<<"fl="<<fl<<" fr="<<fr<<endl;
        work(l,r,y,has);
        if(has<2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
