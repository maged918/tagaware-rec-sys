//Language: GNU C++


#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("a.in");
#define MAX 4005
#define MOD 1000000007
int n, i, j;
int comb[MAX][MAX], a[MAX], b[MAX], k;

int main()
{
    cin >> n;
    comb[0][0] = 1;
    for(i = 1 ; i <= n ; i++)
    {
        comb[i][0] = 1;
        for(j = 1 ; j <= n ; j++)
        {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]);
            if(comb[i][j] >= MOD)
                comb[i][j] -= MOD;
        }
    }
    a[0] = 0;
    b[0] = 1;
    for(i = 1 ; i <= n ; i++)
    {
        a[i] = b[i] = b[i - 1];
        for(k = 0 ; k <= i - 2 ; k++)
        {
            a[i] = (1ll * a[i] + 1ll * a[i - 1 - k] * comb[i - 1][k]) % MOD;
            b[i] = (1ll * b[i] + 1ll * b[i - 1 - k] * comb[i - 1][k]) % MOD;
        }
        b[i] = (b[i] + 1) % MOD;
    }
    cout << a[n] << " ";
}
