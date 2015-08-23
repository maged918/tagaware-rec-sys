//Language: GNU C++11


#include<iostream>
#include<cstring>
#include<cstdio>
typedef long long LL;
using namespace std;
const int maxn=4010;
const int mod=1000000007;
LL g[maxn][maxn];
void init(){
    g[1][1]=1;
    g[2][1]=1;
    g[2][2]=2;
    for(int i=3;i<maxn;++i)
        for(int j=1;j<maxn;++j)
            if(j==1) g[i][j]=g[i-1][i-1];
            else g[i][j]=(g[i][j-1]+g[i-1][j-1])%mod;
    return;
}
int main(){
    init();
    int n;cin>>n;
    cout<<g[n+1][n]<<endl;
    return 0;
}