//Language: GNU C++


#include <bits/stdc++.h>
#define MAXN 100
typedef long long LL;
typedef std::pair<int,int> P;
std::vector<P> G[MAXN];
LL dp[MAXN][MAXN];
bool check(int v,int u,int l,int r)
{
    for(int i=0;i<G[v].size();i++){
        P p=G[v][i];
        if(!p.first&&p.second!=u&&p.second!=v)return false;
        else if(p.first==1&&(p.second<l||p.second>r||p.second==u))return false;
        else if(p.first==2&&(p.second<l||p.second>r))return false;
    }
    for(int i=0;i<G[u].size();i++){
        P p=G[u][i];
        if(!p.first&&p.second!=v&&p.second!=u)return false;
        else if(p.first==1&&(p.second<l||p.second>r||p.second==v))return false;
        else if(p.first==2&&(p.second<l||p.second>r))return false;
    }
    return true;
}
LL solve(int l,int r,int now)
{
    if(r-l==1){
        if(check(l,l+1,l,r))return dp[l][r]=1;
        return dp[l][r]=0;
    }
    if(~dp[l][r])return dp[l][r];
    LL &ans=dp[l][r];
    ans=0;
    if(check(l,r,l,r))ans+=solve(l+1,r-1,now+1);
    if(check(l,l+1,l,r))ans+=solve(l+2,r,now+1);
    if(check(r,r-1,l,r))ans+=solve(l,r-2,now+1);
    return ans;
}
int main() {
    int n,k;
    while(std::cin>>n>>k){
        memset(G,0,sizeof G);
        char ch[5];
        for(int i=0,u,v,w;i<k;i++){
            scanf("%d %s %d",&u,ch,&v);
            if(ch[0]=='=')w=0;
            else if(ch[0]=='<'){
                if(ch[1]=='=')w=2;
                else w=1;
            }
            else if(ch[0]=='>'){
                if(ch[1]=='=')w=2;
                else w=1;
                std::swap(u,v);
            }
            G[u].push_back(P(w,v));
        }
        memset(dp,-1,sizeof dp);
        LL ans=solve(1,2*n,1);
        printf("%I64d\n",ans);
      /*  for(int i=1;i<=2*n;i++){
            for(int j=i;j<=2*n;j++){
                if(j-i==1){
                    if(~dp[i][j])printf("dp[%d][%d]=%I64d\n",i,j,dp[i][j]);
                }
            }
        }*/
    }
    return 0;
}