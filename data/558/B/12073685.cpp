//Language: GNU C++


#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <iomanip>
#define pii pair<int, int>
#define X first
#define Y second
#define ll long long
#define it iterator
const int maxn = 1e6 + 7;
const int oo = 1e9 + 7;
using namespace std;

    int n;
    int a[maxn], d[maxn], mx[maxn];
    bool mark[maxn];

int main()
{
    //freopen ("asdf.inp", "r", stdin);
    //freopen ("file.out", "w", stdout);
    ios_base::sync_with_stdio (0);
    cin.tie (NULL);
    cin >> n;
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[a[i]]++;
        mx[a[i]] = i;
        tmp = max (tmp, d[a[i]]);
    }

    int res = oo, l = 0, r = n+1;
    for (int i = 1; i <= n; i++)
        if (d[a[i]] == tmp && !mark[a[i]])
        {
            mark[a[i]] = 1;
            int pvt = mx[a[i]] - i + 1;
            if (pvt < res)
            {
                res = pvt;
                l = i; r = mx[a[i]];
            }
        }

    cout << l << " " << r << endl;
    return 0;
}
