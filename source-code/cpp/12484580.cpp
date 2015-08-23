//Language: GNU C++


#include <iostream>
#include <stdio.h>

using namespace std;

const long long mod = 1e9 + 7;
int main()
{
    int n;
    cin>>n;
    long long dp[n+1][n+1];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i-1][i-1];
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % mod;
        }
    }
    cout<<dp[n][n-1]<<endl;
}
            
