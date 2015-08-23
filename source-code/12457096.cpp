//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;

const int Maxn = 4000 + 10, mod = 1000 * 1000 * 1000 + 7;
long long n, d[2][Maxn], fact[Maxn], c[Maxn], anss;

long long prm(long long a)
{
    long long ans = 1;
    for(int i = 31; i >= 0; i --)
    {
        ans *= ans;
        ans %= mod;
        if(((mod - 2) >> i) & 1)
            ans *= a;
        ans %= mod;
    }
    return ans;
}

void fillc()
{
    for(int i = 0; i <= n; i ++)
    {
        c[i] = (fact[n] * prm((fact[i] * fact[n - i]) % mod)) % mod;
    }
}

int main()
{
    cin >> n;
    fact[0] = 1;
    for(int i = 1; i <= n; i ++)
        fact[i] = (fact[i - 1] * i) % mod;
    fillc();
    d[0][0] = 1;
    anss = 1;
    for(int i = 1; i < n; i ++)
    {
        d[i % 2][0] = 0;
        for(int j = 1; j < n; j ++)
        {
            d[i % 2][j] = (d[(i - 1) % 2][j - 1] + (j * d[(i - 1) % 2][j]) % mod) % mod;
            anss += (c[i] * d[i % 2][j]);
            anss %= mod;
        }
    }
    cout << anss << endl;
    return 0;
}
