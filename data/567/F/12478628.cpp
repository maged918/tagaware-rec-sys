//Language: GNU C++


#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ostream>
#include<istream>
#include<algorithm>
#include<queue>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<vector>
#define fi first
#define se second
#define pii pair<ll,int>
#define inf (1ll<<60)
#define eps 1e-8
#define ll long long
using namespace std;
const int maxn=110005;
int n,k;
int req[200][3];
ll dp[200][200];
char str[10];
//0:<,1:<=,2:=,3:>,4:>=
bool ok(int a,int b,int l,int r)
{
    for(int i=0;i<k;i++) {
        if((req[i][1]==a&&req[i][2]==b) || (req[i][1]==b&&req[i][2]==a)) {
            if(req[i][0]==0 || req[i][0]==3)
                return false;
        }
        else if(req[i][1]==a || req[i][1]==b) {
            if(req[i][2]>=l && req[i][2]<=r) {
                if(req[i][0]>=2)
                    return false;
            }
        }
        else if(req[i][2]==a || req[i][2]==b) {
            if(req[i][1]>=l && req[i][1]<=r) {
                if(req[i][0]<=2)
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    int x,y;
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++) {
        scanf("%d%s%d",&req[i][1],str,&req[i][2]);
        if(strlen(str)==1) {
            if(str[0]=='>')
                req[i][0]=3;
            else if(str[0]=='<')
                req[i][0]=0;
            else
                req[i][0]=2;
        }
        else {
            if(str[0]=='>')
                req[i][0]=4;
            else
                req[i][0]=1;
        }
    }
    for(int l=2;l<=2*n;l+=2) {
        for(int i=1;i<=n+n;i++) {
            int j=i+l-1;
            if(j>n+n)
                continue;
            dp[i][j]=0;
            if(l==2) {
                if(ok(i,j,i+1,j-1)) {
                    dp[i][j]=1;
                }
                continue;
            }
            if(ok(i,j,i+1,j-1))
                dp[i][j]+=dp[i+1][j-1];
            if(ok(i,i+1,i+2,j))
                dp[i][j]+=dp[i+2][j];
            if(ok(j-1,j,i,j-2))
                dp[i][j]+=dp[i][j-2];
          //  cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout<<dp[1][2*n];
    return 0;
}












