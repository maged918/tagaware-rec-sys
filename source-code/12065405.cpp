//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
int mx,cnt[100005],dis[100005],n,a[100005];
bool b[100005];
void dfs(int s,int d)
{
    if(b[s])
        return;
    b[s]=true;
    dis[s]+=d;
    cnt[s]++;
    if(mx>= s*2)
        dfs(s*2 , d+1);
    if(s/2 > 0)
        dfs(s/2, d+1);
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   
        scanf("%d",&a[i]);
        if(a[i]>mx)
            mx=a[i];
    }   
    for(int i=0;i<n;i++)
    {   
        memset(b,0,sizeof(b));
        dfs(a[i],0);
    }
    int dmax=dis[1];
    for(int i=1;i<=mx;i++)
    {
        if(cnt[i]==n)
        {
            if(dis[i]<dmax)
                dmax=dis[i];
        }
    }
    printf("%d",dmax);
    return 0;   
}