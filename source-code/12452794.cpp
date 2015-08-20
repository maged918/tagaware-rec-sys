//Language: GNU C++11


#include <bits/stdc++.h>

using namespace std;
#define Nmax 5005
#define MOD 1000000007
long long S2[Nmax][Nmax];

int main()
{
    ///freopen("D.in","r",stdin);
    S2[0][0] = 1;
    for(long long i = 1; i < Nmax; ++i)
        for(long long j = 1; j <= i; ++j)
            S2[i][j] = ((j*S2[i-1][j])%MOD + (S2[i-1][j-1])%MOD) % MOD;

    long long rez = 0,N;
    scanf("%I64d",&N);
    --N;
    for(int k = 1; k <= N + 1; ++k)
        rez = (rez + (k * S2[N+1][k]) % MOD )%MOD;
    printf("%I64d\n",rez);

    return 0;
}
