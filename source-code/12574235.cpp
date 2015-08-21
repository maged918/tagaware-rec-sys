//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int MOD = 1e9 + 7;
int f[4001][4001];
int main()
{
    int n ;
    scanf("%d",&n);
    f[0][0] = 1;
    for (int i = 1; i <= n ; i ++)
    {
        f[i][0] = f[i-1][i-1];
        for (int j = 1 ; j <= n ; j ++)
            f[i][j] = (f[i][j-1]+f[i-1][j-1])%MOD;
    }
    printf("%d\n",f[n][n-1]);
}
