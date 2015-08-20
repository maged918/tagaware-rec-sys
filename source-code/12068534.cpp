//Language: GNU C++11


/* cf 312 div2B */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
#define N 100010

struct Node
{
    int x,t;
};
int n;
int a[N];
int cnt[N][2];
queue<Node> q;
int vis[N];

void bfs(int s,int k)
{
    Node now,next;
    //memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    now.x=s;
    now.t=0;
    vis[s]=k;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        cnt[now.x][1]+=now.t;
        cnt[now.x][0]++;
        next=now;
        next.t++;
        next.x*=2;
        if(next.x<=100000 && vis[next.x]!=k){
            q.push(next);
            vis[next.x]=k;
        }
        next=now;
        next.t++;
        next.x/=2;
        if(next.x && vis[next.x]!=k){
            q.push(next);
            vis[next.x]=k;
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            bfs(a[i],i);
        }
        int ans=INF;
        for(int i=1;i<=100000;i++){
            if(cnt[i][0]==n){
                ans=min(ans,cnt[i][1]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
