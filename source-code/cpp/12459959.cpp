//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
typedef long long num;
const int MN = 4002;
const num MOD = 1000000007;
num comb[MN][MN], bell[MN], n, ans, aux, k;

int main()
{
    cin >> n;
    for(int i=0;i<n+1;i++)
        comb[i][0] = 1;
    for(int i=1;i<n+1;i++)
        for(int k=1;k<i+1;k++)
            comb[i][k] = (comb[i-1][k] + comb[i-1][k-1])%MOD;
    bell[0] = bell[1] = 1;
    for(int i=2; i<n+1;i++)
        for(int j=0;j<i;j++)
            bell[i] = (bell[i] + comb[i-1][j]*bell[j] )%MOD;

    ans = 0;
    for(int k=1;k<n+1;k++)
        ans = (ans + comb[n][k]*bell[n-k])%MOD;

    cout << (ans+MOD)%MOD << endl;
}
