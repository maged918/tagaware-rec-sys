//Language: GNU C++


#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, n) for (int i = 1; i <= n; i++)
#define ForK(i, k, n) for (int i = k; i <= n; i++)
#define ForD(i, n) for (int i = n; i >= 0; i--)
#define Rep(i, n) for (int i = 0; i < n; i++)
#define RepD(i, n) for (int i = n; i >= 0; i--)
#define MemI(a) memset(a, 0, sizeof(a))
#define MemC(a) memset(a, '\0', sizeof(a))
#define PI acos(-1)
#define eps 1e-8
#define inf 0x3f3f3f3f
typedef long long ll;
using namespace std;

int main()
{
    int a1, b1, a2, b2, a3, b3;
    while (~scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3))
    {
        if (a1 < b1) swap(a1, b1);
        if (a2 < b2) swap(a2, b2);
        if (a3 < b3) swap(a3, b3);
        if (a2 + a3 <= a1 && (b2 <= b1 && b3 <= b1)
            || b2 + b3 <= b1 && (a2 <= a1 && a3 <= a1)
            || a2 + b3 <= a1 && (b2 <= b1 && a3 <= b1)
            || a3 + b2 <= a1 && (b3 <= b1 && a2 <= b1)
            || a2 + b3 <= b1 && (b2 <= a1 && a3 <= a1)
            || a3 + b2 <= b1 && (b3 <= a1 && a2 <= a1)
            || b2 + b3 <= a1 && (a2 <= b1 && a3 <= b1))
            cout << "YES\n";
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
