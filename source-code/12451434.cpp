//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int DocFile();
int XuLi();

/* ============================================================================ */
/* ============================================================================ */

#define fi "A.INP"
#define For(i,l,r) for(int i=l; i<=r; i++)
#define Ford(i,r,l) for(int i=r; i>=l; i--)
#define pb push_back
#define ll long long
const int infi = 2e9;
const int mod = 1e9+7;
const int maxn = 2e5;
const int N = maxn+10;
typedef int mang[N];
int t, s, q;

/* ============================================================================ */
/* ============================================================================ */

int main()
{
    DocFile();
    XuLi();
}

/* ============================================================================ */
/* ============================================================================ */

int DocFile()
{
    ios_base::sync_with_stdio(0);
//    freopen(fi, "r", stdin);
    cin >> t >> s >> q;
}

/* ============================================================================ */

/* ---------------------------------- */

int XuLi()
{
    int res = 0;
    double x = s;
    while (x < t)   {
        res++;
        x += x*(q-1);
    }
    cout << res;
}
