//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long dp[100][100];
long long rel[100][100];
vector<int>X[100];
bool ok(int d,int x,int y)
{
    for(int i=0; i<X[d].size(); i++)if(X[d][i]>=x&&X[d][i]<=y)return false;
    return true;
}
long long solve(int l,int r)
{
    if(l>r)return 1;
    if(dp[l][r]!=-1)return dp[l][r];
    long long ans=0;
    long long A=rel[l][r],B=rel[l][l+1],C=rel[r-1][r];
    if(r-l==1)
    {
        if(A!=1&&A!=2)ans+=solve(l+1,r-1);
    }
    else
    {
        if(A!=1&&A!=2&&ok(l,l+1,r-1)&&ok(r,l+1,r-1))ans+=solve(l+1,r-1);
        if(B!=1&&B!=2&&ok(l,l+2,r)&&ok(l+1,l+2,r))ans+=solve(l+2,r);
        if(C!=1&&C!=2&&ok(r,l,r-2)&&ok(r-1,l,r-2))ans+=solve(l,r-2);
    }
    return dp[l][r]=ans;
}
int main()
{
    cin>>n>>k;
    for(int i=1; i<=k; i++)
    {
        long long a,b;
        string x;
        cin>>a>>x>>b;
        //if(a>b)swap(a,b);
        if(x==">")rel[a][b]=1,rel[b][a]=2,X[a].push_back(b);
        else if(x=="<")rel[a][b]=2,rel[b][a]=1,X[b].push_back(a);
        else if(x=="=")rel[a][b]=3,rel[b][a]=3,X[a].push_back(b),X[b].push_back(a);
        else if(x==">=")rel[a][b]=4,rel[b][a]=5,X[a].push_back(b);
        else if(x=="<=")rel[a][b]=5,rel[b][a]=4,X[b].push_back(a);
    }
    memset(dp,-1,sizeof dp);
    cout<<solve(1,2*n)<<endl;
}

