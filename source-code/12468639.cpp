//Language: GNU C++11


#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=(long long)(1e9+7);
long long dp[4005][4005];

int main()
{
    int n;
    cin>>n;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=dp[i-1][i-1];
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%mod;
        }
    }
    cout<<dp[n][n-1]<<endl;
}
